//
//  Background.cpp
//  ED_eindopdracht
//
//  Created by Daan Steegmans on 2/12/13.
//
//

#include "Background.h"

Background::Background()
{    
    img.loadImage("background/space.jpg");
    
    x = -(img.getWidth() - ofGetWidth())/2;
    y = -img.getHeight() + ofGetHeight();
    
    maxSpeedY = 5;
    minSpeedY = 1;
    speedX = 0;
    speedY = minSpeedY;
}

void Background::update()
{
    if(speedY > maxSpeedY){
        speedY = maxSpeedY;
    } else if(speedY < minSpeedY){
        speedY = minSpeedY;
    }
    
    x += speedX;
    y += speedY;
}

void Background::draw()
{
    img.draw(x,y);
}