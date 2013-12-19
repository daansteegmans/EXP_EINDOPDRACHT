//
//  Background.h
//  ED_eindopdracht
//
//  Created by Daan Steegmans on 2/12/13.
//
//

#ifndef __ED_eindopdracht__Background__
#define __ED_eindopdracht__Background__

#include "ofMain.h"

class Background
{
    public:
        Background();
        void update();
        void draw();
        void setDefault();
    
        float x;
        float y;
        float speedY;
        float speedX;
        int maxSpeedY;
        int manoeuvreSpeedY;
        int boostSpeedY;
        int minSpeedY;
        ofImage img;
        ofImage img2;
        bool drawImage2;
    
    private:
        
};

#endif /* defined(__ED_eindopdracht__Background__) */
