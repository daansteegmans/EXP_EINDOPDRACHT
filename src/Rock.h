//
//  Rock.h
//  ED_eindopdracht
//
//  Created by Bastiaan Andriessen on 19/12/13.
//
//

#ifndef __ED_eindopdracht__Rock__
#define __ED_eindopdracht__Rock__

#include <iostream>
#include "ofMain.h"

class Rock
{
    public:
        Rock(string rockName, float offsetX, int velX, int offsetY);
        void update();
        void draw();
    
        float rockAlpha;
        ofImage imgBg;
        ofImage collisionBg;
        ofImage imgOriginalExplosion;
        ofImage imgExplosion;
        int currentExplosionFrame;
        int startExplosionTime;
    
        string name;
    
        float x;
        float velX;
        float originalVelX;
        float y;
        float velY;
    
    private:
};
    
#endif /* defined(__ED_eindopdracht__Rock__) */