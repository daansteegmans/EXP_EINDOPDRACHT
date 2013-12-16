//
//  Menu.cpp
//  ED_eindopdracht
//
//  Created by Bastiaan Andriessen on 15/12/13.
//
//

#include "Menu.h"

Menu::Menu(bool gameOver)
{
    isGameOver = gameOver;
    
    font = new ofTrueTypeFont();
    font->loadFont("fonts/Piston_Pressure.otf", 16);
    
    if(isGameOver){
        imgTitle.loadImage("menu/gameover.png");
        imgMessageBg.loadImage("menu/window_msg.png");
        imgStatsBg.loadImage("menu/window_stats.png");
        imgReplayBg.loadImage("menu/window_replay.png");
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
        font->drawString("De brandstof is op. Pak volgende keer wat meer jerrycans op.", (ofGetWidth() - imgMessageBg.width)/2 + 40, ofGetHeight()*0.3 + 85);
        font->drawString("De brandstof is op. Pak volgende keer wat meer jerrycans op.", (ofGetWidth() - imgStatsBg.width)/2 + 20, ofGetHeight()*0.5 + 85);
        font->drawString("Duw op      ,      of      om opnieuw te beginnen.", (ofGetWidth() - imgReplayBg.width)/2 + 100, ofGetHeight()*0.7 + 85);
        ofSetColor(255, 255, 255);
    }
}