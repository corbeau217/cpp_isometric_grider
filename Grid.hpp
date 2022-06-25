/**
 * @file Grid.hpp
 * @author Corbeau (https://github.com/corbeau217)
 * @brief base class for generating/handling the grid
 * @version 0.1
 * @date 2022-06-25
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

// define the current class preprocessor variable
#define __CLASSNAME__ Grid

// saves typing std::
using namespace std;

// post/pre processor stuff here
#define GRID_DEFAULT_COLS 10
#define GRID_DEFAULT_ROWS 10
#define GRID_CALCULATE_COLSANDROWS true

/**
 * @brief base grid class that handles the grid
 * 
 * drawn from the centre using gridLoc as the centre
 * 
 * !!~ REQUIRES YOU TO INCLUDE THE HEADER FOR TEMPLATE CLASS ~!!
 * !!~        BEFORE DECLARING A CONTAINER TO USE THIS       ~!!
 * 
 */
template<class C>
class __CLASSNAME__ {
    public:
    // draw from location
    Vector2 gridLoc;
    // draw dimensions
    Vector2 dimensions;

    // counts
    int cols;
    int rows;

    // cell size
    float cellDiam;

    // cells container
    C ***cells;

    // bool for if we draw outlines
    bool drawCellOutlines;


    // default constructor
    __CLASSNAME__();
    // constructor
    __CLASSNAME__(Vector2 centerLoc_in, Vector2 dimensions_in, float cellDiam_in, bool paintCellOutline_in);

    // destructor
    ~__CLASSNAME__();

    // constuctor helper member functions

    // for converting cell indicies to placement
    virtual Vector2 cellLocationByIndex(int xIdx, int yIdx);


    // paint function
    void paint();


    // cell get by index
    C *get(int xIdx, int yIdx);

    // cell get by ui position
    C *get(Vector2 pos);

    // check if this location is valid by index
    bool validLocation(int xIdx, int yIdx);

    // generate Vector2 for top-left
    Vector2 topLeftV();

    // for calculating the possible rows that fit predetermined circumstances
    static int possibleRows(Vector2 uiDimensions_in, float cellDiam_in);
    // for calculating the possible cols that fit predetermined circumstances
    static int possibleCols(Vector2 uiDimensions_in, float cellDiam_in);
};

// undefine our current class name preprocessor var
#undef __CLASSNAME__