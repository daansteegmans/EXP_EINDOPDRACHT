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

class Functions
{
    public:
        Functions();
        string checkCollision(Player *objA, Coin *objB);
    
    private:
};

#endif /* defined(__ED_eindopdracht__Functions__) */
