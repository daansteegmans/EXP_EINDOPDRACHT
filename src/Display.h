//
//  Display.h
//  ED_eindopdracht
//
//  Created by Bastiaan Andriessen on 13/12/13.
//
//

#ifndef __ED_eindopdracht__Display__
#define __ED_eindopdracht__Display__

#include "ofMain.h"

class Display
{
    public:
        Display();
        void update();
        void draw();
        void setDefault();
        void startAlarm();

        ofImage topBg;
        ofImage bottomBg;
    
        ofImage fuelBorderNormal;
        ofImage fuelBorderHightlight;
        ofImage fuelBorderShown;
    
        ofImage fuelImageNormal;
        ofImage fuelImageHighlight;
        ofImage fuelImageShown;
        int fuelStartedBlinkingTime;
        int numFuelBlinks;
        string currentShownFuel;
    
        ofImage healthBorderNormal;
        ofImage healthBorderHightlight;
        ofImage healthBorderShown;
    
        ofImage healthImageNormal;
        ofImage healthImageHighlight;
        ofImage healthImageShown;
        int healthStartedBlinkingTime;
        int numHealthBlinks;
        string currentShownHealth;
    
        ofImage iconAltitude;
        ofImage iconSpeed;
        ofImage iconTime;
        ofImage iconTemperature;
        ofImage iconCoins;
    
        ofImage iconPowerUpShield;
        ofImage iconPowerUpBattery;
        ofImage iconPowerUpDouble;
    
        ofImage iconEmpty1;
        ofImage iconEmpty2;
        ofImage iconEmpty3;
    
        ofImage iconPowerUp1Shown;
        ofImage iconPowerUp2Shown;
        ofImage iconPowerUp3Shown;
    
        int iconPowerUp1OffsetY;
        int iconPowerUp2OffsetY;
        int iconPowerUp3OffsetY;
    
        string powerUp1Text;
        string powerUp2Text;
        string powerUp3Text;
    
        vector<string> powerupNames;
        int maxPowerups;
    
        float altitude;
        float speed;
        int defaultSpeed;
        int time;
        float temperature;
        int minTemperature;
        int coins;
        int maxSpeed;
    
        ofImage fuelOriginalFill;
        ofImage fuelCurrentFill;
        float fuel;
    
        ofImage healthOriginalFill;
        ofImage healthCurrentFill;
        float health;
    
        float topY;
        float bottomY;
        int topDefaultY;
        int bottomDefaultY;
        float alpha;
        ofSoundPlayer alarmSound;
    
    private:
        ofTrueTypeFont *font;
        ofTrueTypeFont *font2;
        int fillTotalWidth;
        int fillTotalHeight;
    
        bool isAlarmPlaying;
    
};

#endif /* defined(__ED_eindopdracht__Display__) */
