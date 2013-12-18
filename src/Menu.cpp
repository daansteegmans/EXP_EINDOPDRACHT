//
//  Menu.cpp
//  ED_eindopdracht
//
//  Created by Bastiaan Andriessen on 15/12/13.
//
//

#include "Menu.h"

Menu::Menu(bool gameOver, string causeOfGameOver, int displayHeight, int displayMaxSpeed, int displayTime, int displayCoins, int displayTotalCoins)
{
    isGameOver = gameOver;
    cause = causeOfGameOver;
    alpha = 0;
    
    height = displayHeight;
    currentDisplayedHeight = 0;
    
    speed = displayMaxSpeed;
    currentDisplayedSpeed = 0;
    
    time = displayTime;
    currentDisplayedTime = 0;
    
    coins = displayCoins;
    currentDisplayedCoins = 0;
    totalCoins = displayTotalCoins;
    
    totalScore = height*2 + speed*2 + time/100 + coins*200;
    currentDisplayedScore = 0;
    
    font = new ofTrueTypeFont();
    font->loadFont("fonts/Piston_Pressure.otf", 16);
    font2 = new ofTrueTypeFont();
    font2->loadFont("fonts/Piston_Pressure.otf", 28);
    
    if(isGameOver){
        imgTitle.loadImage("menu/gameover.png");
        imgMessageBg.loadImage("menu/window_msg.png");
        imgStatsBg.loadImage("menu/window_stats.png");
        imgReplayBg.loadImage("menu/window_replay.png");
        
        iconMessageNoFuel.loadImage("menu/no_fuel.png");
        iconMessageNoHealth.loadImage("menu/no_health.png");
        
        iconHeight.loadImage("menu/icons/icon_height.png");
        iconSpeed.loadImage("menu/icons/icon_speed.png");
        iconTime.loadImage("menu/icons/icon_time.png");
        iconCoins.loadImage("menu/icons/icon_coins.png");
        
        imgButton1.loadImage("menu/buttons/btn_red_left.png");
        imgButton2.loadImage("menu/buttons/btn_red_right.png");
        imgButton3.loadImage("menu/buttons/btn_green.png");
    }
}

void Menu::update()
{
    alpha = round(alpha*100)/100;
    
    int diff;
    int plus;
    
    if(totalScore != currentDisplayedScore){
        diff = abs(totalScore - currentDisplayedScore);
        plus = diff>1000000? 250000 : diff>100000? 25000 : diff>10000? 2500 : diff>1000? 250 : diff>100? 25 : diff>10? 2 : 1;
        plus = totalScore>currentDisplayedScore? plus : -plus;
        currentDisplayedScore+=plus;
    }
    
    if(height != currentDisplayedHeight){
        diff = abs(height - currentDisplayedHeight);
        plus = diff>1000000? 125000 : diff>100000? 12500 : diff>10000? 1250 : diff>1000? 125 : diff>100? 12 : diff>10? 2 : 1;
        plus = height>currentDisplayedHeight? plus : -plus;
        currentDisplayedHeight+=plus;
    }
    
    if(speed != currentDisplayedSpeed){
        diff = abs(speed - currentDisplayedSpeed);
        plus = diff>1000000? 62500 : diff>100000? 6250 : diff>10000? 625 : diff>1000? 62 : diff>100? 6 : diff>10? 2 : 1;
        plus = speed>currentDisplayedSpeed? plus : -plus;
        currentDisplayedSpeed+=plus;
    }
    
    if(time != currentDisplayedTime){
        diff = abs(time - currentDisplayedTime);
        plus = diff>1000000? 125000 : diff>100000? 12500 : diff>10000? 1250 : diff>1000? 125 : diff>100? 12 : diff>10? 2 : 1;
        plus = time>currentDisplayedTime? plus : -plus;
        currentDisplayedTime+=plus;
    }
    
    if(coins != currentDisplayedCoins){
        diff = abs(coins - currentDisplayedCoins);
        plus = diff>1000000? 31250 : diff>100000? 3125 : diff>10000? 312 : diff>1000? 31 : diff>100? 3 : diff>10? 2 : 1;
        plus = coins>currentDisplayedCoins? plus : -plus;
        currentDisplayedCoins+=plus;
    }
}

