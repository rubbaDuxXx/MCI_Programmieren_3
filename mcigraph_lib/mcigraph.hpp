#ifndef MCIGRAPH_H
#define MCIGRAPH_H

// Warning: Putting everything in the header file is not good style.
// This is done here for ease of use for educational purposes only!!

#include <SDL.h>
#include <cstdint> // For fixed width integer types
#include <iostream>

#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

namespace mcigraph {

// Structure used to report MCIGraph exceptions
struct MciGraphException {
  std::string message;
  MciGraphException(std::string m) {
    std::cout << "MciGraphException: " << m << std::endl;
    message = m;
  }
};

// The class TextureLoadCache allows to load images from files and
// returns a texture for the given file name. More importantly, it
// caches already loaded images. Warning: The cache does not delete
// already loaded textures when memory runs out etc. (which should not
// happen for our use case)
class TextureLoadCache {
private:
  // The map saving already used image names and their associated
  // textures
  std::unordered_map<std::string, SDL_Texture *> _cache;
  // Renderer used to create texture from image
  SDL_Renderer *_ren;

public:
  // Constructors
  TextureLoadCache() : _ren{NULL} {};
  TextureLoadCache(SDL_Renderer *ren) : _ren{ren} {};

  // Destructor
  ~TextureLoadCache() {
    for (auto i : _cache) {
      SDL_DestroyTexture(i.second);
    }
  }

  SDL_Texture *load(std::string filename) {
    // If the file is not in cache: Load, make texture, save to cache and return
    if (_cache.count(filename) == 0) {
      SDL_Surface *bmp = SDL_LoadBMP(filename.c_str());
      // If loading fails (usually because of using a wrong file name,
      // throw an exception naming the used base path where images
      // should be put)
      if (bmp == NULL) {
        throw MciGraphException(
            "Could not load image: " + std::string(SDL_GetError()) +
            " Please put your images in the directory: " +
            std::string(SDL_GetBasePath()));
      }
      // Set magenta pixels of the image as transparent
      auto magenta = SDL_MapRGB(bmp->format, 0xFF, 0x00, 0xFF);
      SDL_SetColorKey(bmp, SDL_TRUE, magenta);
      // Create texture from loaded image
      SDL_Texture *tex = SDL_CreateTextureFromSurface(_ren, bmp);
      SDL_FreeSurface(bmp);
      if (tex == NULL) {
        throw MciGraphException("Could not create texture: " +
                                std::string(SDL_GetError()));
      }
      // Cache the texture
      _cache[filename] = tex;
    }
    return _cache[filename];
  }
};

// Struct used to represent color values
struct Color {
  uint8_t red, green, blue;
};

class MciGraph {
private:
  std::thread _event_loop_thread;
  TextureLoadCache _texcache;
  Color _background;
  std::vector<bool> _keystate;

public:
  bool running;
  SDL_Window *win;
  SDL_Renderer *ren;
  int delay;

private:
  // Constructor is private to prevent people from creating an
  // instance of MciGraph directly. Access should be done by using
  // get_instance following the singleton pattern. This will return a
  // single instance of MCIGraph that is consistent for the whole
  // program.
  MciGraph() {
    // Init some variables
    _background = {0xEF, 0xEF, 0xEF};
    running = true;
    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
      throw MciGraphException("Could not init SDL: " +
                              std::string(SDL_GetError()));
    }

    // Get the window
    win = SDL_CreateWindow("MCI Graph", SDL_WINDOWPOS_CENTERED,
                           SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_SHOWN);
    if (win == NULL) {
      SDL_Quit();
      throw MciGraphException("Could not create Window" +
                              std::string(SDL_GetError()));
    }

    // Init the renderer
    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC);

    if (ren == NULL) {
      SDL_DestroyWindow(win);
      std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
      SDL_Quit();
      throw MciGraphException("Could not create renderer");
    }
    // Init Texture Cache
    _texcache = TextureLoadCache(ren);
    // Init keystates
    _keystate = std::vector<bool>(284); // 284 is the highest key scancode

    delay = 17;
  }

