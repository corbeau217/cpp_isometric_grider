/**
 * @file IsoGrid.hpp
 * @author Corbeau (https://github.com/corbeau217)
 * @brief for generating/handling the grid
 * @version 0.1
 * @date 2022-06-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
//header guard
#pragma once

// standard library includes
#include <iostream> // for cout/endl
// #include <memory> // for unique_ptr/make_unique
// raylib includes
#include "raylib.h"
// project includes
#include "IsoCell.hpp"

// saves typing std::
using namespace std;

// post/pre processor stuff here

/**
 * @brief isometric grid class that handles the grid?
 * 
 * drawn from the centre using gridLoc as the centre
 * 
 */
class IsoGrid {
    public:
    // draw from location
    Vector2 gridLoc;

    // counts
    int cols;
    int rows;

    // cell size
    float cellSize;

    // cells container
    IsoCell ***cells;

    // bool for if we draw outlines
    bool drawCellOutlines;


    // constructor
    IsoGrid(Vector2 loc_in, int cols_in, int rows_in, float cellSize_in, Vector2 dimensions_in, bool paintCellOutline_in);

    // destructor
    ~IsoGrid();

    // constuctor helper member functions

    // for converting cell indicies to placement
    Vector2 cellLocationByIndex(int xIdx, int yIdx);


    // paint function
    void paint();


    // cell get by index
    IsoCell *get(int xIdx, int yIdx);

    // cell get by ui position
    IsoCell *get(Vector2 pos);
};