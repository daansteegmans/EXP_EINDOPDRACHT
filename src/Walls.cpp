//
//  Walls.cpp
//  ED_eindopdracht
//
//  Created by Daan Steegmans on 22/11/13.
//
//

#include "Walls.h"
#include "Wall.h"

Walls::Walls()
{
    walls.push_back(new Wall("left",0));
    walls.push_back(new Wall("right",0));
    
    x = 0;
    y = 0;
}

void Walls::move()
{
    for(int i=0; i<walls.size(); i++){
        walls[i]->speed = 3;
        walls[i]->velY += .5;
    }
}

void Walls::moveFast()
{
    for(int i=0; i<walls.size(); i++){
        walls[i]->speed = 6;
        walls[i]->velY += .5;
    }
}

void Walls::update()
{
    // if last wall has reached top => new wall    
    if(walls[walls.size()-1]->y >= -20)
    {
        int newWallY = -walls[walls.size()-1]->y;
        walls.push_back(new Wall("left", newWallY));
        walls.push_back(new Wall("right", newWallY));
    }
    
    // remove walls that are out of sight
    if(walls[0]->y > ofGetHeight()){
        walls.erase(walls.begin());
    }
    
    for(int i=0; i<walls.size(); i++){
        walls[i]->update();
    }
}

void Walls::draw()
{
    for(int i=0; i<walls.size(); i++){
        walls[i]->draw();
    }
}