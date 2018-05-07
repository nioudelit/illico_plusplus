#ifndef ANIMATION
#define ANIMATION

#include <ofMain.h>
#include "ofxGui.h"

class Animation{
    
public:
    
    Animation();
    
    void setup(int largeur_, int hauteur_, char toucheDAction, int identifiant);
    void update(int key, ofFbo capture);
    void variables(float deplacer_, float hue_, float saturation_);
    void draw(bool jouer);
    void capturer();
    void jouer();
    void vignettes(int i_);
    
    int cardinal();
    int numeroVignettePointee(int x_);
    int indiceVignette();
    
    ofFbo imageVignette(int n_);
    
    void cacher();
    void effacer(int key);
    void afficherCompteur();
    
    vector <ofFbo> images;
    ofShader shader;
    
    int compteur;
    int engrenage;
    int id_;
    float deplacer;
    float hue;
    float saturation;
    char touche;
    char toucheMaj;
    bool seJoue = false;
    int largeur;
    int hauteur;
    
};

#endif