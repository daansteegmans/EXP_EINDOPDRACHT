//
//  Display.cpp
//  ED_eindopdracht
//
//  Created by Bastiaan Andriessen on 13/12/13.
//
//

#include "Display.h"

Display::Display()
{
    topBg.loadImage("display/display_top.png");
    topBgBorder.loadImage("display/display_top_border.png");
    bottomBg.loadImage("display/display_bottom.png");
    fuelCurrentFill.loadImage("display/fuel.png");
    healthCurrentFill.loadImage("display/health.png");
    fuelOriginalFill = fuelCurrentFill;
    healthOriginalFill = healthCurrentFill;
    
    iconAltitude.loadImage("display/icons/icon_height.png");
    iconSpeed.loadImage("display/icons/icon_speed.png");
    iconTime.loadImage("display/icons/icon_time.png");
    iconTemperature.loadImage("display/icons/icon_temperature.png");
    iconCoins.loadImage("display/icons/icon_coins.png");
    
    font = new ofTrueTypeFont();
    font->loadFont("fonts/Piston_Pressure.otf", 24);
    
    Display::setDefault();
}

void Display::update()
{
    fuel = round(fuel*100)/100;
    
    int fuelNewWidth = fillTotalWidth * (fuel/100);
    int fuelNewX = ofGetWidth()/2 - topBg.getWidth()/2 + 67 + (fillTotalWidth - fuelNewWidth);
    fuelCurrentFill.cropFrom(fuelOriginalFill, (fillTotalWidth - fuelNewWidth), 0, fuelNewWidth, fillTotalHeight);
    
    int healthNewWidth = fillTotalWidth * (health/100);
    healthCurrentFill.cropFrom(healthOriginalFill, 0, 0, healthNewWidth, fillTotalHeight);
    
    topBg.update();
}

void Display::draw()
{
    topBg.draw(ofGetWidth()/2 - topBg.getWidth()/2, 0);
    fuelCurrentFill.draw(ofGetWidth()/2 - topBg.getWidth()/2 + 67 + (fillTotalWidth - fuelCurrentFill.width), 45);
    healthCurrentFill.draw(ofGetWidth()/2 - topBg.getWidth()/2 + 468, 45);
    topBgBorder.draw(ofGetWidth()/2 - topBg.getWidth()/2, 44);
    bottomBg.draw(ofGetWidth()/2 - bottomBg.getWidth()/2, ofGetHeight() - bottomBg.height);
    
    iconAltitude.draw(ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.05,5);
    iconSpeed.draw(ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.25 ,5);
    iconTime.draw(ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.47 ,5);
    iconTemperature.draw(ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.665 ,5);
    iconCoins.draw(ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.79 ,5);
    
    ofSetColor(255,255,255,255*0.6);
    ostringstream convert;
    
    string altitudeStr;
    convert << altitude << " km";
    altitudeStr = convert.str();
    font->drawString(altitudeStr, ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.05 + 35, 30);
    convert.str("");
    convert.clear();
    
    string speedStr;
    convert << speed << " km / h";
    speedStr = convert.str();
    font->drawString(speedStr, ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.25 + 35, 30);
    convert.str("");
    convert.clear();
    
    string timeStr;
    convert << time << " ms";
    timeStr = convert.str();
    font->drawString(timeStr, ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.47 + 35, 30);
    convert.str("");
    convert.clear();
    
    string temperatureStr;
    convert << temperature << " °C";
    temperatureStr = convert.str();
    font->drawString(temperatureStr, ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.665 + 35, 30);
    convert.str("");
    convert.clear();
    
    string coinsStr;
    convert << coins << " coins";
    coinsStr = convert.str();
    font->drawString(coinsStr, ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.79 + 35, 30);
    convert.str("");
    convert.clear();
    
    ofSetColor(255,255,255,255);
}

void Display::setDefault(){
    fuel = 100;
    health = 100;
    fillTotalWidth = 391;
    fillTotalHeight = 40;
    
    altitude = 0;
    speed = 150;
    time = 0;
    temperature = 20;
    coins = 0;
}