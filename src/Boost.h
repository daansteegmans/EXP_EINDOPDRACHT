//
//  Boost.h
//  ED_eindopdracht
//
//  Created by Bastiaan Andriessen on 19/12/13.
//
//

#ifndef __ED_eindopdracht__Boost__
#define __ED_eindopdracht__Boost__

#include <iostream>
#include "ofMain.h"

class Boost
{
    public:
        Boost(string boostName, float offsetX);
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

#endif /* defined(__ED_eindopdracht__Boost__) */