public:
  /// Clears the screen
  void clear() {
    if (SDL_RenderClear(ren) < 0)
      throw MciGraphException(SDL_GetError());
    if (SDL_SetRenderDrawColor(ren, _background.red, _background.green,
                               _background.blue, 0xFF) < 0)
      throw MciGraphException(SDL_GetError());
    if (SDL_RenderFillRect(ren, NULL) < 0)
      throw MciGraphException(SDL_GetError());
  }

  /// Present the screen to user and do some message handling
  void present() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
      switch (e.type) {
      case SDL_QUIT: {
        running = false;
        break;
      }
      case SDL_KEYDOWN: { // On keydown set keystate to true
        auto ev = reinterpret_cast<SDL_KeyboardEvent *>(&e);
        _keystate.at(ev->keysym.scancode) = true;
        break;
      }
      case SDL_KEYUP: { // On keyup set keystate to false
        auto ev = reinterpret_cast<SDL_KeyboardEvent *>(&e);
        _keystate.at(ev->keysym.scancode) = false;
        break;
      }
      default:
        break;
      }
    }
    SDL_RenderPresent(ren); // Show drawn frame
    clear();                // Clear screen after picture is shown
    SDL_Delay(delay);       // Wait for a little bit
    SDL_PumpEvents();       // Update events
  }

  /// Check if given key is currently pressed
  bool is_pressed(const Uint8 key) {
    SDL_PumpEvents(); // Update Keymap
    auto keymap = SDL_GetKeyboardState(NULL);
    if (keymap == NULL)
      throw MciGraphException(SDL_GetError());
    return keymap[key];
  }

  /// Check if given key was pressed since last checking
  bool was_pressed(const Uint8 key) {
    if (_keystate.at(key) == true) {
      _keystate.at(key) = false;
      return true;
    }
    return false;
  }

  /// Draw a rectangle
  void draw_rect(int x, int y, int width, int height, bool outline = false,
                 int red = 0x00, int green = 0x00, int blue = 0x00) {
    SDL_Rect rect = {x, y, width, height};
    SDL_SetRenderDrawColor(ren, red, green, blue, SDL_ALPHA_OPAQUE);
    if (outline) {
      SDL_RenderDrawRect(ren, &rect);
    } else {
      SDL_RenderFillRect(ren, &rect);
    }
  }

  /// Draw a line
  void draw_line(int x1, int y1, int x2, int y2, int red = 0x00,
                 int green = 0x00, int blue = 0x00) {
    if (SDL_SetRenderDrawColor(ren, red, green, blue, SDL_ALPHA_OPAQUE) < 0)
      throw MciGraphException(SDL_GetError());
    if (SDL_RenderDrawLine(ren, x1, y1, x2, y2) < 0)
      throw MciGraphException(SDL_GetError());
  }

  /// Draw a point
  void draw_point(int x, int y, int red = 0x00, int green = 0x00,
                  int blue = 0x00) {
    SDL_SetRenderDrawColor(ren, red, green, blue, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawPoint(ren, x, y);
  }

  /// Draw an image (given as a file on disc) at position x,y. The
  /// loading of the images is cached.
  void draw_image(std::string filename, int x = 0, int y = 0) {
    auto tex = _texcache.load(filename);
    int w, h;
    SDL_QueryTexture(tex, NULL, NULL, &w, &h);
    SDL_Rect dest_rect = {x, y, w, h};
    SDL_RenderCopy(ren, tex, NULL, &dest_rect);
  }

  ~MciGraph() {
    SDL_DestroyRenderer(ren);
    SDL_DestroyWindow(win);
    SDL_Quit();
  }

  // Use the singleton pattern to get one globally consistent MCIGraph instance
  // from all points in the program
  static MciGraph &get_instance() {
    static MciGraph mcigraph;
    return mcigraph;
  }

private:
  // Prevent copying and assigning of MciGraph
  MciGraph(const MciGraph &);
  MciGraph &operator=(const MciGraph &);
};

} // namespace mcigraph

// Some fishy stuff is going on after here. This is only done to
// make teaching of an introductory course in C++ easier and should not be taken
// as a good example of how to do things

const auto KEY_LEFT = SDL_SCANCODE_LEFT;
const auto KEY_RIGHT = SDL_SCANCODE_RIGHT;
const auto KEY_UP = SDL_SCANCODE_UP;
const auto KEY_DOWN = SDL_SCANCODE_DOWN;

const auto KEY_1 = SDL_SCANCODE_1;
const auto KEY_2 = SDL_SCANCODE_2;
const auto KEY_3 = SDL_SCANCODE_3;
const auto KEY_4 = SDL_SCANCODE_4;
const auto KEY_5 = SDL_SCANCODE_5;
const auto KEY_6 = SDL_SCANCODE_6;
const auto KEY_7 = SDL_SCANCODE_7;
const auto KEY_8 = SDL_SCANCODE_8;
const auto KEY_9 = SDL_SCANCODE_9;
const auto KEY_0 = SDL_SCANCODE_0;

const auto KEY_W = SDL_SCANCODE_W;
const auto KEY_A = SDL_SCANCODE_A;
const auto KEY_S = SDL_SCANCODE_S;
const auto KEY_D = SDL_SCANCODE_D;

const auto KEY_SPACE = SDL_SCANCODE_SPACE;

#define ___MCILOOPSTART___ while (mcigraph::MciGraph::get_instance().running) {

#define ___MCILOOPEND___                                                       \
  mcigraph::MciGraph::get_instance().present();                                \
  }

// All the following "easy-access-functions" are defined to be inline
// to circumvent the one-definition rule for functions. Otherwise this
// would lead to compile errors when using this library in more than
// one file

inline bool is_pressed(const Uint8 key) {
  return mcigraph::MciGraph::get_instance().is_pressed(key);
}
inline bool was_pressed(const Uint8 key) {
  return mcigraph::MciGraph::get_instance().was_pressed(key);
}
inline void draw_rect(int x, int y, int width, int height, bool outline = false,
               int red = 0x00, int green = 0x00, int blue = 0x00) {
  mcigraph::MciGraph::get_instance().draw_rect(x, y, width, height, outline,
                                               red, green, blue);
}
inline void draw_line(int x1, int y1, int x2, int y2, int red = 0x00, int green = 0x00,
               int blue = 0x00) {
  mcigraph::MciGraph::get_instance().draw_line(x1, y1, x2, y2, red, green,
                                               blue);
}
inline void draw_point(int x, int y, int red = 0x00, int green = 0x00,
                int blue = 0x00) {
  mcigraph::MciGraph::get_instance().draw_point(x, y, red, green, blue);
}
inline void draw_image(std::string filename, int x = 0, int y = 0) {
  mcigraph::MciGraph::get_instance().draw_image(filename, x, y);
}

inline void set_delay(int delay) { mcigraph::MciGraph::get_instance().delay = delay; }

inline int running() { return mcigraph::MciGraph::get_instance().running; }
inline void present() { mcigraph::MciGraph::get_instance().present(); }

#endif /* MCIGRAPH_H */

// Compile (Linux and MacOS):
// g++ -std=c++11 -lpthread test.cpp `sdl2-config --cflags --libs`
