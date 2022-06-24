/**
 * @file App.cpp
 * @author Corbeau (https://github.com/corbeau217)
 * @brief this defines our raylib app
 * @version 0.1
 * @date 2022-06-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// include our header
#include "App.hpp"
#include "AppStageIso.hpp"

// define the current class preprocessor variable
#define __CLASSNAME__ App

// so the preprocessor will handle filling in what AppStage we use
#define APPSTAGE_TYPE AppStageIso
#define APPSTAGE_PARAMS Vector2{appDimensions}

// ----------------------------------------
// define static members

unique_ptr<App> __CLASSNAME__::app = make_unique<App>();

void __CLASSNAME__::start(){
    cout << "[running]: App::start()" << endl;
    __CLASSNAME__::app->run();
}

// ----------------------------------------
// define instance members

// define our constructor
__CLASSNAME__::__CLASSNAME__() :
// we gotta do these in order of their declaration from the header
// setup dimensions
appWidth{DEFAULT_WIDTH}, appHeight {DEFAULT_HEIGHT},
appDimensions{DEFAULT_WIDTH_FLOAT, DEFAULT_HEIGHT_FLOAT},
// setup framerate
appFramerate {DEFAULT_FRAMERATE},
// setup default title
appTitle {DEFAULT_TITLE},
// set initialisation bool to false
initialised {false},
// setup default background color
appFrameBackground {DEFAULT_FRAME_BG}
{
    // setup app stage
    appStage = make_unique<APPSTAGE_TYPE>(APPSTAGE_PARAMS);
    this->updateTitle(appStage->getDesiredTitle());
    
    // setup our vars for refreshing
    framesUntilRefreshCooldown = {0};
}
// define our destructor
__CLASSNAME__::~__CLASSNAME__(){
    //TODO
    // delete appStage;
}

// define getters

int __CLASSNAME__::getWidth(){
    return appWidth;
}
int __CLASSNAME__::getHeight(){
    return appHeight;
}
int __CLASSNAME__::getFramerate(){
    return appFramerate;
}
string __CLASSNAME__::getTitle(){
    return appTitle;
}

// define member functions

/**
 * @brief change the apps title
 * 
 */
void __CLASSNAME__::updateTitle(string newTitle){
    appTitle = newTitle;
    if(initialised)
        SetWindowTitle(newTitle.c_str());
}

/**
 * @brief updates app dimensions
 * 
 */
void __CLASSNAME__::updateDimensions(int newWidth, int newHeight){
    appWidth = newWidth;
    appHeight = newHeight;
    // check if window initialised
    if(initialised)
        // change the window size
        SetWindowSize(newWidth,newHeight);
}

/**
 * @brief update our app framerate
 * 
 */
void __CLASSNAME__::updateFramerate(int newFramerate){
    appFramerate = newFramerate;
    if(initialised)
        SetTargetFPS(newFramerate);
}

/**
 * @brief generate the app
 * 
 */
void __CLASSNAME__::initialise(){
    if(!initialised){
        InitWindow( getWidth(), getHeight(), getTitle().c_str());
        SetTargetFPS( getFramerate() );
        initialised = true;
    }
    else
        reinitialise();
}

/**
 * @brief same as this->initialise(); but for use when
 *      already running
 * 
 */
void __CLASSNAME__::reinitialise(){
    // start our cooldown variable
    framesUntilRefreshCooldown = REFRESH_FRAME_COOLDOWN;

    // change everything back to defaults
    updateDimensions(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    updateFramerate(DEFAULT_FRAMERATE);
    updateTitle(DEFAULT_TITLE);
    // TODO: modify children to default
    appStage = make_unique<APPSTAGE_TYPE>(APPSTAGE_PARAMS);
}

/**
 * @brief anything needed to be done when the app is closed
 * 
 */
void __CLASSNAME__::cleanup(){
    //TODO
}

/**
 * @brief paint single frame
 * 
 */
void __CLASSNAME__::paint(){
    // code for handling refreshing the grid
    if(desireRefresh())
        reinitialise();
    
    // continue as normal
    ClearBackground(appFrameBackground);
    // check our appStage is ready for painting
    // if(appStage)
        // hand off for painting
    appStage->paint();

    // done paint frame, tick refresh cooldown
    tickRefreshCooldown();
}

/**
 * @brief this is called to run a created App instance
 * 
 */
void __CLASSNAME__::run(){
    // check if initialised
    if(!initialised)
        initialise();
    
    // handles the draw loop
    while( !WindowShouldClose() ){
        BeginDrawing();
        paint();
        EndDrawing();
    }

    // cleanup the app
    cleanup();
}

/**
 * @brief checks if we should refresh
 * 
 * @return true : APP_REFRESH_KEY down and not cooldown
 * @return false : otherwise
 */
bool __CLASSNAME__::desireRefresh(){
    // check if cooldown
    if(framesUntilRefreshCooldown > 0)
        return false;
    
    // check if key down
    if(IsKeyDown(APP_REFRESH_KEY))
        return true;
    
    // otherwise
    return false;
}

// handles ticking down the refresh cooldown
void __CLASSNAME__::tickRefreshCooldown(){
    if(framesUntilRefreshCooldown > 0)
        --framesUntilRefreshCooldown;
}


// undefine the current class preprocessor variable
#undef __CLASSNAME__