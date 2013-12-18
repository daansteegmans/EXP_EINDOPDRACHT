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

class Objects
{
    public:
        Objects();
        void update();
        void draw();
        void setDefault();
        void makeCoinGroup(int offsetX);
        void makePowerup(int offsetX);
        float velX;
        float velY;
    
        vector<Coin *> coins;
        int numTotalCoins;
    
        vector<Powerup *> powerups;
    
    private:
        Coin* coin;
        Powerup* powerup;
    
};

#endif /* defined(__ED_eindopdracht__Objects__) */
