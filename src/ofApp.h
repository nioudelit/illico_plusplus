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
    - Pouvoir supprimer une image spécifique de la liste
     - selecteur images
     - afficher image sélectionner aperçu


     
    FLUX ——— à voir.
    
    - Retourner camera ?
    - VOir quel calcque est caché ou non
    - remettre toutes les barres compteurs a 
     - Spécifier quels calques peuvent être «fondverisés»
     - Stoper boucle (play/stop)
     - Avancer/reculer image/par image >>
     - Remettre à zéro compteur
     - Jouer sans boucler.
     - Pouvoir choisir une image disD
     - dragged pour parcourir listes img.
     
    CLASSE SORTIE
     
     - Choisir fond sortie: soit vert soit noir.
     - Exporter sortie en suite images
     - exporter séquence

     
     Nouvelle version de l'illico-cinoche (Programme fait initialement pour l'impro visuelle en direct). Cette version, moins axée «live», permet de créer rapido des petites animations/boucles avec flux webcam, calques et fond vert. #lowFi #cadavreExquisAnimé
     — http://completement.pt/dqsdqsdsd —
     
     C'est encore en chantier et tout, y'a encore plein de bugs et cie, pas très ergonomique et tout mais bon ça marche un peu. C'est vraiment un programme de la râcle.
     
    */

    
    
};
