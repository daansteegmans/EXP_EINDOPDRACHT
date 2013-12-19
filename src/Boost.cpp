//
//  Boost.cpp
//  ED_eindopdracht
//
//  Created by Bastiaan Andriessen on 19/12/13.
//
//

#include "Boost.h"

Boost::Boost(string boostName, float offsetX)
{
    name = boostName;
    string imgLocation = "boosts/" + boostName + ".png";
    imgBg.loadImage(imgLocation);
    
    x = offsetX;
    y = -imgBg.height;
}

void Boost::update()
{
    x += velX;
    y += velY;
}

void Boost::draw()
{
    imgBg.draw(x, y);
}