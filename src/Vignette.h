#ifndef VIGNETTE
#define VIGNETTE

#include <ofMain.h>
#include "ofxGui.h"

class Vignette{
    
public:
    
    Vignette();
    
    void setup();
    void update();
    void draw();
    void selectionnerImg(ofFbo img_);
    
    ofFbo apercu;
    
};

/*
- Correction image par image avec brush vert
- Dessiner sur calque (paint)
- Ajuster couleur d'une ligne animation
- Pouvoir supprimer une image spécifique de la liste
- selecteur images
- afficher image sélectionner aperçu
 */

#endif