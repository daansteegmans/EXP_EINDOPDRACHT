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
    ofSetColor(255, 255, 255, 255*alpha);
    
    x += velX;
    y -= velY;
    img.draw(x,y);
    
    /*ofPushMatrix();
        ofTranslate(img.width/2, img.height/2, 0);//move pivot to centre
        ofRotate(ofGetFrameNum() * .1, 0, 0, 1);//rotate from centre
        ofPushMatrix();
            img.draw(x + -img.width/2, y + -img.height/2);//move back by the centre offset
        ofPopMatrix();
    ofPopMatrix();*/
    
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
    
    // move sound
    // soundPlayer.loadSound("sounds/move.mp3");
    // soundPlayer.setLoop(true);
}
