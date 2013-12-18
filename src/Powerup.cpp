//
//  Powerup.cpp
//  ED_eindopdracht
//
//  Created by Bastiaan Andriessen on 18/12/13.
//
//

#include "Powerup.h"

Powerup::Powerup(string powerupName, float offsetX)
{
    name = powerupName;
    string imgLocation = "powerups/" + powerupName + ".png";
    imgBg.loadImage(imgLocation);
    
    x = offsetX;
    y = -imgBg.height;
}

void Powerup::update()
{
    x += velX;
    y += velY;
}

void Powerup::draw()
{
    imgBg.draw(x, y);
}