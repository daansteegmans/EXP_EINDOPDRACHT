//
//  Coin.h
//  ED_eindopdracht
//
//  Created by Daan Steegmans on 22/11/13.
//
//

#ifndef __ED_eindopdracht__Coin__
#define __ED_eindopdracht__Coin__

#include "ofMain.h"

class Coin
{
    public:
        Coin(float xPos, float yPos, int startFrame);
        ofVideoPlayer img;
        void update();
        void draw();
        float x;
        float originalX;
        float y;
        float sinIncrement;
        float velY;
        float velX;
        float shiftingX; //totale verplaatsing (other than sinus animation)
        string name;
    
    private:
        float maxVelX;
        float diffX;
        float maxDiffX;
        bool isVelXSignPositive;
};

#endif /* defined(__ED_eindopdracht__Coin__) */
