/**
 * @file AppStage.hpp
 * @author Corbeau (https://github.com/corbeau217)
 * @brief this is to declutter the App.cpp/App.hpp files
 * @version 0.1
 * @date 2022-06-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// header guard to prevent redefining
#pragma once

#include <iostream>  // for cout/endl/unique_ptr/make_unique
#include <string>  // so we can use strings
#include "raylib.h"  // since we need this to paint
// we need this so the unique_ptr and
//      make_unique work on windows
#include <memory>

#define APPSTAGE_DEFAULT_TITLE "App"
#define APPSTAGE_DEFAULT_MARGIN 10
#define APPSTAGE_DEFAULT_CELLSIZE 20.0f
#define APPSTAGE_DEFAULT_PAINTCELLOUTLINE false

using namespace std;

class AppStage{
    public:
    // dimensions
    Vector2 dimensions;
    // title var
    string title;
    
    // constructor
    AppStage();
    // destructor
    virtual ~AppStage();


    /**
     * @brief handles painting the frame of app stage
     * 
     */
    virtual void paint()=0;

    /**
     * @brief Get the desired title from our AppStage instance
     * 
     * (this should be set during constructors)
     * 
     */
    string getDesiredTitle(){
        return title;
    }
};

