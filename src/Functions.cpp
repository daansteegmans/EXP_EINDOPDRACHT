//
//  Functions.cpp
//  ED_eindopdracht
//
//  Created by Daan Steegmans on 22/11/13.
//
//

#include "Functions.h"

Functions::Functions()
{}

string Functions::checkCollision(Player *objA, Coin *objB)
{
    int vX = (objA->x + (objA->img.getWidth()/2)) - (objB->x + (objB->width/2));
    int vY = (objA->y + (objA->img.getHeight()/2)) - (objB->y + (objB->width/2));

    float hWidths = (objA->img.getWidth()/2) + (objB->width/2);
    float hHeights = (objA->img.getHeight()/2) + (objB->width/2);
    string colDir = "";
    
    if(abs(vX) <= hWidths && abs(vY) <= hHeights){
        int oX = hWidths - abs(vX);
        int oY = hHeights - abs(vY);
        
        if(oX >= oY){
            if(vY > 0){
                colDir = "T";
            }else{
                colDir = "B";
            }
        }else{
            if(vX > 0){
                colDir = "L";
            }else{
                colDir = "R";
            }
        }
        return colDir;
    }
    return "no collision";
}

string Functions::checkCollisionPowerup(Player *objA, Powerup *objB)
{
    int vX = (objA->x + (objA->img.getWidth()/2)) - (objB->x + (objB->imgBg.width/2));
    int vY = (objA->y + (objA->img.getHeight()/2)) - (objB->y + (objB->imgBg.width/2));
    
    float hWidths = (objA->img.getWidth()/2) + (objB->imgBg.width/2);
    float hHeights = (objA->img.getHeight()/2) + (objB->imgBg.width/2);
    string colDir = "";
    
    if(abs(vX) <= hWidths && abs(vY) <= hHeights){
        int oX = hWidths - abs(vX);
        int oY = hHeights - abs(vY);
        
        if(oX >= oY){
            if(vY > 0){
                colDir = "T";
            }else{
                colDir = "B";
            }
        }else{
            if(vX > 0){
                colDir = "L";
            }else{
                colDir = "R";
            }
        }
        return colDir;
    }
    return "no collision";
}