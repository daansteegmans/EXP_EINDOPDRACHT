//
//  Wall.cpp
//  ED_eindopdracht
//
//  Created by Daan Steegmans on 22/11/13.
//
//

#include "Wall.h"

Wall::Wall(string side, int yPos)
{    
    img.loadImage("walls/wall.jpg");
    
    x = side == "left"? 0 : ofGetWidth() - img.getWidth();
    y = yPos - img.getHeight();
    speed = 0;
    velY = 0;
}

void Wall::update()
{    
    y += velY > speed? speed : velY;
}

void Wall::draw()
{    
    img.draw(x,y);
}