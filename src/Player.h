//
//  Player.h
//  ED_eindopdracht
//
//  Created by Daan Steegmans on 22/11/13.
//
//

#ifndef __ED_eindopdracht__Player__
#define __ED_eindopdracht__Player__

#include "ofMain.h"

class Player
{
    public:
        Player();
        void update();
        void draw();
        void move(int dir);
    
        float x;
        float y;
        ofImage img;
        float velX;
        float speed;
        float maxYSpeed;
        float friction;
        float velY;
    
    private:
        ofSoundPlayer soundPlayer;
};

#endif /* defined(__ED_eindopdracht__Player__) */
