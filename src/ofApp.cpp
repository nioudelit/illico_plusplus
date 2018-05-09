#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //CAMERA
    w = 640;
    h = 420;
    
    //camera.listDevices();
    camera.setDeviceID(0); // ou 2 pour firewire
    camera.initGrabber(w, h);
    
    //BOUCLES
    for(int i = 0; i < n; i++){
        animation[i].setup(w, h, raccourcis[i], i);
    }
    
    //VIGNETTE
    vignette.setup();
    
    //INIT COMMANDES
    modeSuppr = false;
    vueCamera = false;
    sendData = false;
    curseur = 0;
    
    //GUYGUY
    //ofColor rouge(140, 10, 20);
    gui.setup();
    gui.add(deplacer.setup("deplacer timeline", 0, -w, 0));
    gui.add(hueV.setup("etendue vert", 0.1, 0., 1.));
    gui.add(saturationV.setup("intensite vert", 0.95, 0., 1.));
    gui.add(brightnessV.setup("lumino vert", 0.01, 0., 1.));
    gui.setPosition(w + w/4, 0);
    
    guigui.setup();
    guigui.add(opaciteCam.setup("calque alpha du flux", 0, 0, 255));
    guigui.add(tagueule.setup("boucler", true));
    guigui.add(playStop.setup("play n stop", false));
    guigui.add(vertOuNoir.setup("fond noir ou vert", false));
    guigui.setPosition(10, h);
    //guigui.setBackgroundColor(rouge);
    
    
    ofSetFrameRate(12);
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.update();
    for(int i = 0; i < n ; i++){
        animation[i].variables(deplacer, hueV, saturationV, brightnessV);
    }
    
    for(int i = 0; i < n; i++){
        if(animation[i].cardinal() > 0){
            if(animation[i].estJoue() && calqueSup >= calqueSupTemp){
                calqueSup = i;
                calqueSupTemp = calqueSup;
            }
        }
    }
    //cout << "plus haut calque visible" << calqueSup << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    plusGrandCardinal();
    ofBackground(0);
    
    ofFill(); ofSetColor(110, 110, 110);
    ofDrawRectangle(w, 0, ofGetWindowWidth() - w, ofGetWindowHeight());
    
    ofSetColor(0, 140, 30);
    for(int i = n-1; i >= 0; i--){
        animation[i].vignettes(i);
    }
    
    //camera.draw(w, 0);
    ofFill();
    if(vertOuNoir){
        ofSetColor(15, 200, 15);
    }else{
       ofSetColor(0); 
    }
    ofDrawRectangle(0, 0, w, ofGetWindowHeight());
    
    for(int i = 0; i < n; i++){
        animation[i].draw(tagueule, calqueSup);
        //animation[i].indiceVignette();
    }
    
    ofSetColor(255, opaciteCam);
    camera.draw(0, 0);
    ofSetColor(255);
    camera.draw(w, 0, w/4, h/4);
    
    
    //GUI DEBORD
    obtenirFrameRate();
    gui.draw();
    guigui.draw();
    
    
    //TEST VIGNETTE//
    indiceVignette();

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
    if(key == OF_KEY_LEFT){
        //cout << "appuyeee" << endl;
        //ofDrawEllipse(700, 600, 100, 100);
    }
    /*
    if(key == ' '){
        for(int i = 0; i < n; i++){
            animation[i].draw();
        }
    }
     */
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
    
    if(key == OF_KEY_LEFT){
        animation[indiceVignette()[1]].reculer();
    }
    if(key == OF_KEY_RIGHT){
        animation[indiceVignette()[1]].avancer();
    }
    if(key == ' '){
        tagueule =! tagueule;
    }
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    //cout << "test   " << x << " , " << y << endl;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    modeSelect =! modeSelect;
    cout << modeSelect << endl;
    
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
    
    deplacer.setMin(temp * w/4 * (-1) + w/4);
    
}

int ofApp::numeroVignettePointee(int x_){
    int numero = int(x_) % (h/4);
    return numero;
}

int * ofApp::indiceVignette(){
    static int posVignette[2];
    
    
    unsigned int X = 0;
    
    if(modeSelect == false){
        X = (ofGetMouseX() - w + deplacer * (-1));
        X = X / (w/4);
        caseId[0] = X;
    } else {
        X = caseId[0];
    }
    
    
    unsigned int Y = 0;
    if (modeSelect == false) {
        ofSetColor(250, 230, 0, 120);
        Y = ofGetMouseY();
        Y = Y / (h/4);
        caseId[1] = Y;
    } else {
        ofSetColor(255, 56);
        Y = caseId[1];
        ofDrawRectangle(640, Y * (h/4),
                        w, h/4);
    }
    
    
    //DESSINER CASE SELECTIONNEE
    
    
    ofDrawRectangle(X * w/4  + w + deplacer, Y * (h/4),
                    w/4, h/4);
    
    ofSetColor(240, 0, 20);
    
    //ECRIRE VALEURS (+ permutation idcalque)
    Y = n - Y;
    if(Y >= 5){
        Y = n-1;
    }
    
    posVignette[0] = X;
    posVignette[1] = Y;
    
    string msg = "indice vignett: " + ofToString(posVignette[0], 2) + "\n calque num: " + ofToString(posVignette[1], 2);
    ofDrawBitmapString(msg, 1050, 20);
    ofSetColor(255);
    
    
    return posVignette;
}
