/**
 * @file Main.cpp
 * @author Corbeau (https://github.com/corbeau217)
 * @brief 
 * @version 0.1
 * @date 2022-06-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// raylib includes
#include "raylib.h"
// project includes
#include "App.hpp"
// c/c++ includes
#include <string>  // for strings
#include <iostream>  // for cout/endl

using namespace std;


/**
 * @brief main landing point for our program
 * 
 */
int main(){
    cout << "--> Executing Main::main()" << endl;
    
    // start our app
    App::start();

    return 0;
}