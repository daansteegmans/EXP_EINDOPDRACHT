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
    Objects::setDefault();
}

void Objects::setDefault(){
    velX = 0;
    velY = 1.5;
    numTotalCoins = 0;
    coins.clear();
    powerups.clear();
    boosts.clear();
}

void Objects::makeCoinGroup(int offsetX){
    int coinTotalFrames = 8;
    
    for(int i=0; i<10; i++)
    {
        int startFrame = i;
        if(startFrame >= coinTotalFrames){
            int multiplier = round(startFrame/coinTotalFrames);
            startFrame -= (coinTotalFrames*multiplier);
        }
        coin = new Coin(0, 0, startFrame);
        
        coin->x = sin((i*4)*PI/180)*2;
        coin->y = i*50 - 600;
        coin->sinIncrement = i*50;
        
        if(coin->x >= 0){
            coin->x = (ofGetWidth()/2 - coin->width/2) - (coin->x-0) * 30 + offsetX;
        }else{
            coin->x = (ofGetWidth()/2 - coin->width/2) + (0-coin->x) * 30 + offsetX;
        }
        
        coin->originalX = coin->x;
        coins.push_back(coin);
        numTotalCoins++;
    };
}

void Objects::makePowerup(int offsetX){
    int random = rand() % 3;
    if(random == 0){
        powerup = new Powerup("battery", offsetX);
    }else if(random == 1){
        powerup = new Powerup("double", offsetX);
    }else if(random == 2){
        powerup = new Powerup("shield", offsetX);
    }
    powerups.push_back(powerup);
}

void Objects::makeBoost(int offsetX){
    int random = rand() % 2;
    if(random == 0){
        boost = new Boost("speed", offsetX);
    }else if(random == 1){
        boost = new Boost("fuel", offsetX);
    }/*else if(random == 2){
        boost = new Boost("heart", offsetX);
    }*/
    boosts.push_back(boost);
}

void Objects::update()
{
    for(int i=0; i<coins.size(); i++){
        coins[i]->shiftingX = velX;
        coins[i]->velY = velY;
        coins[i]->update();
    }
    
    for(int j=0; j<powerups.size(); j++){
        powerups[j]->velX = velX;
        powerups[j]->velY = velY;
        powerups[j]->update();
    }
    
    for(int k=0; k<boosts.size(); k++){
        boosts[k]->velX = velX;
        boosts[k]->velY = velY;
        boosts[k]->update();
    }
}

void Objects::draw()
{
    for(int i=0; i<coins.size(); i++){
        coins[i]->draw();
    }
    
    for(int j=0; j<powerups.size(); j++){
        powerups[j]->draw();
    }
    
    for(int k=0; k<boosts.size(); k++){
        boosts[k]->draw();
    }
}