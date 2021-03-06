/**
 * @file AppStageIso.cpp
 * @author Corbeau (https://github.com/corbeau217)
 * @brief to declutter the AppStage file and make our own
 * @version 0.1
 * @date 2022-06-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// include our header
#include "AppStageIso.hpp"

// define the current class preprocessor variable
#define __CLASSNAME__ AppStageIso

// constructor
__CLASSNAME__::__CLASSNAME__(Vector2 dimensions_in) : 
// initialise cell size
cellSize {APPSTAGE_DEFAULT_CELLSIZE}
{
    // initialise dimensions
    dimensions = {dimensions_in};
    // calculate the grid dimensions
    Vector2 gridDimensions = {dimensions.x, dimensions.y};
    // get our offsets
    float xOffset = {0.0f};
    float yOffset = {0.0f};
    // add in the offset amounts
    if(APPSTAGEISO_OFFSET_GRID_BOOL){
        xOffset += dimensions.x/2.0f;
        yOffset += dimensions.y/2.0f;
    }
    // initialise location of grid
    gridLoc = {Vector2{0.0f + xOffset, 0.0f + yOffset}};
    
    // setup grid
    grid = make_unique<IsoGrid>(gridLoc, gridDimensions, cellSize, APPSTAGE_DEFAULT_PAINTCELLOUTLINE);
}

// destructor
__CLASSNAME__::~__CLASSNAME__(){
    //TODO
}


// paint member function
void __CLASSNAME__::paint(){
    // hand off to grid
    grid->paint();
}


// undefine the current class preprocessor variable
#undef __CLASSNAME__