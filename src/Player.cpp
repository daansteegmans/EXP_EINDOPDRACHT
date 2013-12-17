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
    img.loadImage("player/player2.png");
    
    Player::setDefault();
}

void Player::update()
{
    x += velX;
    if(gameHasStarted && !gameOver){
        if(velY > maxYSpeed){
            velY = maxYSpeed;
        }else if(velY < -(maxYSpeed*1.6)){
            velY = -(maxYSpeed*1.6);
        }
    }
    y -= velY;
    velX *= friction;
    if(velY > 0 && gameHasStarted && !gameOver){
        velY *= friction;
    }
    velY = round(velY*100)/100;
    
    if(gameOver){
        if(velY < 6)velY += 0.1;
    }
}

void Player::draw()
{
    //check if player is going down or player is above center
    /*if(y > ofGetHeight() - img.getHeight() - 10){
        y = ofGetHeight() - img.getHeight() - 10;
        velY = 0;
    }*/
    
    x += velX;
    y -= velY;
    img.draw(x,y);
}

void Player::setDefault(){
    velX = 0;
    velY = 0;
    friction = .9;
    speed = 2;
    maxYSpeed = 0.6;
    x = ofGetWidth()/2 - img.getWidth()/ 2;
    y = ofGetHeight() - img.getHeight();
    defaultY = ((ofGetHeight() - img.getHeight()) / 2) + 70;
    gameHasStarted = false;
    gameOver = false;
    
    // move sound
    // soundPlayer.loadSound("sounds/move.mp3");
    // soundPlayer.setLoop(true);
}
