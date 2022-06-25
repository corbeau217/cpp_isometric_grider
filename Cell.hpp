/**
 * @file Cell.hpp
 * @author Corbeau (https://github.com/corbeau217)
 * @brief base class for handling the individual cells
 * @version 0.1
 * @date 2022-06-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
//header guard
#pragma once

// std library includes

// raylib includes
#include "raylib.h"

// project includes


// define the current class preprocessor variable
#define __CLASSNAME__ Cell

#define CELL_DEFAULT_FILLCOLOR WHITE

#define CELL_DRAWWITHLINES true
#define CELL_DRAWASBOXES false


/**
 * @brief container for the isometric cells
 * 
 * draw from centre, using uiLoc as the centre
 * 
 */
class __CLASSNAME__ {
    public:
    // where in the ui this is drawn from
    Vector2 uiLoc;

    // position in the grid
    int col;
    int row;

    // size of cell
    float cellDiam;

    // fill color
    Color cellColor;

    // if this cell wants its outline drawn
    bool drawOutline;


    // default constructor
    __CLASSNAME__();
    // constructor
    __CLASSNAME__(Vector2 loc_in, int col, int row, float diam_in, bool drawOutline_in);
    // destructor
    ~__CLASSNAME__();


    // paint member function
    void paint();


    // location getter
    Vector2 getLoc();

    // if a location is contained in this cell
    bool contains(Vector2 loc_in);

};

// undefine our current class name preprocessor var
#undef __CLASSNAME__