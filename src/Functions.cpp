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
    int vX = (objA->x + (objA->img.getWidth()/2)) - (objB->x + (objB->img.getWidth()/2));
    int vY = (objA->y + (objA->img.getHeight()/2)) - (objB->y + (objB->img.getHeight()/2));

    float hWidths = (objA->img.getWidth()/2) + (objB->img.getWidth()/2);
    float hHeights = (objA->img.getHeight()/2) + (objB->img.getHeight()/2);
    string colDir = "";
    
    if(abs(vX) <= hWidths && abs(vY) <= hHeights){
        int oX = hWidths - abs(vX);
        int oY = hHeights - abs(vY);
        
        if(oX >= oY){
            if(vY > 0){
                colDir = "T";
                //objA->y += oY;
            }else{
                colDir = "B";
                //objA->y -= oY;
            }
        }else{
            if(vX > 0){
                colDir = "L";
                //objA->x += oX;
            }else{
                colDir = "R";
                //objA->x -= oX;
            }
        }
        //return [objB, colDir];
        return colDir;
    }
    //return [null, null];
    return "no collision";
}