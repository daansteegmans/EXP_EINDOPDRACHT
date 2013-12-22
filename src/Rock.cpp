//
//  Rock.cpp
//  ED_eindopdracht
//
//  Created by Bastiaan Andriessen on 19/12/13.
//
//

#include "Rock.h"

Rock::Rock(string rockName, float offsetX, int velX, int offsetY)
{
    name = rockName;
    string imgLocation = "rocks/" + rockName + ".png";
    imgBg.loadImage(imgLocation);
    collisionBg.cropFrom(imgBg, imgBg.width*0.1, imgBg.height*0.1, imgBg.width*0.8, imgBg.height*0.8);
    imgOriginalExplosion.loadImage("rocks/explosionspritesheet.png");
    
    rockAlpha = 1;
    originalVelX = velX;
    x = offsetX;
    y = -imgBg.height - offsetY;
    
    currentExplosionFrame = 0;
}

void Rock::update()
{
    x += (velX + originalVelX);
    y += (velY*1.8);
    
    if(currentExplosionFrame>0){
        if(currentExplosionFrame==1) startExplosionTime = ofGetElapsedTimeMillis();
        if(currentExplosionFrame>6) rockAlpha-=0.1;
        if(currentExplosionFrame < 13){
            if(ofGetElapsedTimeMillis() >= startExplosionTime + 100*(currentExplosionFrame-1)){
                int width = 256;
                currentExplosionFrame++;
                imgExplosion.cropFrom(imgOriginalExplosion, currentExplosionFrame*256, 0, 256, 256);
            }
        }else{
            currentExplosionFrame = 0;
        }
    }
}

void Rock::draw()
{
    if(currentExplosionFrame>0) ofSetColor(255, 255, 255, 255*rockAlpha);
    imgBg.draw(x, y);
    if(currentExplosionFrame>0) imgExplosion.draw((x+imgBg.width/2)-imgExplosion.width/2, (y+imgBg.height/2)-imgExplosion.height/2);
}