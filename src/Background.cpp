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
    
    speedX = 0;
    speedY = 1;
}

void Background::update()
{
    x += speedX;
    y += speedY;
}

void Background::draw()
{
    img.draw(x,y);
}