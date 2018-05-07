#include "Vignette.h"


Vignette::Vignette(){
    
}

void Vignette::setup(){
    apercu.clear();
    apercu.allocate(640, 420, GL_RGBA);
}

void Vignette::update(){
}

void Vignette::draw(){
}

void Vignette::selectionnerImg(ofFbo img_){
    apercu = img_;
    apercu.draw(50, 50);
}