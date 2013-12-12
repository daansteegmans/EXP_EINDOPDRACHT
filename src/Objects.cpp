//
//  Objects.cpp
//  ED_eindopdracht
//
//  Created by Daan Steegmans on 6/12/13.
//
//

#include "Objects.h"

Objects::Objects()
{
    velY = 1.5;
    
    for(int i=0; i<10; i++)
    {
        oxygen = new Oxygen(0, 0);
        
        oxygen->x = sin((i*4)*PI/180)*2;
        oxygen->y = i*50;
        oxygen->sinIncrement = i*50;
        
        if(oxygen->x >= 0){
            oxygen->x = (ofGetWidth()/2 - oxygen->imgOxygen.width/2) - (oxygen->x-0) * 30;
        }else{
            oxygen->x = (ofGetWidth()/2 - oxygen->imgOxygen.width/2) + (0-oxygen->x) * 30;
        }
        
        oxygen->originalX = oxygen->x;
        oxygenBubbles.push_back(oxygen);
    };
}

void Objects::update()
{
    for(int i=0; i<oxygenBubbles.size(); i++){
        oxygenBubbles[i]->velY = velY;
        oxygenBubbles[i]->update();
    }
}

void Objects::draw()
{
    for(int i=0; i<oxygenBubbles.size(); i++){
        oxygenBubbles[i]->draw();
    }
}