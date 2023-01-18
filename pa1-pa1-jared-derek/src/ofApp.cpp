#include "ofApp.h"
#include <vector>

//--------------------------------------------------------------
void ofApp::setup()
{
    sound.loadSound("Never Gonna Give You Up Original.mp3"); // Loads a sound file (in bin/data/)
    sound.setLoop(true);                                                         // Makes the song loop indefinitely
    sound.setVolume(1);                                                          // Sets the song volume
    ofSetBackgroundColor(0, 0, 0);                                               // Sets the Background Color
}

//--------------------------------------------------------------
void ofApp::update()
{
    /* The update method is called muliple times per second
    It's in charge of updating variables and the logic of our app */
    ofSoundUpdate();               // Updates all sound players
    visualizer.updateAmplitudes(); // Updates Amplitudes for visualizer
    if(replay == true) {
        countdown++;
        if(countdown == 500) {
            currentKey = keyrecording[index];
            keyRecording(currentKey);
            index++;
            countdown = 0;
        }
    }
    if(index == keyrecording.size()) {
        replaystring = " ";
        replay = false;
        index = 0;
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    /* The update method is called muliple times per second
    It's in charge of drawing all figures and text on screen */
    if (!playing)
    {
        ofDrawBitmapString("Press 'a' to play some music!", ofGetWidth() / 2 - 120, ofGetHeight() / 3);
    }
    vector<float> amplitudes = visualizer.getAmplitudes();
    if (mode == '1')
    {
        drawMode1(amplitudes);
    }
    else if (mode == '2')
    {
        drawMode2(amplitudes);
    }
    else if (mode == '3')
    {
        drawMode3(amplitudes);
    }
    else if (mode == '4')
    {
        drawMode4(amplitudes);
    }
}
void ofApp::drawMode1(vector<float> amplitudes)
{
    int v1, v2, v3;
    srand(time(0));
    v1 = rand() % 256 + 1;
    v2 = rand() % 256 + 1;
    v3 = rand() % 256 + 1;
    ofFill();        // Drawn Shapes will be filled in with color
    ofSetColor(256); // This resets the color of the "brush" to white
    if(record == false){
            ofDrawBitmapString("Rectangle Height Visualizer", 0, 15);
        }
        else{
            ofDrawBitmapString("Recording", ofGetWidth()/2 - 50, ofGetHeight()/2);
        }
        if(replay == false){
            ofDrawBitmapString("Rectangle Height Visualizer", 0, 15);
        }
        else{
            ofDrawBitmapString("Replaying", ofGetWidth()/2 - 50, ofGetHeight()/2);
        }
    ofSetColor(v1, v2, v3); // Random colors
    // ofDrawRectangle(2, ofGetHeight() - 100, 50, amplitudes[0]);
    int bars = amplitudes.size();
    int x = 2;
    for (int i = 1; i < bars; i++)
    {
        ofSetColor(v1, v2, v3);
        ofDrawRectangle(x + i, ofGetHeight(), ofGetWidth() / bars, amplitudes[i]*10);
        x += ofGetWidth() / bars;
    }
}
void ofApp::drawMode2(vector<float> amplitudes)
{
    ofSetLineWidth(5); // Sets the line width
    ofNoFill();        // Only the outline of shapes will be drawn
    ofSetColor(256);   // This resets the color of the "brush" to white
    if(record == false){
            ofDrawBitmapString("Circle Visualizer", 0, 15);
        }
        else{
            ofDrawBitmapString("Recording", ofGetWidth()/2 - 50, ofGetHeight()/2);
        }
        if(replay == false){
            ofDrawBitmapString("Circle Visualizer", 0, 15);
        }
        else{
            ofDrawBitmapString("Replaying", ofGetWidth()/2 - 50, ofGetHeight()/2);
        }
    int bands = amplitudes.size();
    for (int i = 0; i < bands; i++)
    {
        ofSetColor((bands - i) * 32 % 256, 18, 144); // Color varies between frequencies
        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, amplitudes[0] / (i + 1));
    }
}

void ofApp::drawMode3(vector<float> amplitudes)
{
    int v1, v2, v3;
    srand(time(0));
    v1 = rand() % 256 + 1; // Random R Values
    v2 = rand() % 256 + 1; // Random G Values
    v3 = rand() % 256 + 1; // Random B Values
    ofFill();        // Drawn Shapes will be filled in with color
    ofSetColor(256); // This resets the color of the "brush" to white
    if(record == false){
            ofDrawBitmapString("Rectangle Width Visualizer", 0, 15);
        }
        else{
            ofDrawBitmapString("Recording", ofGetWidth()/2 - 50, ofGetHeight()/2);
        }
        if(replay == false){
            ofDrawBitmapString("Rectangle Width Visualizer", 0, 15);
        }
        else{
            ofDrawBitmapString("Replaying", ofGetWidth()/2 - 50, ofGetHeight()/2);
        }
    // ofDrawRectangle(2, ofGetHeight() - 100, 50, amplitudes[0]);
    int bars = amplitudes.size();
    int y = 2;
    for (int i = 1; i < bars; i++)
    {
        ofSetColor(v1, v2, v3);
        ofDrawRectangle(ofGetHeight() + 250, y, amplitudes[i]*16, ofGetWidth() / bars);
        y += ofGetWidth() / bars;
    }
}

