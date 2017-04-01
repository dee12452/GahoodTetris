#ifndef CONST_HPP
#define CONST_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <thread>
#include <iostream>
#include <string>
#include <vector>

////////////////////////////////////////////////////////////////////
//Game Name
const char * const GAME_NAME = "Gahood Tetris Test";
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Game states for the game
enum GameState { PLAY, EXIT };
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Sprite File Locations
const char * const BLOCK_YELLOW_SPRITE = "../res/tetris_block_yellow.png";
const char * const BLOCK_GREEN_SPRITE = "../res/tetris_block_green.png";
const char * const BLOCK_GREY_SPRITE = "../res/tetris_block_grey.png";
const char * const BLOCK_ORANGE_SPRITE = "../res/tetris_block_orange.png";
const char * const BLOCK_PURPLE_SPRITE = "../res/tetris_block_purple.png";
const char * const BLOCK_RED_SPRITE = "../res/tetris_block_red.png";
const char * const BLOCK_BLUE_SPRITE = "../res/tetris_block_blue.png";
const char * const BLOCK_BLANK_SPRITE = "../res/tetris_block_empty.png";
const char * const GRID_SPRITE = "../res/tetris_border.png";
const char * const NUMBERS_SPRITE_SHEET = "../res/numbers.png";
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//CPU Usage Delay
//Set higher for less CPU usage

//Delays the game loop thread, not the window thread
const int CPU_USAGE_LOGIC_DELAY = 20;

//Delays the window thread, not the game loop thread
const int CPU_USAGE_EVENT_DELAY = 20;
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Keys to be detected for handling input
const SDL_Scancode DEFAULT_SCAN_KEYS[] = { SDL_SCANCODE_LEFT, 
											SDL_SCANCODE_RIGHT, 
											SDL_SCANCODE_UP, 
											SDL_SCANCODE_DOWN, 
											SDL_SCANCODE_RETURN,
											SDL_SCANCODE_ESCAPE };
//The length of the above array
const int DEFAULT_SCAN_KEYS_SIZE = 6;
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Timer Constants
//
//Default FPS
const int DEFAULT_FPS = 30;
//
//Starting Board Update Timer
const int STARTING_BOARD_DELAY_TIME = 2000;
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Window Size
const int DESIRED_WINDOW_WIDTH = 500;
const int DESIRED_WINDOW_HEIGHT = 500;
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Location of Player information on screen
const int PLAYER_SCORE_X = 0;
const int PLAYER_SCORE_Y = 0;
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Grid Dimensions
const int GRID_ROWS = 10;
const int GRID_COLUMNS = 20;
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Direction enum
//Left = Counterclockwise, Right = Clockwise
enum Direction { UP, DOWN, LEFT, RIGHT };

////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Tetris Starting Pieces
const int NUMBER_OF_PIECE_TYPES = 5;
enum PieceTypes{ T, S, Z, I, O, J, L };

/* ///////////////////////////////////////
const Uint8 TETRIS_PIECE_TYPES[][3][3] = {
	{
		{ 0, 1, 0 },
		{ 1, 1, 1 },
		{ 0, 0, 0 }
	},
	{
		{ 0, 0, 0 },
		{ 1, 1, 1 },
		{ 0, 0, 0 }
	},
	{
		{ 1, 1, 0 },
		{ 1, 1, 0 },
		{ 0, 0, 0 }
	},
	{
		{ 0, 1, 0 },
		{ 0, 1, 0 },
		{ 0, 1, 0 }
	},
	{
		{ 1, 1, 0 },
		{ 0, 1, 1 },
		{ 0, 0, 0 }
	},
	{
		{ 0, 1, 1 },
		{ 1, 1, 0 },
		{ 0, 0, 0 }
	},
};
*/ ///////////////////////////////////////
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Values for colorization
const Uint8 FULL_RGB_VALUE = 255;
const Uint8 NO_RGB_VALUE = 0;
const Uint8 FULL_ALPHA_VALUE = 255;
const Uint8 NO_ALPHA_VALUE = 0;
const int RGB_VARIANTS = 3;
enum RGB_VALUES { RED, GREEN, BLUE, NONE };
////////////////////////////////////////////////////////////////////

#endif
