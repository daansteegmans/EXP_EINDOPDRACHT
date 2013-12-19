#pragma once

#include "ofMain.h"
#include "Functions.h"
#include "Player.h"
#include "Objects.h"
#include "Backgrounds.h"
#include "Display.h"
#include "Countdown.h"
#include "Menu.h"

#include <string.h>

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void setupArduino(const int & version);
        void startUpBlink();

		void keyPressed(int key);
		void keyReleased(int key);
		
    private:
        ofArduino arduino;
        Functions* functions;
        Player* player;
        Background* background;
        Objects* objects;
        Display* display;
        Countdown* countDown;
        Menu* menu;
        vector<int> keys;
        int timeStarted;
        int startDelay;
        int controlDelay;
        int gameOverTime;
        int coinsGroupsMade;
        string causeOfGameOver;
    
        bool blinkOn;
        bool startBlinking;
        int numBlinks;
        int timeArduinoInitialized;
    
        ofSoundPlayer backgroundMusic;
        bool bgMusicIsPlaying;
        ofSoundPlayer coinSound;
        ofSoundPlayer gameOverSound;
        ofSoundPlayer getPowerUpSound;
        ofSoundPlayer activateShieldSound;
        ofSoundPlayer activateBatterySound;
        ofSoundPlayer activateDoubleSound;
    
        int lastPowerUpActivated;
        int powerUpsMade;
        bool shieldActivated;
        bool batteryActivated;
        bool doubleActivated;
    
        int boostsMade;
};
