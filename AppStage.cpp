

#include "AppStage.hpp"
#include "raylib.h"

// define constructor
AppStage::AppStage(int width_in, int height_in){
    // initialise dimension vars
    width = width_in;
    height = height_in;
}

// define destructor
AppStage::~AppStage(){
    //TODO
}



void drawHexagon(int x_in, int y_in, int size){
    int quarts = size/4;
    // get our points
    Vector2 topPoint =      {(float)x_in,            (float)y_in-(quarts*2)};
    Vector2 leftTopPoint =  {(float)x_in-(quarts*2), (float)y_in-quarts    };
    Vector2 leftBotPoint =  {(float)x_in-(quarts*2), (float)y_in+quarts    };
    Vector2 botPoint =      {(float)x_in,            (float)y_in+(quarts*2)};
    Vector2 rightTopPoint = {(float)x_in+(quarts*2), (float)y_in-quarts    };
    Vector2 rightBotPoint = {(float)x_in+(quarts*2), (float)y_in+quarts    };
    // draw our lines
    DrawLineV(topPoint,      leftTopPoint,  BLACK);
    DrawLineV(leftTopPoint,  leftBotPoint,  BLACK);
    DrawLineV(leftBotPoint,  botPoint,      BLACK);
    DrawLineV(botPoint,      rightBotPoint, BLACK);
    DrawLineV(rightBotPoint, rightTopPoint, BLACK);
    DrawLineV(rightTopPoint, topPoint,      BLACK);
}

void AppStage::paint(){
    //TODO: handle frame paint
    Vector2 *pos = new Vector2{100,100};
    drawHexagon(pos->x,pos->y,100);
    drawHexagon(pos->x+100,pos->y,100);
    drawHexagon(pos->x+200,pos->y,100);

}

