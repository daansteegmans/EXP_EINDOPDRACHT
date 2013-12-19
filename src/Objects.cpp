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
    rocks.clear();
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
    int random = rand() % 7;
    if(random == 0){
        boost = new Boost("speed", offsetX);
    }else if(random == 1 || random == 2 || random == 3 || random == 4){
        boost = new Boost("fuel", offsetX);
    }else if(random == 5 || random == 6){
        boost = new Boost("heart", offsetX);
    }
    boosts.push_back(boost);
}

void Objects::makeSpeedBoostLine(){
    int speedBoostWidth = 100;
    int numSpeedBoosts = (floor(ofGetWidth()/speedBoostWidth)+1)*3;
    int xPos = -((numSpeedBoosts/3)*100);
    for(int i=0; i<numSpeedBoosts; i++){
        boost = new Boost("speed", xPos);
        boosts.push_back(boost);
        xPos+=speedBoostWidth;
    }
}

void Objects::makeRock(int offsetX){
    int random = rand() % 4;
    int speedX = rand() % 4;
    if(offsetX > ofGetWidth()/2){
        speedX*=-1;
    }
    if(random == 0 || random == 1){
        rock = new Rock("rock_small", offsetX, speedX);
    }else if(random == 2 || random == 3){
        rock = new Rock("rock_medium", offsetX, speedX);
    }else if(random == 4){
        rock = new Rock("rock_large", offsetX, speedX);
    }
    rocks.push_back(rock);
    collisionRocks.push_back(rock);
}

void Objects::makeRockLine(){
    cout << "makeRockLine" << endl;
    int numRocks = floor(ofGetWidth()/300)*3;
    int posX = -((numRocks/3)*300);
    for(int i = 0; i<numRocks; i++){
        int random = rand() % 3;
        int width = getRockWidth(random);
        string name = getRockName(random);
        rock = new Rock(name, posX, 0);
        rocks.push_back(rock);
        collisionRocks.push_back(rock);
        posX+=300;
    }
}

int Objects::getRockWidth(int randomNum){
    int rockWidth;
    if(randomNum == 0){
        rockWidth = 129;
    }else if(randomNum == 1){
        rockWidth = 201;
    }else if(randomNum == 2){
        rockWidth = 183;
    }
    return rockWidth;
}

string Objects::getRockName(int randomNum){
    string rockName;
    if(randomNum == 0){
        rockName = "rock_small";
    }else if(randomNum == 1){
        rockName = "rock_medium";
    }else if(randomNum == 2){
        rockName = "rock_large";
    }
    return rockName;
}

void Objects::update()
{
    vector<Boost *> updatedBoosts;
    for(int k=0; k<boosts.size(); k++){
        if(boosts[k]->y <= ofGetHeight()){
            updatedBoosts.push_back(boosts[k]);
        }
        boosts[k]->velX = velX;
        boosts[k]->velY = velY;
        boosts[k]->update();
    }
    boosts = updatedBoosts;
    
    vector<Coin *> updatedCoins;
    for(int i=0; i<coins.size(); i++){
        if(coins[i]->y <= ofGetHeight()){
            updatedCoins.push_back(coins[i]);
        }
        coins[i]->shiftingX = velX;
        coins[i]->velY = velY;
        
        coins[i]->update();
    }
    coins = updatedCoins;
    
    vector<Powerup *> updatedPowerups;
    for(int j=0; j<powerups.size(); j++){
        if(powerups[j]->y <= ofGetHeight()){
            updatedPowerups.push_back(powerups[j]);
        }
        powerups[j]->velX = velX;
        powerups[j]->velY = velY;
        powerups[j]->update();
    }
    powerups = updatedPowerups;
    
    vector<Rock *> updatedRocks;
    for(int l=0; l<rocks.size(); l++){
        if(rocks[l]->y <= ofGetHeight()){
            updatedRocks.push_back(rocks[l]);
        }
        rocks[l]->velX = velX;
        rocks[l]->velY = velY;
        rocks[l]->update();
    }
    rocks = updatedRocks;
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
    
    for(int l=0; l<rocks.size(); l++){
        rocks[l]->draw();
    }
}