/**
 * @file IsoCell.hpp
 * @author Corbeau (https://github.com/corbeau217)
 * @brief handles the individual cells
 * @version 0.1
 * @date 2022-06-24
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


#define ISOCELL_DEFAULT_FILLCOLOR WHITE

#define ISOCELL_DRAWWITHLINES true
#define ISOCELL_DRAWASBOXES false



class IsoCell {
    public:
    // where in the ui this is drawn from
    Vector2 uiLoc;

    // position in the grid
    int col;
    int row;

    // size of cell
    float cellSize;

    // fill color
    Color cellColor;

    // if this cell wants its outline drawn
    bool drawOutline;


    //constructor
    IsoCell(Vector2 loc_in, int col, int row, float size_in, bool drawOutline_in);
    // destructor
    ~IsoCell();


    // paint member function
    void paint();


    // location getter
    Vector2 getLoc();

    // if a location is contained in this cell
    bool contains(Vector2 loc_in);

};
