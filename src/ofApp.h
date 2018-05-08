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
    int * indiceVignette();
    
    
    int w;
    int h;
    int n = 5;
    int curseur;
    int calqueSup = 0;
    int calqueSupTemp = 0;
    
    ofVideoGrabber camera;
    Animation animation[5];
    ofShader enleverVert;
    
    Vignette vignette;
    
    ofxFloatSlider deplacer;
    ofxFloatSlider hueV;
    ofxFloatSlider saturationV;
    ofxFloatSlider brightnessV;
    ofxPanel gui;
    
    /////
    ofxToggle tagueule;
    ofxFloatSlider opaciteCam;
    ofxToggle playStop;
    ofxToggle vertOuNoir;
    ofxPanel guigui;
    
    
    bool modeSuppr;
    bool vueCamera;
    bool sendData;
    char raccourcis[5] = {'a', 'z', 'e', 'r', 't'};
    
    
    /*
     
     CLASSE VIGNETTE?
     
    - Menu (paint)
        - formes (�toiles, rond, carr�)
    - Ajuster couleur d'une ligne animation
    - erosion
    
    $ selecteur images
     - afficher image s�lectionner aper�u
     - Pouvoir supprimer une image sp�cifique de la liste


     
    FLUX ��� � voir.
    
     CHANGER ORDRE DES CALQUES
    - Retourner camera ?
    - parametrer camera
    - VOir quel calcque est cach� ou non
    - remettre toutes les barres compteurs a 
     - Sp�cifier quels calques peuvent �tre �fondveris�s�
     - Stoper boucle (play/stop)
     - Avancer/reculer image/par image >>
     - Remettre � z�ro compteur
     - Jouer sans boucler.
     - Pouvoir choisir une image disD
     - dragged pour parcourir listes img.
     - TISSAGE LISTE ANIM VERS PATTERN MOUVEMENT DESSINABLE
     - Calque de calque (pgraphics dans pgraphics).
     - Un menu
     - Dupliquer images
     
    CLASSE SORTIE
     
     - Choisir fond sortie: soit vert soit noir.
     - Exporter sortie en suite images
     - exporter s�quence
     - sauvegarder (banderoles?) --> importer exporter suite images

     
     Niou version de l'illico-cinoche (soft fait initialement pour l'impro visuelle en direct). Ce prototype, moins ax� �live�, permet de cr�er rapido des ptites s�quences anim�es via flux webcam, calques et fond vert. #lowFi #cadavreExquisAnim� #openframeworks
     http://completement.pt/dqsdqsdsd
     
     C'est encore en chantier et tout, y'a encore plein de bugs et cie, pas ergonomique, des choses abscentes etc. mais bon �a marche (un peu). C'est vraiment un programme de la r�cle, cod� sans trop savoir o� j'allais� donc bon.
     
    */

    
    
};
