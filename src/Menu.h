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
        Menu(bool gameOver, string causeOfGameOver);
        void update();
        void draw();
    
    
    private:
        ofTrueTypeFont* font;
        bool isGameOver;
        string cause;
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
    
    
};


#endif /* defined(__ED_eindopdracht__Menu__) */
