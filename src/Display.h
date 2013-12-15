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

        ofImage topBg;
        ofImage topBgBorder;
        ofImage bottomBg;
    
        ofImage iconAltitude;
        ofImage iconSpeed;
        ofImage iconTime;
        ofImage iconTemperature;
        ofImage iconCoins;
    
        float altitude;
        int speed;
        int defaultSpeed;
        int time;
        int temperature;
        int coins;
    
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
    private:
        ofTrueTypeFont *font;
        int fillTotalWidth;
        int fillTotalHeight;
    
};

#endif /* defined(__ED_eindopdracht__Display__) */
