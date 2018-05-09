#ifndef ANIMATION
#define ANIMATION

#include <ofMain.h>
#include "ofxGui.h"

class Animation{
    
public:
    
    Animation();
    
    void setup(int largeur_, int hauteur_, char toucheDAction, int identifiant);
    void update(int key, ofFbo capture);
    void variables(float deplacer_, float hue_, float saturation_, float brightness_, float tailleSouris_);
    void draw(bool jouer, int calque_);

    void vignettes(int i_);
    
    int cardinal();
    int numeroVignettePointee(int x_);
    int indiceVignette();
    bool estJoue();
    
    ofFbo imageVignette(int n_);
    
    void effacer(int key);
    void effacerVignette(int indice_);
    void afficherCompteur();
    
    void avancer();
    void reculer();
    void choisir(int x_);
    void cacher();
    void montrer();
    
    void onGifSaved(string & fileName);
    void exit();
    
    vector <ofFbo> images;
    ofShader shader;
    
    int compteur;
    int engrenage;
    int id_;
    
    float deplacer;
    float hue;
    float saturation;
    float brightness;
    float tailleSouris;
    
    char touche;
    char toucheMaj;
    bool seJoue = false;
    int largeur;
    int hauteur;
    
};

#endif