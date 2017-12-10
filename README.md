# Gahood Tetris
Gahood Tetris is a cross platform game written in C++ using C++11 and SDL2

## What is Gahood Tetris?
It's essentially tetris but built from the ground up using the C++ programming language and the SDL2 library.

## Developer Installation

### **Clone**
- First clone the repository into your desired directory
``` sh
git clone 'https://github.com/dee12452/GahoodTetris.git'
```

### **Android**

- Copy SDL2 and SDL2_image source code into jni/SDL2 and jni/SDL2_image respectively
- Navigate to the project folder 
``` sh
cd Android/GahoodTetrisProject
```
- Build the project using Android NDK
``` sh
ndk-build
```
- Install using ant
``` sh
ant debug install
```

### **Desktop**

- Navigate to the desktop make folder
``` sh
cd Desktop/make
```
- Call make
``` sh
make
```
- Then run the binary
``` sh
./game.o
```

## --Screenshots--

![Screenshot](screenshots/home_screen.png)
![Screenshot](screenshots/play_1.png)
![Screenshot](screenshots/play_2.png)
