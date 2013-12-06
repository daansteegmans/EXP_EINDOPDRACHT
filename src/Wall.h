//
//  Wall.h
//  ED_eindopdracht
//
//  Created by Daan Steegmans on 22/11/13.
//
//

#ifndef __ED_eindopdracht__Wall__
#define __ED_eindopdracht__Wall__

#include "ofMain.h"

class Wall
{
    public:
        Wall(string side,int yPos);
        void update();
        void draw();
        void move();
    
        float x;
        float y;
        float friction;
        float velY;
        float speed;
        ofImage img;
    
    private:
        string _side;
};

#endif /* defined(__ED_eindopdracht__Wall__) */
