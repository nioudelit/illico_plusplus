#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //CAMERA
    w = 640;
    h = 480;
    
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
    
    //GUYGUY
    gui.setup();
    gui.add(deplacer.setup("deplacer", 0, -600, 0));
    gui.add(opaciteCam.setup("opaciteCam", 0, 0, 255));
    gui.add(hueV.setup("hueV", 0, 0., 1.));
    gui.add(saturationV.setup("saturationV", 0.9, 0., 1.));
    gui.setPosition(640, 5);
    
    ofSetFrameRate(12);
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.update();
    for(int i = 0; i < n ; i++){
        animation[i].variables(deplacer, hueV, saturationV);
    }
   
}

//--------------------------------------------------------------
void ofApp::draw(){
    plusGrandCardinal();
    ofBackground(0);
    
    ofFill(); ofSetColor(110, 110, 110);
    ofDrawRectangle(640, 0, ofGetWindowWidth() - 640, ofGetWindowHeight());
    
    ofSetColor(255);
    for(int i = n-1; i >= 0; i--){
        animation[i].vignettes(i);
    }
    
    //camera.draw(w, 0);
    ofFill(); ofSetColor(0);
    ofDrawRectangle(0, 0, 640, 480);
    
    for(int i = 0; i < n; i++){
        animation[i].draw();
    }
    ofSetColor(255, opaciteCam);
    camera.draw(0, 0);
    
    obtenirFrameRate();
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'x'){
        modeSuppr = true;
    }
    if(key == 'c'){
        ofSetFrameRate(12);
    }
    if(key == 'v'){
        ofSetFrameRate(24);
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

void ofApp::plusGrandCardinal(){
    int c [] = {0, 0, 0, 0, 0};
    for(int i = 0; i < n; i++){
        c[i] = animation[i].cardinal();
    }
    int temp = 0;
    
    for(int i = 0; i < n; i++){
        if(c[i]>temp){
            temp = c[i];
        }
    }
    
    deplacer.setMin(temp * 160 * (-1) +  200);
    
}
