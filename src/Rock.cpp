//
//  Rock.cpp
//  ED_eindopdracht
//
//  Created by Bastiaan Andriessen on 19/12/13.
//
//

#include "Rock.h"

Rock::Rock(string rockName, float offsetX, int velX)
{
    name = rockName;
    string imgLocation = "rocks/" + rockName + ".png";
    imgBg.loadImage(imgLocation);
    collisionBg.cropFrom(imgBg, imgBg.width*0.1, imgBg.height*0.1, imgBg.width*0.8, imgBg.height*0.8);
    
    originalVelX = velX;
    x = offsetX;
    y = -imgBg.height;
}

void Rock::update()
{
    x += (velX + originalVelX);
    y += (velY*1.8);
}

void Rock::draw()
{
    imgBg.draw(x, y);
}