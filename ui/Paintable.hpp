/**
 * @file ui/Paintable.hpp
 * @author Corbeau (https://github.com/corbeau217)
 * @brief base class for drawing ui elements
 * @version 0.1
 * @date 2022-07-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// header guard
#pragma once

// includes
#include "raylib.h"


// define the current class preprocessor variable
#define __CLASSNAME__ Paintable

class __CLASSNAME__ {
    public:
    // position var
    Vector2 pos;
    // dimensions var
    Vector2 dim;

    // default constructor
    __CLASSNAME__(){}
    // constructor
    // __CLASSNAME__(Vector2 pos_in, Vector2 dim_in);
    // destructor
    virtual ~__CLASSNAME__(){}


    // paint member function
    virtual void paint()=0;

    // get the dimensions of this element
    virtual Vector2 getDim(){
        return dim;
    }
    // set the dimensions of this element
    virtual void setDim(Vector2 dim_in){
        dim = dim_in;
    }

    // get the position of this element
    virtual Vector2 getPos(){
        return pos;
    }
    // set the position of this element
    virtual void setPos(Vector2 pos_in){
        pos = pos_in;
    }

};

// this is so we dont need to rewrite it each time
#define PAINTABLE_INCLUDE_MEMBERS \
    using Paintable::getDim; \
    using Paintable::setDim; \
    using Paintable::setPos; \
    using Paintable::getPos;

// undefine the current class preprocessor variable
#undef __CLASSNAME__