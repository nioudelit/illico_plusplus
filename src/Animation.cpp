#include "Animation.h"


Animation::Animation(){
    
}

void Animation::setup(int largeur_, int hauteur_, char toucheDAction, int identifiant){
    largeur = largeur_;
    hauteur = hauteur_;
    touche = toucheDAction;
    toucheMaj = ofToChar(ofToUpper(ofToString(touche)));
    id_ = identifiant;
    
    shader.load("shaders/test");
}

void Animation::update(int key){
    if(key == toucheMaj){
        
        /*FBO POUR RECUPERER CAPTURE SCREEN (TEXTURE)*/
        ofFbo tempfbo;
        tempfbo.allocate(largeur, hauteur, GL_RGBA);
        tempfbo.begin();
        ofClear(0,0,0);
        tempfbo.end();
        
        /*CAPTURE ECRAN*/
        ofTexture img;
        img.allocate(largeur, hauteur, GL_RGB);
        img.loadScreenData(0, 0, largeur, hauteur);
        
        /*COPIE TEXTURE DANS LE FBO*/
        tempfbo.begin();
        img.draw(0, 0);
        tempfbo.end();
        
        /*ET NOUVEL OBJET*/
        images.push_back(tempfbo);
        
        seJoue = true;
    } else if (key == touche){
        seJoue =! seJoue;
    }
}

void Animation::draw(){
    if(seJoue && images.size() > 0){
        if(compteur < images.size()){
            compteur++;
        }
        if(compteur == images.size()){
            compteur = 0;
        }

        shader.begin();
        shader.setUniform1f("h", ofMap(ofGetMouseX(), 0, ofGetWindowWidth(), 0.0, 1.0));
        shader.setUniform1f("s", ofMap(ofGetMouseY(), 0, ofGetWindowHeight(), 0.0, 1.0));
        shader.setUniform1f("b", 0.2);
        shader.setUniformTexture("tex0", images[compteur].getTexture(), id_);
        images[compteur].draw(largeur, 0);
        shader.end();
        
        //for(int i = 0; i < images.size(); i++){
          //  images[i].draw(largeur, hauteur/2*i, largeur/2, hauteur/2);
        //}
    }
}


void Animation::effacer(int key){
    if(key == touche){
        images.clear();
        seJoue = false;
        compteur = 0;
    }
}


void Animation::capturer(){
    
}

void Animation::jouer(){
    
}


void Animation::cacher(){
    
}
