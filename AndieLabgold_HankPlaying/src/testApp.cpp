#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    recognizer.initRecognizer();
    synthesizer.initSynthesizer("Whisper");
    synthesizer.listVoices();
    synthesizer.getCurrentVoice();
    recognizer.loadDictionaryFromFile("dictionary.txt");
    
    recognizer.startListening();
    ofAddListener(recognizer.speechRecognizedEvent, this, &testApp::speechRecognized);
    hankstill.load("hank.jpg");
    hankvid.load("hanky.mp4");
    hankvid.setLoopState(OF_LOOP_NORMAL);
    hankvid.play();
    
    mySound.load("meow.wav");
    
}

//--------------------------------------------------------------
void testApp::speechRecognized(string & wordRecognized)
{
    synthesizer.speakPhrase(wordRecognized);
    if(wordRecognized == "hank")
    {
        hankvid.setFrame(0);
        mySound.play();

    }

}

//--------------------------------------------------------------
void testApp::update(){

     hankvid.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    hankvid.draw(0,0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key == 'd')
    {
        synthesizer.setDigitByDigit(true);
    }
    
    if(key == 'c')
    {
        synthesizer.setCharacterByCharacter(true);
        synthesizer.setDigitByDigit(false);
    }
    
    if(key == 'n')
    {
        synthesizer.setDigitByDigit(false);
        synthesizer.setCharacterByCharacter(false);
    }
    
    if(key == 'p')
    {
        synthesizer.pauseSpeaking();
    }
    
    if(key == 't')
    {
        synthesizer.continueSpeaking();
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
