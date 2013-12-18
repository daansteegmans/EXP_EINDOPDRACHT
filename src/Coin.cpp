//
//  Coin.cpp
//  ED_eindopdracht
//
//  Created by Daan Steegmans on 22/11/13.
//
//

#include "Coin.h"

Coin::Coin(float xPos, float yPos, int frame)
{
    name = "coin";
    currentFrame = frame;
    width = 65;

    imgOriginalCoin.loadImage("coin/coin_spritesheet.png");
    imgCurrentCoint.cropFrom(imgOriginalCoin, currentFrame*65, 0, 65, 65);
    
    x = xPos;
    originalX = x;
    y = yPos;
    maxVelX = 1;
    velX = maxVelX;
    shiftingX = 0;
    velY = 1.5;
    maxDiffX = 0.3;
    diffX = maxDiffX;
    isVelXSignPositive = true;
    sinIncrement = 0;
}

void Coin::update()
{
    if(currentFrame < 8){
        currentFrame+=0.3;
    }else{
        currentFrame = 0;
    }
    imgCurrentCoint.cropFrom(imgOriginalCoin, floor(currentFrame)*65, 0, 65, 65);
    imgCurrentCoint.update();
    
    velX-=diffX;
    x+=velX;
    originalX+=shiftingX;
    
    if(velX > -0.09 && velX < 0.09 && velX != 0){
        velX = 0;
    }
    
    if(velX>0){
        if(velX < .5){
            diffX -= 0.05;
            isVelXSignPositive = true;
        } else {
            diffX = -diffX;
        }
    }else if(velX < 0){
        if(velX > -.5){
            diffX += 0.05;
            isVelXSignPositive = false;
        } else {
            if(diffX > 0.1){
                diffX = -diffX;
            }else{
                diffX += 0.05;
            }
        }
    }else{
        if(isVelXSignPositive){
            diffX = 0.1    ;
        }else{
            diffX = -0.1;
        }
        isVelXSignPositive = !isVelXSignPositive;
    }
    
    x = sin(sinIncrement*PI/180)*2;
    y+=velY;
    
    if(x >= 0)
    {
        x = originalX - (x-0) * 30;
    }else{
        x = originalX + (0-x) * 30;
    }
    sinIncrement++;
}

void Coin::draw()
{
    imgCurrentCoint.draw(x, y);
}