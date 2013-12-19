//
//  Functions.h
//  ED_eindopdracht
//
//  Created by Daan Steegmans on 22/11/13.
//
//

#ifndef __ED_eindopdracht__Functions__
#define __ED_eindopdracht__Functions__

#include "Player.h"
#include "Coin.h"
#include "Powerup.h"
#include "Boost.h"
#include "Rock.h"

class Functions
{
    public:
        Functions();
        string checkCollision(Player *objA, Coin *objB);
        string checkCollisionPowerup(Player *objA, Powerup *objB);
        string checkCollisionBoost(Player *objA, Boost *objB);
        string checkCollisionRock(Player *objA, Rock *objB);
    private:
};

#endif /* defined(__ED_eindopdracht__Functions__) */