void ofApp::drawMode4(vector<float> amplitudes)
{
    int v1, v2, v3, v4, v5, v6;
    srand(time(0));
    v1 = rand() % 256 + 1;
    v2 = rand() % 256 + 1;
    v3 = rand() % 256 + 1;
    v4 = rand() % 256 + 1;
    v5 = rand() % 256 + 1;
    v6 = rand() % 256 + 1;
    ofFill();        // Drawn Shapes will be filled in with color
    ofSetColor(256); // This resets the color of the "brush" to white
    if(record == false){
            ofDrawBitmapString("Custom Visualizer", 0, 15);
        }
        else{
            ofDrawBitmapString("Recording", ofGetWidth()/2 - 50, ofGetHeight()/2);
        }
        if(replay == false){
            ofDrawBitmapString("Custom Visualizer", 0, 15);
        }
        else{
            ofDrawBitmapString("Replaying", ofGetWidth()/2 - 50, ofGetHeight()/2);
        }
    int bars = amplitudes.size();
    int x = 2;
    for (int i = 1; i < bars; i++)
    {
        ofSetColor(v1, v2, v3);
        ofDrawRectangle(x + i, ofGetHeight() - 250 - (4 * i), ofGetWidth() / bars, amplitudes[i]*6);
        ofDrawRectangle(x + i, ofGetHeight() - 250 - (4 * i), ofGetWidth() / bars, amplitudes[i]*-6);
        
        x += ofGetWidth() / bars;
    }
    for (int i = 0; i < bars; i++)
    {
        ofSetColor((bars - i) * 32 % v4, v5, v6); // Color varies between frequencies
        ofDrawCircle(ofGetWidth() / 2, ofGetHeight() / 4, amplitudes[0] / (i + 1));
        ofDrawCircle(ofGetWidth() / 2, ofGetHeight() /1.3, amplitudes[0] / (i + 1));
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

    // This method is called automatically when any key is pressed
    if(record == true && key != 'r'){
        keyrecording.push_back(key);
    }

    if(replay == true){
        if(key == 'c' || key == 'C'){
            replaystring = " ";
            replay = false;
            index = 0;
        }
    }
    if(replay == false){
        switch (key)
        {
            case 'a':
                if (playing)
                {
                    sound.stop();
                }
                else
                {
                    sound.play();
                }
                playing = !playing;
                break;
            case '1':
                mode = '1';
                break;
            case '2':
                mode = '2';
                break;
            case '3':
                mode = '3';
                break;
            case '4':
                mode = '4';
                break;
            case '=': // raises the volume
                if (sound.getVolume() < 1)
                {
                    sound.setVolume(sound.getVolume() + 0.1);
                }
                break;
            case '-': // lowers the volume
                if (sound.getVolume() > 0)
                {
                    sound.setVolume(sound.getVolume() - 0.1);
                }
                break;
            case 'd':
                if (sound.loadSound("Never Gonna Give You Up Original.mp3"))
                {
                    sound.loadSound("Justin_Bieber_Lonely.wav");
                    sound.play();
                }
                break;
            case 'f':
                if (sound.loadSound("Justin_Bieber_Lonely.wav"))
                {
                    sound.loadSound("Zzoilo_Aitana_Mon_Amour _Remix.wav");
                    sound.play();
                }
                break;
            case 'g':
                if (sound.loadSound("Zzoilo_Aitana_Mon_Amour _Remix.wav"))
                {
                    sound.loadSound("The_Daily_Life_of_the_Immortal_King_Season_2_Opening.wav");
                    sound.play();
                }
                break;
            case 'h':
                if (sound.loadSound("The_Daily_Life_of_the_Immortal_King_Season_2_Opening.wav"))
                {
                    sound.loadSound("Never Gonna Give You Up Original.mp3");
                    sound.play();
                }
                break;
            }
        if(key == 'r'){
            record = !record;
            if(record == true) {
                keyrecording.clear();
                recordstring = "Recording";
            }
            else
                recordstring = " ";
        }
        if(key == 't'){
            record = false;
            replay = true;
            if(replay == true){
                replaystring = "Replaying";
            }
        }
    }
    
}
//--------------------------------------------------------------
void ofApp::keyRecording(int key)
{
    switch (key)
    {
        case 'a':
            if (playing)
            {
                sound.stop();
            }
            else
            {
                sound.play();
            }
            playing = !playing;
            break;
        case '1':
            mode = '1';
            break;
        case '2':
            mode = '2';
            break;
        case '3':
            mode = '3';
            break;
        case '4':
            mode = '4';
            break;
        case '=': // raises the volume
            if (sound.getVolume() < 1)
            {
                sound.setVolume(sound.getVolume() + 0.1);
            }
            break;
        case '-': // lowers the volume
            if (sound.getVolume() > 0)
            {
                sound.setVolume(sound.getVolume() - 0.1);
            }
            break;
        case 'd':
            if (sound.loadSound("Never Gonna Give You Up Original.mp3"))
            {
                sound.loadSound("Justin_Bieber_Lonely.wav");
                sound.play();
            }
            break;
        case 'f':
            if (sound.loadSound("Justin_Bieber_Lonely.wav"))
            {
                sound.loadSound("Zzoilo_Aitana_Mon_Amour _Remix.wav");
                sound.play();
            }
            break;
        case 'g':
            if (sound.loadSound("Zzoilo_Aitana_Mon_Amour _Remix.wav"))
            {
                sound.loadSound("The_Daily_Life_of_the_Immortal_King_Season_2_Opening.wav");
                sound.play();
            }
            break;
        case 'h':
            if (sound.loadSound("The_Daily_Life_of_the_Immortal_King_Season_2_Opening.wav"))
            {
                sound.loadSound("Never Gonna Give You Up Original.mp3");
                sound.play();
            }
            break;
    
	}
}
//---------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
