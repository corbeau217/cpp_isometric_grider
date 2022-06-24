/**
 * @file AppStageIso.hpp
 * @author Corbeau (https://github.com/corbeau217)
 * @brief to declutter the AppStage file and make our own
 * @version 0.1
 * @date 2022-06-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// header guard
#pragma once

// include our base class
#include "AppStage.hpp"
// include our grid class
#include "IsoGrid.hpp"

#define APPSTAGEISO_OFFSET_GRID_BOOL true

class AppStageIso : public AppStage {
    public:
    // grid params
    Vector2 gridLoc;
    float cellSize;

    // grid instance
    unique_ptr<IsoGrid> grid;

    // constructor
    AppStageIso(Vector2 dimensions_in);
    // destructor
    ~AppStageIso();

    // paint member function
    void paint();
};