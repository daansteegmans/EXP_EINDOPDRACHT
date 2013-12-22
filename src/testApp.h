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
        void setUpDefault();

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
        bool startScreenActivated;
        string causeOfGameOver;
    
        bool blinkOn;
        bool startBlinking;
        int numBlinks;
        int timeArduinoInitialized;
    
        ofSoundPlayer bootSound;
        bool bootHasPlayed;
        ofSoundPlayer backgroundMusic;
    
        ofSoundPlayer moveSound;
        ofSoundPlayer moveFastSound;
        ofSoundPlayer moveLeftSound;
        ofSoundPlayer moveRightSound;
    
        ofSoundPlayer coinSound;
        ofSoundPlayer gameOverSound;
        ofSoundPlayer getPowerUpSound;
        ofSoundPlayer activateShieldSound;
        ofSoundPlayer activateBatterySound;
        ofSoundPlayer activateDoubleSound;
        ofSoundPlayer powerUpDeactivateSound;
        ofSoundPlayer errorSound;
        ofSoundPlayer explosionSound;
    
        ofSoundPlayer boostSpeedSound;
        ofSoundPlayer boostFuelSound;
        ofSoundPlayer boostHealthSound;
    
        ofSoundPlayer playerHit1Sound;
        ofSoundPlayer playerHit2Sound;
        ofSoundPlayer playerHit3Sound;
        ofSoundPlayer playerHit4Sound;
        ofSoundPlayer playerHit5Sound;
        ofSoundPlayer playerHit6Sound;
    
        int lastPowerUpActivated;
        int powerUpsMade;
        int timePowerupDisallowed;
        int timeHitRock;
        int numHitRockPlayerBlinks;
        bool updatePowerUpList;
        bool shieldActivated;
        bool batteryActivated;
        bool doubleActivated;
    
        int boostsMade;
        int rocksMade;
        float minNumRocksToMake;
        int speedBoostLinesMade;
        int rockLinesMade;
        int createRockInterval;
        int hitSpeedBoostTime;
};
