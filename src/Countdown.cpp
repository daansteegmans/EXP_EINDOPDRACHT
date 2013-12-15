//
//  Countdown.cpp
//  ED_eindopdracht
//
//  Created by Bastiaan Andriessen on 15/12/13.
//
//

#include "Countdown.h"

Countdown::Countdown(int count)
{
    font = new ofTrueTypeFont();
    font->loadFont("fonts/Piston_Pressure.otf", 44);
    Countdown::setDefault(count);
    alpha = 0;
}

void Countdown::setDefault(int count){
    totalCount = count;
    currentCount = 0;
}

void Countdown::updateCurrentCount(int count){
    currentCount = count;
    alpha = 0;
}

void Countdown::update()
{
    if(currentCount > totalCount){
        currentCount = totalCount;
    }
    float diff = 0.05;
    if(alpha<1-diff)alpha+=diff;
    alpha = round(alpha*100)/100;
    
    ostringstream convert;
    convert << totalCount-currentCount;
    current = convert.str();
    if(current == "0"){
        current = "start";
    }
}

void Countdown::draw()
{
    ofSetColor(255, 255, 255, 255*alpha);
    ofRectangle rect = font->getStringBoundingBox(current, 0,0);
    font->drawString(current, ofGetWidth()/2 - rect.width/2, ofGetHeight()/2 - rect.height/2);
    ofSetColor(255, 255, 255, 255);
}