#ifndef ANIMATION
#define ANIMATION

#include <ofMain.h>

class Animation{
    
public:
    
    Animation();
    
    void setup(int largeur_, int hauteur_, char toucheDAction, int identifiant);
    void update(int key, ofFbo capture);
    void draw();
    void capturer();
    void jouer();
    void cacher();
    void effacer(int key);
    void afficherCompteur();
    
    vector <ofFbo> images;
    ofShader shader;
    
    int compteur;
    int id_;
    char touche;
    char toucheMaj;
    bool seJoue = false;
    int largeur;
    int hauteur;
    
    
};

#endif