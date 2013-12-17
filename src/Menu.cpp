//
//  Menu.cpp
//  ED_eindopdracht
//
//  Created by Bastiaan Andriessen on 15/12/13.
//
//

#include "Menu.h"

Menu::Menu(bool gameOver, string causeOfGameOver)
{
    isGameOver = gameOver;
    cause = causeOfGameOver;
    cout << "causeOfGameOver: " << causeOfGameOver << "cause: " << cause << endl;
    
    font = new ofTrueTypeFont();
    font->loadFont("fonts/Piston_Pressure.otf", 16);
    
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
    }
}

void Menu::update()
{
    
}

void Menu::draw()
{
    if(isGameOver){
        imgTitle.draw((ofGetWidth() - imgTitle.width)/2,ofGetHeight()*0.15);
        
        imgMessageBg.draw((ofGetWidth() - imgMessageBg.width)/2,ofGetHeight()*0.3);
        imgStatsBg.draw((ofGetWidth() - imgStatsBg.width)/2,ofGetHeight()*0.5);
        imgReplayBg.draw((ofGetWidth() - imgReplayBg.width)/2,ofGetHeight()*0.7);
        
        ofSetColor(212, 223, 241);
        if(cause == "fuel"){
            font->drawString("De brandstof is op. Pak volgende keer wat meer jerrycans op.", (ofGetWidth() - imgMessageBg.width)/2 + 77, ofGetHeight()*0.3 + 82);
            iconMessageNoFuel.draw((ofGetWidth() - imgMessageBg.width)/2 + 27, ofGetHeight()*0.3 + 56);
        } else if(cause == "health"){
            font->drawString("Je verloor al je leven. Pak volgende keer wat leven op.", (ofGetWidth() - imgMessageBg.width)/2 + 107, ofGetHeight()*0.3 + 82);
            iconMessageNoHealth.draw((ofGetWidth() - imgMessageBg.width)/2 + 57, ofGetHeight()*0.3 + 56);
        }
        
        iconHeight.draw((ofGetWidth() - imgStatsBg.width)/2 + imgStatsBg.width*0.043, ofGetHeight()*0.5 + 63);
        iconSpeed.draw((ofGetWidth() - imgStatsBg.width)/2 + imgStatsBg.width*0.23, ofGetHeight()*0.5 + 63);
        iconTime.draw((ofGetWidth() - imgStatsBg.width)/2 + imgStatsBg.width*0.47, ofGetHeight()*0.5 + 63);
        iconCoins.draw((ofGetWidth() - imgStatsBg.width)/2 + imgStatsBg.width*0.72, ofGetHeight()*0.5 + 63);
        
        font->drawString("De brandstof is op. Pak volgende keer wat meer jerrycans op.", (ofGetWidth() - imgStatsBg.width)/2 + 20, ofGetHeight()*0.5 + 85);
        font->drawString("Duw op      ,      of      om opnieuw te beginnen.", (ofGetWidth() - imgReplayBg.width)/2 + 100, ofGetHeight()*0.7 + 85);
        ofSetColor(255, 255, 255);
    }
}