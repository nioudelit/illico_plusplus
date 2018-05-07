#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Animation.h"

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
    void plusGrandCardinal();
    
    int w;
    int h;
    int n = 5;
    int curseur;
    
    ofVideoGrabber camera;
    Animation animation[5];
    ofShader enleverVert;
    
    ofxFloatSlider deplacer;
    ofxFloatSlider opaciteCam;
    ofxFloatSlider hueV;
    ofxFloatSlider saturationV;
    ofxPanel gui;
    
    
    
    bool modeSuppr;
    bool vueCamera;
    bool sendData;
    char raccourcis[5] = {'a', 'z', 'e', 'r', 't'};
    
    
    /*
     
    - Correction image par image avec brush vert
    - Dessiner sur calque (paint)
    - Choisir fond sortie: soit vert soit noir.
    - Ajuster couleur d'une ligne animation
    - Stoper boucle (play/stop)
    - Avancer/reculer image/par image >>
    - Exporter sortie en suite images
    - Spécifier quels calques peuvent être «fondverisés»
    - Remettre à zéro compteur
    - Jouer sans boucler.
    - Pouvoir choisir une image disD
     
     
    */

    
    
};
