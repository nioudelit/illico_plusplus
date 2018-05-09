#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxGifEncoder.h"
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
    void selecteur();
    
    void onGifSaved(string & fileName);
    void exit();
    
    
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
    ofxFloatSlider tailleSouris;
    ofxToggle playStop;
    ofxToggle vertOuNoir;
    ofxPanel guigui;
    
    //////GIF EXPORT
    ofxGifEncoder gifEncoder;
    ofImage imgSauvegarde;
    
    
    bool modeSuppr;
    bool vueCamera;
    bool sendData;
    char raccourcis[5] = {'a', 'z', 'e', 'r', 't'};
    
    bool modeSelect = false;
    int caseId[2] = {0, 0};
    
    
    /*
     
     CLASSE VIGNETTE?
     
    - Menu (paint)
        - formes (�toiles, rond, carr� voire images)
    - Ajuster couleur d'une ligne animation
    x erosion
    
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
     
     - Apercu fond vert incruste webcam flux
     
    CLASSE SORTIE
     
     - Choisir fond sortie: soit vert soit noir.
     - Exporter sortie en suite images
     - exporter s�quence
     - sauvegarder (banderoles?) --> importer exporter suite images
     - gif ffmpeg

     
     Niou version de l'illico-cinoche (soft fait initialement pour l'impro visuelle en direct). Ce prototype, moins ax� �live�, permet de cr�er rapido des ptites s�quences anim�es via flux webcam, calques et fond vert. #lowFi #cadavreExquisAnim� #openframeworks
     http://completement.pt/dqsdqsdsd
     
    (C'est un banc titre quoi)
     
     C'est encore en chantier et tout c'est plut�t pour un usage priv� (interface pas tr�s �affordante�). C'est vraiment un programme de la r�cle, cod� sans trop savoir o� �a allais� donc bon. �a fera une base correcte.
     
     Pour l'instant c'eest compil� sur mac, mais je ferais un ptit export pour linuss. La version linuss aura une fonction en plus assez pratique: gestion de la webcam (uvc).
     
     Ce n'est pas un logiel de montage, juste un �banc-titre� pour animer des choses.
     
     
    */

    
    
};
