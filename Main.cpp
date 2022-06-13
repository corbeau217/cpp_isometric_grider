// raylib includes
#include "raylib.h"
// project includes

// c/c++ includes
#include <string>  // for strings
#include <iostream>  // for cout/endl

using namespace std;

// definitions
#define FRAMERATE 15

// vars for our program
int appWidth;
int appHeight;

int getWidth(){
    return appWidth;
}
int getHeight(){
    return appHeight;
}

void setupApp(){
    cout << "--> Setting up app" << endl;

    // set our variables
    appWidth = 1024;
    appHeight = 720;
    string appTitle  = "Isometric C++ grid";

    // raylib setup
    InitWindow( getWidth(), getHeight(), appTitle.c_str());
    SetTargetFPS( FRAMERATE );
}

void framePaint(){
    ClearBackground(GRAY);
    // grid->paint();
}

void cleanupApp(){
    cout << "Cleaning up app" << endl;
    // Lib::closingApp();
    //TODO
    cout << "[nothing to report in cleanup lel]" << endl
            << "[slap a TODO here]"                 << endl;
}

void drawLoop(){
    cout << "--> Starting Main::drawLoop()" << endl;
    // handles the draw loop
    while( !WindowShouldClose() ){
        BeginDrawing();
        framePaint();
        EndDrawing();
    }
    cleanupApp();
}

/**
 * @brief main landing point for our program
 * 
 */
int main(){
    cout << "--> Executing Main::main()" << endl;
    setupApp();
    drawLoop();
    cleanupApp();
    return 0;
}