/**
 * @file IsoGrid.cpp
 * @author Corbeau (https://github.com/corbeau217)
 * @brief for generating/handling the grid
 * @version 0.1
 * @date 2022-06-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// include our header
#include "IsoGrid.hpp"

// define the current class preprocessor variable
#define __CLASSNAME__ IsoGrid

// constructor
__CLASSNAME__::__CLASSNAME__(Vector2 loc_in, Vector2 dimensions_in, float cellSize_in, bool paintCellOutline_in) :
// store our ui position
gridLoc {loc_in},
// stor our ui dimensions
dimensions {dimensions_in},
// setup our cell size
cellSize {cellSize_in}
{
    // we should calculate the size here
    int cols_calculated = possibleCols(dimensions, cellSize);
    int rows_calculated = possibleRows(dimensions, cellSize);
    // then we have our cols/rows vars that we work with
    cols = {cols_calculated};
    rows = {rows_calculated};
    // setup our cell array
    cells = new IsoCell**[cols];
    // loop through each column and add the rows
    for(int x = 0; x < cols; x++){
        // add the rows to our pointers
        cells[x] = new IsoCell*[rows];
        // loop through the row and set up each pointer
        for(int y = 0; y < rows; y++){
            // get the ui position
            Vector2 currCellPos = generateCellLocationByIndex(x,y);
            // setup up the pointer
            cells[x][y] = new IsoCell(currCellPos, x, y, cellSize, paintCellOutline_in);
        }
    }
    cout << "Done building IsoGrid constructor" << endl;
}

// destructor
__CLASSNAME__::~__CLASSNAME__(){
    //TODO
}


// for converting cell indicies to placement
Vector2 __CLASSNAME__::generateCellLocationByIndex(int xIdx, int yIdx){
    // this offset vector is calculated based off the grid location
    //      and top of ui dimensions
    Vector2 offset = {
            gridLoc.x,
            gridLoc.y-possibleRows(dimensions,cellSize)*cellSize/4
        };
    
    // this borrows from:
    //      https://www.youtube.com/watch?v=04oQ2jOUjkU
    float xLoc = xIdx*( 0.5f*cellSize) + yIdx*(-0.5f*cellSize);
    float yLoc = xIdx*(0.25f*cellSize) + yIdx*(0.25f*cellSize);

    // return adding our offset vector
    return Vector2{xLoc + offset.x, yLoc + offset.y};
}


// paint grid member function
void __CLASSNAME__::paint(){
    for(int x = 0; x < cols; x++)
        for(int y = 0; y < rows; y++)
            cells[x][y]->paint();
}


// cell get by index
IsoCell *__CLASSNAME__::get(int xIdx, int yIdx){
    return cells[xIdx][yIdx];
}

// cell get by ui position
IsoCell *__CLASSNAME__::get(Vector2 pos){
    //TODO
    return nullptr;
}

// check if this location is valid by index
bool __CLASSNAME__::validLocation(int xIdx, int yIdx){
    return (xIdx > 0 && yIdx > 0) &&
           (xIdx < cols && yIdx < rows);
}

Vector2 __CLASSNAME__::topLeftV(){
    return Vector2{
            gridLoc.x-(dimensions.x/2.0f),
            gridLoc.y-(dimensions.y/2.0f)
        };
}


// static member functions

int __CLASSNAME__::possibleCols(Vector2 uiDimensions_in, float cellSize_in){
    // should we calculate
    if(!ISOGRID_CALCULATE_COLSANDROWS)
        return ISOGRID_DEFAULT_COLS;
    // otherwise calculate it
    // float yLoc = xIdx*(0.25f*cellSize) + yIdx*(0.25f*cellSize);
    // nah something to do with the square root of 2?
    // one side 1, another side 0.5
    // so sqrt(1*1 + 0.5*0.5)
    // sqrt 1.25??
    return uiDimensions_in.x/cellSize_in;
}

int __CLASSNAME__::possibleRows(Vector2 uiDimensions_in, float cellSize_in){
    // should we calculate
    if(!ISOGRID_CALCULATE_COLSANDROWS)
        return ISOGRID_DEFAULT_ROWS;
    // otherwise calculate it
    return uiDimensions_in.x/cellSize_in;
}


// undefine the current class preprocessor variable
#undef __CLASSNAME__