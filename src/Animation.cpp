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

void Animation::update(int key, ofFbo capture){
    if(key == toucheMaj){
        images.push_back(capture);
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
        shader.setUniform1f("b", 0.14);
        shader.setUniformTexture("tex0", images[compteur].getTexture(), id_);
        images[compteur].draw(0, 0);
        shader.end();
        
        //for(int i = 0; i < images.size(); i++){
          //  images[i].draw(largeur, hauteur/2*i, largeur/2, hauteur/2);
        //}
    }
    afficherCompteur();
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

void Animation::afficherCompteur(){
    //////FRAMERATE///////
    ofSetColor(255);
    string msg = "fps: " + ofToString(compteur, 2);
    ofDrawBitmapString(msg, 10, id_ * 10 + 30);
}
