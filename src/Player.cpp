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

void Player::update()
{
    x += velX;
    if(velY > maxYSpeed){
        velY = maxYSpeed;
    }else if(velY < -(maxYSpeed*1.6)){
        velY = -(maxYSpeed*1.6);
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
