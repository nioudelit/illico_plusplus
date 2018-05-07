#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "Animation.h"
#include "Vignette.h"

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
    int numeroVignettePointee(int x_);
    
    int w;
    int h;
    int n = 5;
    int curseur;
    
    ofVideoGrabber camera;
    Animation animation[5];
    ofShader enleverVert;
    
    Vignette vignette;
    
    ofxFloatSlider deplacer;
    ofxFloatSlider hueV;
    ofxFloatSlider saturationV;
    ofxPanel gui;
    
    /////
    ofxToggle tagueule;
    ofxFloatSlider opaciteCam;
    ofxToggle playStop;
    ofxPanel guigui;
    
    
    bool modeSuppr;
    bool vueCamera;
    bool sendData;
    char raccourcis[5] = {'a', 'z', 'e', 'r', 't'};
    
    
    /*
     
     CLASSE VIGNETTE?
     
    - Correction image par image avec brush vert
    - Dessiner sur calque (paint)
    - Ajuster couleur d'une ligne animation
    - Pouvoir supprimer une image sp�cifique de la liste
     - selecteur images
     - afficher image s�lectionner aper�u


     
    FLUX ��� � voir.
    
    - Retourner camera ?
    - VOir quel calcque est cach� ou non
    - remettre toutes les barres compteurs a 
     - Sp�cifier quels calques peuvent �tre �fondveris�s�
     - Stoper boucle (play/stop)
     - Avancer/reculer image/par image >>
     - Remettre � z�ro compteur
     - Jouer sans boucler.
     - Pouvoir choisir une image disD
     - dragged pour parcourir listes img.
     
    CLASSE SORTIE
     
     - Choisir fond sortie: soit vert soit noir.
     - Exporter sortie en suite images
     - exporter s�quence

     
     Nouvelle version de l'illico-cinoche (Programme fait initialement pour l'impro visuelle en direct). Cette version, moins ax�e �live�, permet de cr�er rapido des petites animations/boucles avec flux webcam, calques et fond vert. #lowFi #cadavreExquisAnim�
     � http://completement.pt/dqsdqsdsd �
     
     C'est encore en chantier et tout, y'a encore plein de bugs et cie, pas tr�s ergonomique et tout mais bon �a marche un peu. C'est vraiment un programme de la r�cle.
     
    */

    
    
};
