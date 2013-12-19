//
//  Objects.h
//  ED_eindopdracht
//
//  Created by Daan Steegmans on 6/12/13.
//
//

#ifndef __ED_eindopdracht__Objects__
#define __ED_eindopdracht__Objects__

#include "ofMain.h"
#include "Coin.h"
#include "Powerup.h"
#include "Boost.h"
#include "Rock.h"

class Objects
{
    public:
        Objects();
        void update();
        void draw();
        void setDefault();
        void makeCoinGroup(int offsetX);
        void makePowerup(int offsetX);
        void makeBoost(int offsetX);
        void makeRock(int offsetX);
        void makeRockLine();
        void makeSpeedBoostLine();
        int getRockWidth(int randomNum);
        string getRockName(int randomNum);
        float velX;
        float velY;
    
        vector<Coin *> coins;
        int numTotalCoins;
    
        vector<Powerup *> powerups;
        vector<Boost *> boosts;
        vector<Rock *> rocks;
        vector<Rock *> collisionRocks;
    private:
        Coin* coin;
        Powerup* powerup;
        Boost* boost;
        Rock* rock;
};

#endif /* defined(__ED_eindopdracht__Objects__) */
