//
//  Menu.cpp
//  ED_eindopdracht
//
//  Created by Bastiaan Andriessen on 15/12/13.
//
//

#include "Menu.h"

Menu::Menu()
{
    img.loadImage("background/space.jpg");
    
    x = ofGetWidth()/2 - img.width/2;
    y = ofGetHeight()/2 - img.height/2;
}

void Menu::update()
{
    
}

void Menu::draw()
{
    img.draw(x,y);
}