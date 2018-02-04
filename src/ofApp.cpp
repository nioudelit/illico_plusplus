#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //CAMERA
    w = 400;
    h = 300;
    modeSuppr = false;
    vueCamera = false;
    sendData = false;
    camera.initGrabber(w, h);
    
    //BOUCLES
    for(int i = 0; i < n; i++){
        animation[i].setup(w, h, raccourcis[i], i);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    camera.draw(0, 0);
    for(int i = 0; i < n; i++){
        animation[i].draw();
    }
    obtenirFrameRate();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'x'){
        modeSuppr = true;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(modeSuppr == false){
        for(int i = 0; i < n; i++){
            animation[i].update(key);
        }
    } else {
        for(int i = 0; i < n; i++){
            animation[i].effacer(key);
        }
    }
    modeSuppr = false;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

void ofApp::obtenirFrameRate(){
    //////FRAMERATE///////
    ofSetColor(255);
    string msg = "fps: " + ofToString(ofGetFrameRate(), 2);
    ofDrawBitmapString(msg, 10, 20);
    //ETAT VARIABLE EFFACER
    string msgETAT = "ETAT: " + ofToString(modeSuppr, 2);
    ofDrawBitmapString(msgETAT, 10, 50);
    /////////////////////
}
