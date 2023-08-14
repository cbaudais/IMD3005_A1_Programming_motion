#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

    public:
    
        ofImage m_bkg_bubblesImage;
        ofVec2f m_bkg_bubblesPos;
        float m_bkg_bubblesAngle;
        
        ofImage m_submarineImage;
        ofVec2f m_submarinePos;
        ofVec2f m_submarinePosTarget;
        float m_submarineAngle;
        
        ofImage m_jellyfishImage;
        ofVec2f m_jellyfishPos;
        float m_jellyfishAngle;
        
        ofImage m_bubbleImage;
        ofVec2f m_bubblePos;
        float m_bubbleAngle;
        
        ofImage m_diver1Image;
        ofVec2f m_diver1Pos;
        ofVec2f m_diver1PosTarget;
        float m_diver1Angle;
        
        ofImage m_diver2Image;
        ofVec2f m_diver2Pos;
        ofVec2f m_diver2PosTarget;
        float m_diver2Angle;
    
        void setup();
        void update();
        void draw();
    
        void mousePressed(int x, int y, int button);
    
        void drawMoon(ofImage & moonRef, float orbitSpeed, float orbitRadius, float scale, float rotateSpeed);
    
        float lerp(float start, float end, float percent);


		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
