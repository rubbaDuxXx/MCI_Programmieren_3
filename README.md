# MCI_Programmieren_3
Lecture material for the course "Programmieren 3" at MCI

Recordings of the lecture (in German) can be seen [here on YouTube](https://www.youtube.com/playlist?list=PLklwMV4rlxFnEd5rem6wm4Cp9xVHYySuy)

## Marpit slides framework
Slides are written in *Markdown* using the [Marpit](https://marpit.marp.app/) framework in conjunction with the [Marp for VS Code](https://marketplace.visualstudio.com/items?itemName=marp-team.marp-vscode) extension

## Installation
Clone the repositiory and open the root folder in [Visual Studio Code](https://code.visualstudio.com/). You will be prompted to install the [Marp for VS Code](https://marketplace.visualstudio.com/items?itemName=marp-team.marp-vscode) extension. If not, install the extension manually.

## Theme
The custom theme `solarized` is based on the built-in theme `gaia` and made to resemble [Beamer Solarized](https://github.com/homerours/beamer-solarized).

## Conversion using pandas
The universal document converter [Pandoc](https://pandoc.org/) is used to convert existing *org-mode* slides to *Markdown* with minimal hand-tuning required.

### Makefile
Use

```
make clean
```
to delete all generated output files **even if they have been modified**.

````
make
````
to generate *Markdown* files from *org-mode* sources.

### Header file
The required header for *Marpit* to render the markdown slides is defined in *YAML Font Matter* and is included upon conversion from `header.yaml`.

### Lua Filters

- Images\
    `fix_img_org2md.lua` redefines the image inclusion syntax to work with *Marpit*

- Title slide\
    `fix_add_author_title.lua` creates a title slide taken from latex metadata inside the source files