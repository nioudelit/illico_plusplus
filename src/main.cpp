#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    ofGLWindowSettings settings;
    
    settings.setGLVersion(3,2);
    settings.width = 1000;
    settings.height = 700;
    settings.setPosition(ofVec2f(0,0));
    ofCreateWindow(settings);
    ofRunApp(new ofApp());
    
    //shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    //settings.width = 400;
    //settings.height = 300;
    //settings.setPosition(ofVec2f(0,0));
    //settings.windowMode = OF_WINDOW;
    //shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
    
    
    
    /*shared_ptr<ofApp> mainApp(new ofApp);
    shared_ptr<GuiApp> guiApp(new GuiApp);
    mainApp->gui = guiApp;
    
    ofRunApp(guiWindow, guiApp);
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
     */
}