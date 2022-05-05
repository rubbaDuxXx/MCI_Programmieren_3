#include "mcigraph.hpp"
#include <time.h>
#include <string>
#include <vector>

using namespace std;

typedef struct Figure{
    int x, y;
    string img;
} Figure;

void draw_figure(Figure *f){
    draw_image(f->img, f->x * 16, f->y * 16);
}

void move_left(Figure *f){
    f->x--;
    if (f->x < 0)
        f->x++;
}

void move_right(Figure *f){
    f->x++;
    if (f->x > 63)
        f->x--;
}

void move_up(Figure *f){
    f->y--;
    if (f->y < 0)
        f->y++;
}

void move_down(Figure *f){
    f->y++;
    if (f->y > 47)
        f->y--;
}

void draw_grass(){
    for (int x = 0; x < 64; x++){
        for (int y = 0; y < 48; y++){
            draw_image("tiles\\3_16.bmp", x * 16, y * 16);
        }
    }
}

void check_movement(int leftkey, int rightkey, int upkey, int downkey, Figure *f1){
    if (is_pressed(leftkey)) move_left(f1);
    if (is_pressed(rightkey)) move_right(f1);
    if (is_pressed(upkey)) move_up(f1);
    if (is_pressed(downkey)) move_down(f1);
}

//check if two Figures collided
bool check_collision(Figure c, Figure other){
    return (c.x == other.x && c.y == other.y);
}

Figure randfigure(string img){
    Figure f;
    f.x = rand() % 64;
    f.y = rand() % 48;
    f.img = img;
    return f;
}

int main(int argc, char *argv[])
{
    srand(time(0));
    set_delay(25);
    Figure c = {32, 24, "tiles\\char1.bmp"};
    vector<Figure> monsters;
    vector<Figure> chests;

    //set to true if the game should end
    bool gameover = false;

    //place 10 random chests
    for(int i = 0; i < 10; i++)
        chests.push_back(randfigure("tiles\\50_19.bmp"));

    while (running() && !gameover){
        draw_grass();

        check_movement(KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, &c);

        if (rand() % 8 == 0)
            monsters.push_back(randfigure("tiles\\monster.bmp"));

        for(auto &monster : monsters){
            int direction = rand() % 4;

            switch(direction){
                case 0:
                    move_up(&monster);
                    break;
                case 1:
                    move_down(&monster);
                    break;
                case 2:
                    move_left(&monster);
                    break;
                case 3:
                    move_right(&monster);
                    break;
            }
        }

        for (int i = 0; i < monsters.size(); i++)
            if (rand() % 100 == 0)
                monsters.erase(monsters.begin() + i);

        //check if the player collides with a monster
        for(auto monster : monsters){
            if(check_collision(c, monster)){
                cout << "GAME OVER!" << endl;
                gameover = true;
            }
        }

        //check if the player collides with a chest
        for(auto &chest : chests){
            if(check_collision(c, chest))
                chest.img = "tiles\\43_10.bmp";
        }

        for(auto monster : monsters)
            draw_figure(&monster);

        for(auto chest : chests)
            draw_figure(&chest);

        draw_figure(&c);

        present();
    }
    return 0;
}

//3_16.bmp --> grass
//3_7.bmp --> flower
//6_0.bmp --> soil
//9_4.bmp --> wall
//50_19 --> chest
//43_10 --> gold
//char1.bmp --> character
//monster.bmp --> monster