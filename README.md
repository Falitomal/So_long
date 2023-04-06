# So_long

![so long 42_preview](/readme/so_long_preview.png)

This is a small game project from 42school implemented using MLX42 ( a version customized of MiniLibX).

## Goals
This project is a very small 2D game. It is built to make you work with textures, sprites. And some very basic gameplay elements.
One part of most difficult goal of this project is to implement the flood fill algorithm,
 to find a valid path taking into account the special characters and the exit.
Initiating the reading of a file full of characters using funtions from our own library, we load the file and apply to each character,
a parsed imagen(texture) using funtions from the MLX42 library.

## Getting Started
```
🚨 Please check that you have glfw installed in your machine. 
$ You can instal in Macos with brew install glfw
```
### Install and making
```bash
$ make
```

### Usage
```bash
$ ./so_long [MAP_FILE.ber]
```
Only map files with extension `.ber` are available. Map file examples are available in the `maps/` directory.

```bash
$ ./so_long maps/map.ber
```
Run the code to use all the features of the game.

### Parser and checks
The program must not have errors in differents input parameters:
- The numbers of characters in all rows must be the same.
- Only characters allowd are " 0, 1, C, P, E ".
- Must have a single player, and only one exit, and minimum one collectible.
- The egdes of the maps must be closed, have walls.
- The program checks the arguments, and the extension if finish in ".ber".
- The wrong characters in input or wrong characters does not segmentation failure.

## Validation path
One of the most complicated part of this proyect, is to apply a an algorithm to validate than the map and the game is possible to complete.
For this part of program, apply an algorithm called "flood fill", which applied to a copy of the map evaluate that it is possible, to collect the objects and after them to reach the good exit from the game.


### HOW TO PLAY
The player’s goal is to collect all collectibles present on the map then escape with minimal movement.
The main player is the similar logo to the school of 42, who must eat "camperos" (typical hamburgers from Málaga) and reach the blackhole, in a forest style map.

|KEYBOARD|ACTION|
|---|---|
|`W`, `↑`|Move up|
|`S`, `↓`|Move down|
|`A`, `←`|Move left|
|`D`, `→`|Move right|
|`ESC ⎋`| Key "Q"|

## Reference
 * [42Paris/minilibx-linux](https://github.com/42Paris/minilibx-linux)
 * [42Docs/minilibx](https://harm-smits.github.io/42docs/libs/minilibx)
 * [42Docs/MLX42 Codam](https://github.com/codam-coding-college/MLX42)
 * [Wiki Flood Fill](https://en.wikipedia.org/wiki/Flood_fill)
 * [Guide Flood Fill](https://www.freecodecamp.org/news/flood-fill-algorithm-explained/)
 * [Web to create sprites](https://www.piskelapp.com/)

