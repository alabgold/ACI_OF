#pragma once

#include "ofMain.h"
#include "ofxSpeech.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void speechRecognized(string & wordRecognized);
    
        ofxSpeechRecognizer         recognizer;
        ofxSpeechSynthesizer        synthesizer;
        vector<string>              words;
        bool                        redBackground;
        ofVideoPlayer		hankvid;
    ofImage hankstill;
    ofSoundPlayer   mySound;
    //Sound from https://freesound.org/people/tuberatanka/sounds/110011/
};
