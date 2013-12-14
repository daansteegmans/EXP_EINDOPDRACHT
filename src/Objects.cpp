//
//  Objects.cpp
//  ED_eindopdracht
//
//  Created by Daan Steegmans on 6/12/13.
//
//

#include "Objects.h"

Objects::Objects()
{
    velX = 0;
    velY = 1.5;
    int coinTotalFrames = 8;
    
    for(int i=0; i<10; i++)
    {
        int startFrame = i*2;
        if(startFrame >= coinTotalFrames){
            int multiplier = round(startFrame/coinTotalFrames);
            startFrame -= (coinTotalFrames*multiplier);
        }
        coin = new Coin(0, 0, startFrame);
        
        coin->x = sin((i*4)*PI/180)*2;
        coin->y = i*50 - 10*50;
        coin->sinIncrement = i*50;
        
        if(coin->x >= 0){
            coin->x = (ofGetWidth()/2 - coin->img.width/2) - (coin->x-0) * 30 + 350;
        }else{
            coin->x = (ofGetWidth()/2 - coin->img.width/2) + (0-coin->x) * 30 + 350;
        }
        
        coin->originalX = coin->x;
        coins.push_back(coin);
    };
}

void Objects::update()
{
    for(int i=0; i<coins.size(); i++){
        coins[i]->shiftingX = velX;
        coins[i]->velY = velY;
        coins[i]->update();
    }
}

void Objects::draw()
{
    for(int i=0; i<coins.size(); i++){
        coins[i]->draw();
    }
}