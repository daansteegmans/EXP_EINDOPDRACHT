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
        void setDefault();
    
        float x;
        float y;
        float defaultY;
        float minY;
        float velX;
        float speed;
        float maxYSpeed;
        float friction;
        float velY;
        bool gameHasStarted;
        bool gameOver;
        float alpha;
    
        float powerUpAlpha;
        bool powerUpActivated;
        ofImage powerUpShield;
        ofImage powerUpDouble;
        ofImage powerUpBattery;
        ofImage powerUpBg;
    
        ofImage fullImg;
        ofImage img;
        int imageWidth;
        float currentSpriteSheetFrame;
        int numFrames;
    
        string action;
    
    private:
        ofSoundPlayer soundPlayer;
};

#endif /* defined(__ED_eindopdracht__Player__) */
