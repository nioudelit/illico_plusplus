#pragma once

#include "ofMain.h"
#include "Animation.h"
#include "GuiApp.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void obtenirFrameRate();
    
    int w;
    int h;
    int n = 5;
    
    ofVideoGrabber camera;
    Animation animation[5];
    ofShader enleverVert;
    
    bool modeSuppr;
    bool vueCamera;
    bool sendData;
    char raccourcis[5] = {'q', 'w', 'e', 'r', 't'};
    
    shared_ptr<GuiApp> gui;
    
};
