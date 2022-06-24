/**
 * @file IsoCell.cpp
 * @author Corbeau (https://github.com/corbeau217)
 * @brief handles the individual cells
 * @version 0.1
 * @date 2022-06-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// include our header
#include "IsoCell.hpp"


// constructor
IsoCell::IsoCell(Vector2 loc_in, int col_in, int row_in, float size_in, bool drawOutline_in) : 
// setup our ui placement
uiLoc {loc_in},
// setup location indicies
col {col_in}, row {row_in},
// setup cell size
cellSize {size_in},
// default color
cellColor {ISOCELL_DEFAULT_FILLCOLOR},
// say if we draw outline
drawOutline {drawOutline_in}
{
    //TODO
}

// destructor
IsoCell::~IsoCell(){
    //TODO
}


// paint member function
void IsoCell::paint(){
    //TODO
    if(ISOCELL_DRAWASBOXES)
        DrawRectangleV(uiLoc, Vector2(cellSize,cellSize), BLUE);
    // this needs to be fixed
    if(ISOCELL_DRAWWITHLINES){
        // parts
        float halfSize = {cellSize/2.0f};
        float quarSize = {cellSize/4.0f};
        // point count 
        int pointCount = 4;
        // initialise points array
        Vector2 *points = new Vector2[pointCount];
        // set our points
        points[0] = {Vector2(uiLoc.x           , uiLoc.y           )};
        points[1] = {Vector2(uiLoc.x + halfSize, uiLoc.y + quarSize)};
        points[2] = {Vector2(uiLoc.x           , uiLoc.y + halfSize)};
        points[3] = {Vector2(uiLoc.x - halfSize, uiLoc.y + quarSize)};
        // draw them
        DrawLineStrip(points, pointCount, BLACK);
    }
}


// location getter
Vector2 IsoCell::getLoc(){
    //TODO
    return Vector2(0.0f, 0.0f);
}

// if a location is contained in this cell
bool IsoCell::contains(Vector2 loc_in){
    //TODO
    return false;
}