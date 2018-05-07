#include "Animation.h"


Animation::Animation(){
    
}

void Animation::setup(int largeur_, int hauteur_, char toucheDAction, int identifiant){
    images.clear();
    compteur = 0;
    engrenage = 0;
    
    largeur = largeur_;
    hauteur = hauteur_;
    touche = toucheDAction;
    toucheMaj = ofToChar(ofToUpper(ofToString(touche)));
    id_ = identifiant;
    
    shader.load("shaders/test");
    
    //gui.setup();
    //gui.add(slideur.setup("slideur", 640, id_*120, 600));
}

void Animation::update(int key, ofFbo capture){
    
    if(key == toucheMaj && images.size() < 20){
        images.push_back(capture);
        seJoue = true;
    } else if (key == touche){
        seJoue =! seJoue;
    }
}

void Animation::variables(float deplacer_, float hue_, float saturation_){
    deplacer = deplacer_;
    hue = hue_;
    saturation = saturation_;
}

void Animation::draw(bool jouer){
    
    if(seJoue && images.size()>0){
        
        if(compteur < images.size()){
            if(jouer){
                compteur++;
            }
        }
        
        if(compteur == images.size()){
            compteur = 0;
        }
        
        images[compteur].begin();
        ofFill();
        ofSetColor(15, 200, 15);
        ofDrawCircle(ofGetMouseX(), ofGetMouseY(), 20);
        images[compteur].end();
        
        shader.begin();
        //shader.setUniform1f("h", ofMap(0, 0, ofGetWindowWidth(), 0.0, 1.0));
        //shader.setUniform1f("s", ofMap(0, 0, ofGetWindowHeight(), 0.0, 1.0));
        shader.setUniform1f("h", hue);
        shader.setUniform1f("s", saturation);
        shader.setUniform1f("b", 0.14);
        shader.setUniformTexture("tex0", images[compteur].getTexture(), id_);
        images[compteur].draw(0, 0);
        shader.end();
        
    }
    afficherCompteur();
    //gui.draw();
}


void Animation::effacer(int key){
    if(key == touche){
        images.clear();
        seJoue = false;
        compteur = 0;
    }
}

void Animation::vignettes(int i_){
    ofPushMatrix();
    ofTranslate(deplacer, 0);
    ofSetColor(255);
        for(int i = 0; i < images.size(); i++){
            images[i].draw(largeur + i * largeur/4, (5 - i_)* hauteur/4, largeur/4, hauteur/4);
        }
    if(images.size() > 0){
        ofSetColor(255, 0, 0);
        ofDrawLine(largeur + compteur * largeur/4 + 50, (5 - i_) * hauteur/4,
               largeur + compteur * largeur/4 + 50, (5 - i_) * hauteur/4 + hauteur/4);
    }
    
    ofSetColor(255);
    string msg = "position relative souris: " + ofToString(ofGetMouseX() + deplacer * (-1), 2);
    ofPopMatrix();
    
    ofDrawBitmapString(msg, 640, 480);
}

int Animation::indiceVignette(){
    int cervo = (ofGetMouseX() - largeur + deplacer * (-1));
    cervo = cervo / 160;
    
    ofSetColor(240, 0, 20);
    string msg = "position relative souris: " + ofToString(cervo, 2);
    ofDrawBitmapString(msg, 640, 400);
    
    ofNoFill();
    ofSetColor(255, 255, 0);
    ofDrawRectangle(cervo * largeur/4  + largeur + deplacer, ofGetWindowHeight() - hauteur/4, 160, 120);
    
    cout << "Salut " << cervo << endl;
    return 0;
}

int Animation::cardinal(){
    return images.size();
}

int Animation::numeroVignettePointee(int x_){
    int numero = x_ % (160+640);
    return x_;
}

ofFbo Animation::imageVignette(int n_){
    return images[n_];
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
