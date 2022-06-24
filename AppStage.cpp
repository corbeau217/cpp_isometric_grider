/**
 * @file AppStage.cpp
 * @author Corbeau (https://github.com/corbeau217)
 * @brief this is to declutter the App.cpp/App.hpp files
 * @version 0.1
 * @date 2022-06-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "AppStage.hpp"

// constructor
AppStage::AppStage() :
// initialise title
title {APPSTAGE_DEFAULT_TITLE}
{
    //TODO
    // previously we didnt wanna have these here
    //  since it's redundant code but derived classes
    //  scream and dont compile if we dont specify and
    //  define a default constructor for the base class
}
// destructor
AppStage::~AppStage(){
    //TODO
}

/**
 * @brief handles painting the frame of app stage
 * 
 */
void AppStage::paint(){
    //TODO
}