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

// constructor
IsoGrid::IsoGrid(Vector2 loc_in, int cols_in, int rows_in, float cellSize_in, Vector2 dimensions_in, bool paintCellOutline_in) :
// store our ui position
gridLoc {loc_in},
// store our dimensions
cols {cols_in}, rows {rows_in},
// setup our cell size
cellSize {cellSize_in}
{
    // setup our cell array
    cells = new IsoCell**[cols];
    // loop through each column and add the rows
    for(int x = 0; x < cols; x++){
        // add the rows to our pointers
        cells[x] = new IsoCell*[rows];
        // loop through the row and set up each pointer
        for(int y = 0; y < rows; y++){
            // get the ui position
            Vector2 currCellPos = cellLocationByIndex(x,y);
            // setup up the pointer
            cells[x][y] = new IsoCell(currCellPos, x, y, cellSize, paintCellOutline_in);
        }
    }
    cout << "Done building IsoGrid constructor" << endl;
}

// destructor
IsoGrid::~IsoGrid(){
    //TODO
}


// for converting cell indicies to placement
Vector2 IsoGrid::cellLocationByIndex(int xIdx, int yIdx){
    // this offset vector is calculated based off the grid location
    Vector2 offset = {gridLoc.x, gridLoc.y};
    
    // this borrows from:
    //      https://www.youtube.com/watch?v=04oQ2jOUjkU
    float xLoc = xIdx*( 0.5f*cellSize) + yIdx*(-0.5f*cellSize);
    float yLoc = xIdx*(0.25f*cellSize) + yIdx*(0.25f*cellSize);

    // return adding our offset vector
    return Vector2{xLoc + offset.x, yLoc + offset.y};
}


// paint member function
void IsoGrid::paint(){
    for(int x = 0; x < cols; x++)
        for(int y = 0; y < rows; y++)
            cells[x][y]->paint();
}


// cell get by index
IsoCell *IsoGrid::get(int xIdx, int yIdx){
    //TODO
    return nullptr;
}

// cell get by ui position
IsoCell *IsoGrid::get(Vector2 pos){
    //TODO
    return nullptr;
}