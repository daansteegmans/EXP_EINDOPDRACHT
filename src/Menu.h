//
//  Menu.h
//  ED_eindopdracht
//
//  Created by Bastiaan Andriessen on 15/12/13.
//
//

#ifndef __ED_eindopdracht__Menu__
#define __ED_eindopdracht__Menu__

#include "ofMain.h"

class Menu
{
    public:
        Menu(bool gameOver, string causeOfGameOver, int displayHeight, int displayMaxSpeed, int displayTime, int displayCoins);
        void update();
        void draw();
        float alpha;
    
    private:
        ofTrueTypeFont* font;
        bool isGameOver;
        string cause;
    
        int height;
        int currentDisplayedHeight;
        int speed;
        int currentDisplayedSpeed;
        int time;
        int currentDisplayedTime;
        int coins;
        int currentDisplayedCoins;
    
        ofImage imgTitle;
    
        ofImage imgMessageBg;
        ofImage iconMessageNoFuel;
        ofImage iconMessageNoHealth;
    
        ofImage imgStatsBg;
        ofImage iconHeight;
        ofImage iconSpeed;
        ofImage iconTime;
        ofImage iconCoins;
    
        ofImage imgReplayBg;
        ofImage imgButton1;
        ofImage imgButton2;
        ofImage imgButton3;
};


#endif /* defined(__ED_eindopdracht__Menu__) */
