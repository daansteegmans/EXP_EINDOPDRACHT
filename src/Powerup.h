//
//  Powerup.h
//  ED_eindopdracht
//
//  Created by Bastiaan Andriessen on 18/12/13.
//
//

#ifndef __ED_eindopdracht__Powerup__
#define __ED_eindopdracht__Powerup__

#include <iostream>
#include "ofMain.h"

class Powerup
{
    public:
        Powerup(string powerupName, float offsetX);
        void update();
        void draw();
    
        ofImage imgBg;
        string name;
    
        float x;
        float velX;
        float y;
        float velY;
    
    private:
};

#endif /* defined(__ED_eindopdracht__Powerup__) */
