//
//  Walls.h
//  ED_eindopdracht
//
//  Created by Daan Steegmans on 22/11/13.
//
//

#ifndef __ED_eindopdracht__Walls__
#define __ED_eindopdracht__Walls__

#include "ofMain.h"
#include "Wall.h"

class Walls
{
    public:
        Walls();
        void update();
        void draw();
        void move();
        void moveFast();
    
        vector<Wall *> walls;
    
    private:
        int x;
        int y;
};

#endif /* defined(__ED_eindopdracht__Walls__) */
