CC = g++
FILES = ../src/Main.cpp ../src/game/TetrisPiece.cpp ../src/game/Game.cpp ../src/game/Window.cpp ../src/animation/BaseAnimation.cpp ../src/animation/AnimatorHelper.cpp ../src/animation/MoveAnimation.cpp ../src/util/Util.cpp ../src/util/DisplayUtil.cpp ../src/util/Timer.cpp ../src/sprite/Sprite.cpp ../src/sprite/SpriteUtil.cpp ../src/input/MenuInputHandler.cpp ../src/input/BaseInputHandler.cpp ../src/input/PlayInputHandler.cpp ../src/drawable/MainMenu.cpp ../src/drawable/Player.cpp ../src/drawable/TetrisGrid.cpp ../src/drawable/BaseDrawable.cpp ../src/animation/RowCompleteAnimation.cpp ../src/input/HowToPlayInputHandler.cpp
FLAGS = -std=c++11 -lSDL2 -lSDL2_image -lpthread -g
OUT = GahoodTetris
game:
	$(CC) $(FILES) -o $(OUT) $(FLAGS)
