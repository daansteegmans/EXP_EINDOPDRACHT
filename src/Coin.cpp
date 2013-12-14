//
//  Coin.cpp
//  ED_eindopdracht
//
//  Created by Daan Steegmans on 22/11/13.
//
//

#include "Coin.h"

Coin::Coin(float xPos, float yPos, int startFrame)
{
    imgCoin.setFrame(startFrame);
    imgCoin.loadMovie("coin/coin.gif");
    imgCoin.play();
    
    x = xPos;
    originalX = x;
    y = yPos;
    maxVelX = 1;
    velX = maxVelX;
    velY = 1.5;
    maxDiffX = 0.3;
    diffX = maxDiffX;
    isVelXSignPositive = true;
    sinIncrement = 0;
}

void Coin::update()
{
    imgCoin.update();
    
    velX-=diffX;
    x+=velX;
    
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
    
    //cout << "velY bubble: " << velY << endl;
}

void Coin::draw()
{
    //imgOxygen.draw(x,y);
    imgCoin.draw(x, y);
}