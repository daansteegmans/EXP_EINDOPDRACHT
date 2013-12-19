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
        Rock(string rockName, float offsetX, int velX);
        void update();
        void draw();
    
        ofImage imgBg;
        ofImage collisionBg;
        string name;
    
        float x;
        float velX;
        float originalVelX;
        float y;
        float velY;
    
    private:
};
    
#endif /* defined(__ED_eindopdracht__Rock__) */