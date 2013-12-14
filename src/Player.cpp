//
//  Player.cpp
//  ED_eindopdracht
//
//  Created by Daan Steegmans on 22/11/13.
//
//

#include "Player.h"
#include <string>
#include <iostream>

Player::Player()
{
    img.loadImage("player/player.png");
    
    velX = 0;
    velY = 0;
    friction = .9;
    speed = 2;
    maxYSpeed = 0.6;
    x = ofGetWidth()/2 - img.getWidth()/ 2;
    y = ((ofGetHeight() - img.getHeight()) / 2) + 70;
    
    // move sound
    // soundPlayer.loadSound("sounds/move.mp3");
    // soundPlayer.setLoop(true);
}

void Player::move(int dir)
{    
    switch(dir)
    {
        case 1: // left
            if(velX > -speed){
                velX--;
            }
        break;
            
        case 2: // right
            if(velX < speed){
                velX++;
            }
        break;
            
        case 3: //boost: player goes up
            if(!(y < (ofGetHeight()/2 - img.getHeight()/2))){
                if(velY <= 0){
                    velY = .5;
                }else{
                    if(velY < 3){
                        velY *= 1.2;
                    }
                }
            }else{
                velY *= .95;
            }
        break;
            
        case 4: //boost release: player goes down
            velY = -2;
        break;
    }
    
    //soundPlayer.play();
}

void Player::update()
{
    x += velX;
    if(velY > maxYSpeed){
        velY = maxYSpeed;
    }else if(velY < -maxYSpeed){
        velY = -maxYSpeed;
    }
    y -= velY;
    velX *= friction;
    if(velY > 0){
        velY *= friction;
    }
}

void Player::draw()
{
    //check if player is going down or player is above center
    /*if(y > ofGetHeight() - img.getHeight() - 10){
        y = ofGetHeight() - img.getHeight() - 10;
        velY = 0;
    }*/
    
    /*ofPushMatrix();
    ofTranslate(img.width/2, img.height/2, 0);//move pivot to centre
    ofRotate(ofGetFrameNum() * 10, 0, 0, 1);//rotate from centre
    ofPushMatrix();
    img.draw(-img.width/2,-img.height/2);//move back by the centre offset
    ofPopMatrix();
    ofPopMatrix();*/
    
    x += velX;
    y -= velY;
    img.draw(x,y);
}
