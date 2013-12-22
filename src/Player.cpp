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
    fullImg.loadImage("player/player.png");
    imageWidth = 130;
    numFrames = 5;
    
    powerUpShield.loadImage("player/powerup_shield.png");
    powerUpDouble.loadImage("player/powerup_double.png");
    powerUpBattery.loadImage("player/powerup_battery.png");
    
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
    
    if(y < minY && !gameOver) velY -= 0.1;
    alpha = round(alpha*100)/100;
    
    if(currentSpriteSheetFrame >= numFrames) currentSpriteSheetFrame = 0;
    if(action == "normal_ascend"){
        img.cropFrom(fullImg, floor(currentSpriteSheetFrame)*imageWidth, 0, imageWidth, fullImg.height);
    }else if(action == "boost"){
        img.cropFrom(fullImg, floor(15+currentSpriteSheetFrame)*imageWidth, 0, imageWidth, fullImg.height);
    }else if(action == "left"){
        img.cropFrom(fullImg, floor(10+currentSpriteSheetFrame)*imageWidth, 0, imageWidth, fullImg.height);
    }else if(action == "right"){
        img.cropFrom(fullImg, floor(5+currentSpriteSheetFrame)*imageWidth, 0, imageWidth, fullImg.height);
    }
}

void Player::draw()
{
    x += velX;
    y -= velY;
    ofSetColor(255, 255, 255, 255*(alpha*0.7*powerUpAlpha));
    if(powerUpActivated){
        powerUpBg.draw((x + img.width/2) - powerUpBg.width/2, (y + img.height/2) - powerUpBg.height/2);
        if(powerUpAlpha < 1)powerUpAlpha+=0.03;
    }else{
        if(powerUpAlpha > 0){
            powerUpAlpha-=0.03;
            powerUpBg.draw((x + img.width/2) - powerUpBg.width/2, (y + img.height/2) - powerUpBg.height/2);
        }
    }
    ofSetColor(255, 255, 255, 255*alpha);
    img.draw(x,y);
    
    ofSetColor(255, 255, 255, 255);
}

void Player::setDefault(){
    velX = 0;
    velY = 0;
    friction = .9;
    speed = 2;
    maxYSpeed = 0.6;
    x = ofGetWidth()/2 - imageWidth/ 2;
    y = ofGetHeight() - fullImg.getHeight();
    defaultY = ((ofGetHeight() - fullImg.getHeight()) / 2) + 70;
    gameHasStarted = false;
    gameOver = false;
    minY = ((ofGetHeight() - fullImg.getHeight()) / 2) - 50;
    alpha = 1;
    currentSpriteSheetFrame = 0;
    action = "normal_ascend";
    
    powerUpActivated = false;
    powerUpAlpha = 0;
}
