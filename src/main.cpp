#include "ofMain.h"
#include "ofApp.h"
#include "GuiApp.h"
#include "ofAppGLFWWindow.h"

//========================================================================
int main( ){
    
    ofGLWindowSettings settings;
    
    settings.setGLVersion(3,2);
    settings.width = 800;
    settings.height = 480;
    settings.setPosition(ofVec2f(0,0));
    //settings.multiMonitorFullScreen = true;
    //settings.windowMode = OF_FULLSCREEN;
    ofCreateWindow(settings);
   // shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    /*
    settings.width = 400;
    settings.height = 300;
    //Zsettings.multiMonitorFullScreen = false;
    //settings.windowMode = OF_WINDOW;
    shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
     */
    
    // this kicks off the running of my app
    // can be OF_WINDOW or OF_FULLSCREEN
    // pass in width and height too:
    ofRunApp(new ofApp());
    
    //shared_ptr<ofApp> mainApp(new ofApp);
    //shared_ptr<GuiApp> guiApp(new GuiApp);
    //mainApp->gui = guiApp;
    
    //ofRunApp(guiWindow, guiApp);
    //ofRunApp(mainWindow, mainApp);
    //ofRunMainLoop();
}