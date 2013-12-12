//
//  Oxygen.h
//  ED_eindopdracht
//
//  Created by Daan Steegmans on 22/11/13.
//
//

#ifndef __ED_eindopdracht__Oxygen__
#define __ED_eindopdracht__Oxygen__

#include "ofMain.h"

class Oxygen
{
    public:
    Oxygen(float xPos, float yPos);
        ofImage imgOxygen;
        void update();
        void draw();
        float x;
        float originalX;
        float y;
        float sinIncrement;
        float velY;
    
    private:
        float velX;
        float maxVelX;
        float diffX;
        float maxDiffX;
        bool isVelXSignPositive;
};

#endif /* defined(__ED_eindopdracht__Oxygen__) */
