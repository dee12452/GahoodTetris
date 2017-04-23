#ifndef CONST_HPP
#define CONST_HPP

#include <SDL.h>
#include <SDL_image.h>
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
enum GameState { START, MAIN_MENU, PLAY, EXIT, PAUSE };
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Game Vector Drawables
//Menu
const int VECTOR_MENU = 0;
const int VECTOR_MENU_MAIN = 0;
//Play
const int VECTOR_PLAY = 1;
const int VECTOR_PLAY_GRID = 0;
const int VECTOR_PLAY_PLAYER = 1;
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Game Input Handlers
//Menu
const int INPUT_MENU = 0;
//Play
const int INPUT_PLAY = 1;
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Sprite File Locations
const char * const BLOCK_YELLOW_SPRITE_FILE_LOCATION = "res/tetris_block_yellow.png";
const char * const BLOCK_GREEN_SPRITE_FILE_LOCATION = "res/tetris_block_green.png";
const char * const BLOCK_GREY_SPRITE_FILE_LOCATION = "res/tetris_block_grey.png";
const char * const BLOCK_ORANGE_SPRITE_FILE_LOCATION = "res/tetris_block_orange.png";
const char * const BLOCK_PURPLE_SPRITE_FILE_LOCATION = "res/tetris_block_purple.png";
const char * const BLOCK_RED_SPRITE_FILE_LOCATION = "res/tetris_block_red.png";
const char * const BLOCK_BLUE_SPRITE_FILE_LOCATION = "res/tetris_block_blue.png";
const char * const SPRITE_WHITE_BLOCK_FILE_LOCATION = "res/tetris_block_white.png";
const char * const BLOCK_BLANK_SPRITE_FILE_LOCATION = "res/tetris_block_empty.png";
const char * const GRID_SPRITE_FILE_LOCATION = "res/tetris_border.png";
const char * const NUMBERS_SPRITE_SHEET_FILE_LOCATION = "res/numbers.png";
const char * const SPRITE_MENU_BG_FILE_LOCATION = "res/menu_bg.png";
const char * const SPRITE_PLAY_BUTTON_FILE_LOCATION = "res/play_button.png";
const char * const SPRITE_EXIT_BUTTON_FILE_LOCATION = "res/exit_button.png";
const char * const SPRITE_SELECTOR_FILE_LOCATION = "res/selector.png";
const char * const SPRITE_NEXT_BORDER_FILE_LOCATION = "res/next_border.png";
const char * const SPRITE_A_FILE_LOCATION = "res/A.png";
const char * const SPRITE_B_FILE_LOCATION = "res/B.png";
const char * const SPRITE_C_FILE_LOCATION = "res/C.png";
const char * const SPRITE_D_FILE_LOCATION = "res/D.png";
const char * const SPRITE_E_FILE_LOCATION = "res/E.png";
const char * const SPRITE_F_FILE_LOCATION = "res/F.png";
const char * const SPRITE_G_FILE_LOCATION = "res/G.png";
const char * const SPRITE_H_FILE_LOCATION = "res/H.png";
const char * const SPRITE_I_FILE_LOCATION = "res/I.png";
const char * const SPRITE_J_FILE_LOCATION = "res/J.png";
const char * const SPRITE_K_FILE_LOCATION = "res/K.png";
const char * const SPRITE_L_FILE_LOCATION = "res/L.png";
const char * const SPRITE_M_FILE_LOCATION = "res/M.png";
const char * const SPRITE_N_FILE_LOCATION = "res/N.png";
const char * const SPRITE_O_FILE_LOCATION = "res/O.png";
const char * const SPRITE_P_FILE_LOCATION = "res/P.png";
const char * const SPRITE_Q_FILE_LOCATION = "res/Q.png";
const char * const SPRITE_R_FILE_LOCATION = "res/R.png";
const char * const SPRITE_S_FILE_LOCATION = "res/S.png";
const char * const SPRITE_T_FILE_LOCATION = "res/T.png";
const char * const SPRITE_U_FILE_LOCATION = "res/U.png";
const char * const SPRITE_V_FILE_LOCATION = "res/V.png";
const char * const SPRITE_W_FILE_LOCATION = "res/W.png";
const char * const SPRITE_X_FILE_LOCATION = "res/X.png";
const char * const SPRITE_Y_FILE_LOCATION = "res/Y.png";
const char * const SPRITE_Z_FILE_LOCATION = "res/Z.png";
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Animation File Locations
const char * const ANIMATION_MAIN_MENU = "animations/MainMenuAnimation.txt";
const char * const ANIMATION_CLEAR_ROW = "animations/ClearRowAnimation.txt";
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//CPU Usage Delay
//Set higher for less CPU usage

//Delays the game loop thread, not the window thread
const int CPU_USAGE_LOGIC_DELAY = 20;

//Delays the window thread, not the game loop thread
const int CPU_USAGE_EVENT_DELAY = 20;

//Delays the animation thread, not the game loop thread
const int CPU_USAGE_ANIMATION_DELAY = 5;
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
const int STARTING_BOARD_DELAY_TIME = 1000;
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Window Size
const int DESIRED_WINDOW_WIDTH = 500;
const int DESIRED_WINDOW_HEIGHT = 500;
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Location of Player information on screen
const int PLAYER_SCORE_X = 0;
const int PLAYER_SCORE_Y = 10;
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Grid Dimensions
const int GRID_ROWS = 10;
const int GRID_COLUMNS = 20;
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Block Dimensions
const int BLOCK_WIDTH = (DESIRED_WINDOW_HEIGHT / 2) / GRID_ROWS;
const int BLOCK_HEIGHT = DESIRED_WINDOW_HEIGHT / GRID_COLUMNS;
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

////////////////////////////////////////////////////////////////////
//Tetris Piece Starting Place Timer
const int TETRIS_PIECE_DEFAULT_TIMER = 2000;
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//Tetris Grid Points and Level Constants
//
//The number of points to get to the next level
const int TARGET_POINTS_FACTOR = 100;
//The factor by which the update time is reduced (updateTime -= (currentLevel * factor))
const int UPDATE_TIME_FACTOR = 10;
//The minimum possible update time
const int UPDATE_TIME_MINIMUM = 50;
////////////////////////////////////////////////////////////////////

#endif
