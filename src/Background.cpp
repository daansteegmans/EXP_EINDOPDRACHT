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
    img2.loadImage("background/space2.jpg");
    
    maxSpeedY = 5;
    manoeuvreSpeedY = 3;
    minSpeedY = 1;
    boostSpeedY = 0;
    
    Background::setDefault();
    y = -img.getHeight()*2 + 3*ofGetHeight();
}

void Background::setDefault(){
    x = -(img.getWidth() - ofGetWidth())/2;
    y = -img.getHeight()*2 + ofGetHeight();
    
    speedX = 0;
    speedY = minSpeedY;
    drawImage2 = false;
}

void Background::update()
{
    if(boostSpeedY == 0){
        if(speedY > maxSpeedY){
            speedY = maxSpeedY;
        } else if(speedY < minSpeedY){
            speedY = minSpeedY;
        }
    }else{
        if(speedY > boostSpeedY){
            speedY = boostSpeedY;
        } else if(speedY < minSpeedY){
            speedY = minSpeedY;
        }
    }
    
    x += speedX;
    y += speedY;
    y = round(y);
    
    if(y+img.getHeight() >= -0.1){
        drawImage2 = true;
    }
}

void Background::draw()
{
    img.draw(x,y+img.getHeight());
    if(drawImage2){
       img2.draw(x,y);
    }
}