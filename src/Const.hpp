#ifndef CONST_HPP
#define CONST_HPP

#include <SDL2/SDL.h>
#include <thread>
#include <iostream>
#include <string>
#include <vector>

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

#endif