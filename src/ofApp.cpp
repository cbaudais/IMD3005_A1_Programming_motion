#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // init bkg
    ofSetBackgroundColor(35, 145, 255);
    m_bkg_bubblesImage.load("bkg_bubbles.png");
    m_bkg_bubblesPos.set(ofGetWindowWidth()/2.0f, ofGetWindowHeight()/2.0f);
    m_bkg_bubblesAngle = 0.0f;
    
    // init submarine stuff
    m_submarineImage.load("submarine.png");
    m_submarineImage.resize(300, 300);
    m_submarinePos.set(ofGetWindowWidth()/2.0f, ofGetWindowHeight()/2.0f);
    m_submarinePosTarget.set(m_submarinePos.x, m_submarinePos.y);
    m_submarineAngle = 0.0f;
    
    // init jellyfish stuff
    m_jellyfishImage.load("jellyfish.png");
    m_jellyfishImage.resize(300, 300);
    m_jellyfishPos.set(100.0f, 0);
    m_jellyfishAngle = 0.0f;
    
    // init bubble stuff
    m_bubbleImage.load("bubble.png");
    m_bubbleImage.resize(200, 200);
    m_bubblePos.set(100.0f, 0);
    m_bubbleAngle = 0.0f;

    // init diver1 stuff
    m_diver1Image.load("diver1.png");
    m_diver1Image.resize(200, 200);
    m_diver1Pos.set(100.0f, 0);
    m_diver1Angle = 0.0f;
    
    // init diver2 stuff
    m_diver2Image.load("diver2.png");
    m_diver2Image.resize(200, 200);
    m_diver2Pos.set(450.0f, 0);
    m_diver2PosTarget.set(m_diver2Pos.x, m_diver2Pos.y);
    m_diver2Angle = 0.0f;
    
    //m_submarineImage.setAnchorPoint(m_submarineImage.getWidth()/2.0f, m_submarineImage.getHeight()/2.0f);
    //m_submarineImage.setAnchorPercent(0.5, 0.5);
    
    // tells OF to set anchor point to center on all images
    ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    m_bkg_bubblesPos.set(ofGetWindowWidth()/2.0f, ofGetWindowHeight()/2.0f);
    // get vector angle from X and Y using cos sin tan to point to wherever mouse is
    // mouse angle minus submarine position gives us angle middle, point correct
    ofVec2f submarineToMouseVec = ofVec2f(ofGetMouseX() - m_submarinePos.x, ofGetMouseY() - m_submarinePos.y);
    m_submarineAngle = ofRadToDeg(atan2(submarineToMouseVec.y, submarineToMouseVec.x));
    
    ofVec2f diver2ToParentVec = ofVec2f(m_submarinePos.x - m_diver2Pos.x - 500.0f, m_submarinePos.y - m_diver2Pos.y);
    m_diver2Angle = ofRadToDeg(atan2(m_submarinePos.y, m_submarinePos.x));

    
    // lerp
    m_submarinePos.x = lerp(m_submarinePos.x, m_submarinePosTarget.x, 0.08f); // 1.0f instant, smol slower
    m_submarinePos.y = lerp(m_submarinePos.y, m_submarinePosTarget.y, 0.08f);

    m_diver2Pos.x = lerp(m_diver2Pos.x, m_submarinePos.x, 0.02f); // 1.0f instant, smol slower
    m_diver2Pos.y = lerp(m_diver2Pos.y, m_submarinePos.y, 0.02f);
    
    
    m_bkg_bubblesAngle += -0.1f;
    m_jellyfishAngle += 0.5f;
    m_bubbleAngle += 0.5f;
    m_diver1Angle += 0.5f;
    m_diver2Angle += 0.5f;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //ofSetColor(255, 255, 255); // color tint
    
    // bkg_bubbles
    ofPushMatrix();
        ofTranslate(m_bkg_bubblesPos);
        ofScale(0.5,0.5);
        ofRotate(m_bkg_bubblesAngle);
        m_bkg_bubblesImage.draw(0,0);
    
        drawMoon(m_bubbleImage, m_bubbleAngle * 1.0f, m_bubblePos.y + 500.0f, 0.35f, m_bubbleAngle * 2.0f);
        drawMoon(m_bubbleImage, m_bubbleAngle * -2.0f, m_bubblePos.y + 600.0f, 0.2f, m_bubbleAngle * -1.0f);
        drawMoon(m_bubbleImage, m_bubbleAngle * -3.0f, m_bubblePos.x + 300.0f, 0.3f, m_bubbleAngle * 1.0f);
        drawMoon(m_bubbleImage, m_bubbleAngle * -2.5f, m_bubblePos.y + 500.0f, 0.45f, m_bubbleAngle * -1.0f);
        drawMoon(m_bubbleImage, m_bubbleAngle * -1.0f, m_bubblePos.y + 700.0f, 0.3f, m_bubbleAngle * 1.0f);
        drawMoon(m_bubbleImage, m_bubbleAngle * 1.0f, m_bubblePos.y + 500.0f, 0.35f, m_bubbleAngle * 2.0f);
        drawMoon(m_bubbleImage, m_bubbleAngle * 2.0f, m_bubblePos.y + 600.0f, 0.2f, m_bubbleAngle * -1.0f);
        drawMoon(m_bubbleImage, m_bubbleAngle * 3.0f, m_bubblePos.x + 300.0f, 0.3f, m_bubbleAngle * 1.0f);
        drawMoon(m_bubbleImage, m_bubbleAngle * 2.5f, m_bubblePos.y + 500.0f, 0.45f, m_bubbleAngle * -1.0f);
        drawMoon(m_bubbleImage, m_bubbleAngle * 1.5f, m_bubblePos.y + 700.0f, 0.3f, m_bubbleAngle * 1.0f);
    
        ofPushMatrix();
            // the order of things called matters
            ofRotate(m_jellyfishAngle * -0.5f); //orbit around parent, smol faster
            ofTranslate(m_jellyfishPos.x + 200.0f, 0.8f); //away from radius
            ofScale(1.0f); //size
            ofRotate(m_jellyfishAngle * -0.0f); //orbit about itself
            m_jellyfishImage.draw(0,0);
                drawMoon(m_bubbleImage, m_bubbleAngle * 1.0f, m_bubblePos.x + -40.0f, 0.5f, m_bubbleAngle * 2.0f);
                drawMoon(m_bubbleImage, m_bubbleAngle * 2.0f, m_bubblePos.x + 20.0f, 0.4f, m_bubbleAngle * -1.0f);
                drawMoon(m_bubbleImage, m_bubbleAngle * -1.0f, m_bubblePos.x + 75.0f, 0.45f, m_bubbleAngle * 1.0f);
                //      image           orbitspeed              from radius         size    self-rotate speed
        ofPopMatrix();
    
        ofPushMatrix();//big
            ofRotate(m_jellyfishAngle * -0.1f);
            ofTranslate(m_jellyfishPos.x + 550.0f, 0.8f);
            ofScale(1.5f);
            ofRotate(m_jellyfishAngle * -0.0f);
            m_jellyfishImage.draw(0,0);
                drawMoon(m_bubbleImage, m_bubbleAngle * 1.0f, m_bubblePos.x + -50.0f, 0.4f, m_bubbleAngle * 2.0f);
                drawMoon(m_bubbleImage, m_bubbleAngle * -2.0f, m_bubblePos.x + 50.0f, 0.35f, m_bubbleAngle * -1.0f);
                drawMoon(m_bubbleImage, m_bubbleAngle * 1.0f, m_bubblePos.x + 80.0f, 0.2f, m_bubbleAngle * 1.0f);
                drawMoon(m_bubbleImage, m_bubbleAngle * -3.0f, m_bubblePos.x + 60.0f, 0.3f, m_bubbleAngle * -3.0f);
                drawMoon(m_bubbleImage, m_bubbleAngle * 0.8f, m_bubblePos.x + 70.0f, 0.45f, m_bubbleAngle * 2.0f);
        ofPopMatrix();
    
        ofPushMatrix(); //smol
            ofRotate(m_jellyfishAngle * -2.0f);
            ofTranslate(m_jellyfishPos.x + 350.0f, 0.8f);
            ofScale(0.5f);
            ofRotate(m_jellyfishAngle * -0.0f);
            m_jellyfishImage.draw(0,0);
                drawMoon(m_bubbleImage, m_bubbleAngle * 3.0f, m_bubblePos.x + -50.0f, 0.8f, m_bubbleAngle * 2.0f);
                drawMoon(m_bubbleImage, m_bubbleAngle * 2.0f, m_bubblePos.x + 50.0f, 0.6f, m_bubbleAngle * -1.0f);
                drawMoon(m_bubbleImage, m_bubbleAngle * -1.0f, m_bubblePos.x + 100.0f, 0.9f, m_bubbleAngle * 1.0f);
        ofPopMatrix();
    
        ofPushMatrix(); //middle
            ofRotate(m_jellyfishAngle * -1.8f);
            ofTranslate(m_jellyfishPos.x + 30.0f, 0.8f);
            ofScale(0.7f);
            ofRotate(m_jellyfishAngle * -0.0f);
            m_jellyfishImage.draw(0,0);
                drawMoon(m_bubbleImage, m_bubbleAngle * 3.0f, m_bubblePos.x + -50.0f, 0.4f, m_bubbleAngle * 2.0f);
                drawMoon(m_bubbleImage, m_bubbleAngle * 2.0f, m_bubblePos.x + 50.0f, 0.6f, m_bubbleAngle * -1.0f);
                drawMoon(m_bubbleImage, m_bubbleAngle * 1.0f, m_bubblePos.x + 100.0f, 0.5f, m_bubbleAngle * 1.0f);
        ofPopMatrix();
        
        // diver haha
        drawMoon(m_diver1Image, m_diver1Angle * 0.0f, m_diver1Pos.y + 30.0f, 1.0f, m_diver1Angle * -2.0f);
        ofPushMatrix();
            drawMoon(m_bubbleImage, m_bubbleAngle * 3.0f, m_bubblePos.x + -70.0f, 0.1f, m_bubbleAngle * 2.0f);
            drawMoon(m_bubbleImage, m_bubbleAngle * 2.0f, m_bubblePos.x + -40.0f, 0.2f, m_bubbleAngle * -1.0f);
            drawMoon(m_bubbleImage, m_bubbleAngle * 1.0f, m_bubblePos.x + -50.0f, 0.2f, m_bubbleAngle * 1.0f);
        ofPopMatrix();
    ofPopMatrix();
    
    // submarine
    ofPushMatrix();
        ofTranslate(m_submarinePos);
        ofScale(0.5,0.5);
        ofRotate(m_submarineAngle);
        m_submarineImage.draw(0,0);
        
    ofPopMatrix();
    
    // diver2
    ofPushMatrix();
        ofTranslate(m_diver2Pos/*.x - 450.0f, m_diver2Pos.y - 50.0f*/); // where placed
        ofScale(0.5,0.5);
        ofRotate(m_diver2Angle); // follow rotation of submarine
        m_diver2Image.draw(0,0);
            drawMoon(m_bubbleImage, m_bubbleAngle * 3.0f, m_bubblePos.x + -50.0f, 0.4f, m_bubbleAngle * 2.0f);
            drawMoon(m_bubbleImage, m_bubbleAngle * 2.0f, m_bubblePos.x + 30.0f, 0.6f, m_bubbleAngle * -1.0f);
            drawMoon(m_bubbleImage, m_bubbleAngle * 1.0f, m_bubblePos.x + 20.0f, 0.5f, m_bubbleAngle * 1.0f);
    ofPopMatrix();
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    m_submarinePosTarget.set((float)x,(float)y);
}

void ofApp::drawMoon(ofImage &moonRef, float orbitSpeed, float orbitRadius, float scale, float rotateSpeed){
    ofPushMatrix();
        // the order of things called matters
        ofRotate(orbitSpeed); // create an orbit around parent pos
        ofTranslate(orbitRadius, 0.0f);
        ofScale(scale,scale);
        ofRotate(rotateSpeed); // orbit around itself
        moonRef.draw(0,0);
    ofPopMatrix();
}

float ofApp::lerp(float start, float end, float percent){
    return start + percent * (end - start);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_UP) {
        ofSetBackgroundColor(35, 145, 255);
    }
    else if (key == OF_KEY_DOWN) {
        ofSetBackgroundColor(25, 50, 140);
    }
    else if (key == OF_KEY_RIGHT) {
        ofSetBackgroundColor(95, 230, 230);
    }
    else if (key == OF_KEY_LEFT) {
        ofSetBackgroundColor(160, 110, 210);
    }
}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
        //m_submarinePosTarget.set((float)x,(float)y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
        m_submarinePosTarget.set((float)x,(float)y);
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
