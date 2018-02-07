#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //CAMERA
    w = 400;
    h = 300;
    camera.initGrabber(w, h);
    
    //BOUCLES
    for(int i = 0; i < n; i++){
        animation[i].setup(w, h, raccourcis[i], i);
    }
    
    //INIT COMMANDES
    modeSuppr = false;
    vueCamera = false;
    sendData = false;
    curseur = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    camera.draw(w, 0);
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
    for(int i = 0; i < sizeof(raccourcis); i++){
        if(key == raccourcis[i] || key == ofToChar(ofToUpper(ofToString(raccourcis[i])))){
            curseur = i;
        }
    }
    if(modeSuppr == false){
        ofFbo injectionCamera;
        injectionCamera.allocate(w, h);
        injectionCamera.begin();
        ofClear(0);
        camera.draw(0, 0);
        injectionCamera.end();
        animation[curseur].update(key, injectionCamera);
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
    ofDrawBitmapString(msgETAT, 100, 50);
}