void Menu::draw()
{
    if(isGameOver){
        ofSetColor(255, 255, 255, 255*alpha);
        imgTitle.draw((ofGetWidth() - imgTitle.width)/2,ofGetHeight()*0.15);
        
        if(alpha - 0.3 > 0){
            ofSetColor(255, 255, 255, 255*(alpha - 0.3));
            imgMessageBg.draw((ofGetWidth() - imgMessageBg.width)/2,ofGetHeight()*0.3);
            ofSetColor(212, 223, 241, 255*(alpha - 0.3));
            if(cause == "fuel"){
                font->drawString("De brandstof is op. Pak volgende keer wat meer jerrycans op.", (ofGetWidth() - imgMessageBg.width)/2 + 77, ofGetHeight()*0.3 + 82);
                ofSetColor(255, 255, 255, 255*(alpha - 0.3));
                iconMessageNoFuel.draw((ofGetWidth() - imgMessageBg.width)/2 + 27, ofGetHeight()*0.3 + 56);
            } else if(cause == "health"){
                font->drawString("Je verloor al je leven. Pak volgende keer wat leven op.", (ofGetWidth() - imgMessageBg.width)/2 + 107, ofGetHeight()*0.3 + 82);
                ofSetColor(255, 255, 255, 255*(alpha - 0.3));
                iconMessageNoHealth.draw((ofGetWidth() - imgMessageBg.width)/2 + 57, ofGetHeight()*0.3 + 56);
            }
        }
        
        if(alpha - 0.6 > 0){
            ofSetColor(255, 255, 255, 255*(alpha - 0.6));
            imgStatsBg.draw((ofGetWidth() - imgStatsBg.width)/2,ofGetHeight()*0.5);
            
            iconHeight.draw((ofGetWidth() - imgStatsBg.width)/2 + imgStatsBg.width*0.043, ofGetHeight()*0.5 + 63);
            iconSpeed.draw((ofGetWidth() - imgStatsBg.width)/2 + imgStatsBg.width*0.23, ofGetHeight()*0.5 + 63);
            iconTime.draw((ofGetWidth() - imgStatsBg.width)/2 + imgStatsBg.width*0.47, ofGetHeight()*0.5 + 63);
            iconCoins.draw((ofGetWidth() - imgStatsBg.width)/2 + imgStatsBg.width*0.72, ofGetHeight()*0.5 + 63);
            
            ofSetColor(255,255,255,255*(alpha-0.6));
            ostringstream convert;
            
            string scoreStr;
            convert << currentDisplayedScore;
            scoreStr = convert.str();
            int scoreStrLen = scoreStr.length();
            font2->drawString(scoreStr, (ofGetWidth() - scoreStrLen*20)/2, ofGetHeight()*0.53 + 13);
            convert.str("");
            convert.clear();
            
            ofSetColor(212, 223, 241, 255*(alpha - 0.6));
            
            string heightStr;
            convert << currentDisplayedHeight << " km";
            heightStr = convert.str();
            font->drawString(heightStr, (ofGetWidth() - imgStatsBg.width)/2 + imgStatsBg.width*0.09, ofGetHeight()*0.5 + 83);
            convert.str("");
            convert.clear();
            
            string speedStr;
            convert << currentDisplayedSpeed << " km / u";
            speedStr = convert.str();
            font->drawString(speedStr, (ofGetWidth() - imgStatsBg.width)/2 + imgStatsBg.width*0.28, ofGetHeight()*0.5 + 83);
            convert.str("");
            convert.clear();
            
            string timeStr;
            convert << currentDisplayedTime << " ms";
            timeStr = convert.str();
            font->drawString(timeStr, (ofGetWidth() - imgStatsBg.width)/2 + imgStatsBg.width*0.52, ofGetHeight()*0.5 + 83);
            convert.str("");
            convert.clear();
            
            string coinsStr;
            convert << currentDisplayedCoins << " / " << totalCoins << " munten";
            coinsStr = convert.str();
            font->drawString(coinsStr, (ofGetWidth() - imgStatsBg.width)/2 + imgStatsBg.width*0.77, ofGetHeight()*0.5 + 83);
            convert.str("");
            convert.clear();
        }
        
        if(alpha-0.9 > 0){
            ofSetColor(255, 255, 255, 255*(alpha - 0.9));
            imgReplayBg.draw((ofGetWidth() - imgReplayBg.width)/2,ofGetHeight()*0.7);
        
            imgButton1.draw((ofGetWidth() - imgReplayBg.width)/2 + imgReplayBg.width*0.255, ofGetHeight()*0.7 + imgReplayBg.height*0.47);
            imgButton2.draw((ofGetWidth() - imgReplayBg.width)/2 + imgReplayBg.width*0.34, ofGetHeight()*0.7 + imgReplayBg.height*0.47);
            imgButton3.draw((ofGetWidth() - imgReplayBg.width)/2 + imgReplayBg.width*0.455, ofGetHeight()*0.7 + imgReplayBg.height*0.47);
        
            ofSetColor(212, 223, 241, 255*(alpha - 0.9));
            font->drawString("Duw op      ,      of      om opnieuw te beginnen.", (ofGetWidth() - imgReplayBg.width)/2 + 100, ofGetHeight()*0.7 + 83);
        }
        ofSetColor(255, 255, 255);
    }
}