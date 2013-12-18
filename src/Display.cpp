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
    bottomBg.loadImage("display/display_bottom.png");
    fuelCurrentFill.loadImage("display/fuel.png");
    healthCurrentFill.loadImage("display/health.png");
    
    fuelBorderNormal.loadImage("display/fuel_border_normal.png");
    fuelBorderHightlight.loadImage("display/fuel_border_highlight.png");
    
    fuelImageNormal.loadImage("display/fuel_normal.png");
    fuelImageHighlight.loadImage("display/fuel_highlight.png");
    
    healthBorderNormal.loadImage("display/health_border_normal.png");
    healthBorderHightlight.loadImage("display/health_border_highlight.png");
    
    healthImageNormal.loadImage("display/health_normal.png");
    healthImageHighlight.loadImage("display/health_highlight.png");
    
    iconAltitude.loadImage("display/icons/icon_height.png");
    iconSpeed.loadImage("display/icons/icon_speed.png");
    iconTime.loadImage("display/icons/icon_time.png");
    iconTemperature.loadImage("display/icons/icon_temperature.png");
    iconCoins.loadImage("display/icons/icon_coins.png");
    
    iconEmpty1.loadImage("display/icons/powerup_1.png");
    iconEmpty2.loadImage("display/icons/powerup_2.png");
    iconEmpty3.loadImage("display/icons/powerup_3.png");
    
    font = new ofTrueTypeFont();
    font->loadFont("fonts/Piston_Pressure.otf", 24);
    font2 = new ofTrueTypeFont();
    font2->loadFont("fonts/Piston_Pressure.otf", 28);
    
    Display::setDefault();
}

void Display::setDefault(){
    fuel = 100;
    health = 100;
    fillTotalWidth = 391;
    fillTotalHeight = 40;
    
    altitude = 0;
    defaultSpeed = 48;
    speed = 0;
    maxSpeed = speed;
    time = 0;
    temperature = 40;
    minTemperature = -100;
    coins = 0;
    
    topY = -topBg.height;
    bottomY = ofGetHeight();
    topDefaultY = 0;
    bottomDefaultY = ofGetHeight() - bottomBg.height;
    alpha = 0;
    
    fuelStartedBlinkingTime = 0;
    numFuelBlinks = 0;
    currentShownFuel = "normal";
    
    healthStartedBlinkingTime = 0;
    numHealthBlinks = 0;
    currentShownHealth = "normal";
    
    fuelOriginalFill = fuelCurrentFill;
    fuelBorderShown = fuelBorderNormal;
    fuelImageShown = fuelImageNormal;
    
    healthOriginalFill = healthCurrentFill;
    healthBorderShown = healthBorderNormal;
    healthImageShown = healthImageNormal;
    
    iconPowerUp1 = iconEmpty1;
    iconPowerUp2 = iconEmpty2;
    iconPowerUp3 = iconEmpty3;
    
    maxPowerups = 3;
    
    Display::update();
    Display::draw();
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
    
    if(fuel < 25){
        if(fuelStartedBlinkingTime == 0){
            fuelStartedBlinkingTime = ofGetElapsedTimeMillis();
        }
        if(ofGetElapsedTimeMillis() > fuelStartedBlinkingTime + 200*numFuelBlinks && fuelStartedBlinkingTime!=0){
            if(currentShownFuel == "normal"){
                fuelImageShown = fuelImageHighlight;
                fuelBorderShown = fuelBorderHightlight;
                currentShownFuel = "highlight";
            }else{
                fuelImageShown = fuelImageNormal;
                fuelBorderShown = fuelBorderNormal;
                currentShownFuel = "normal";
            }
            numFuelBlinks++;
        }
    }else{
        fuelStartedBlinkingTime = 0;
        numFuelBlinks = 0;
    }
    
    if(health < 25){
        if(healthStartedBlinkingTime == 0){
            healthStartedBlinkingTime = ofGetElapsedTimeMillis();
        }
        if(ofGetElapsedTimeMillis() > healthStartedBlinkingTime + 200*numHealthBlinks && healthStartedBlinkingTime!=0){
            if(currentShownHealth == "normal"){
                healthImageShown = healthImageHighlight;
                healthBorderShown = healthBorderHightlight;
                currentShownHealth = "highlight";
            }else{
                healthImageShown = healthImageNormal;
                healthBorderShown = healthBorderNormal;
                currentShownHealth = "normal";
            }
            numHealthBlinks++;
        }
    }else{
        healthStartedBlinkingTime = 0;
        numHealthBlinks = 0;
    }
    
    if(maxSpeed < speed)maxSpeed = speed;
    if(temperature < minTemperature) temperature = minTemperature;
    temperature = round(temperature*10)/10;
}

void Display::draw()
{
    ofSetColor(255,255,255,255*alpha);
    
    topBg.draw(ofGetWidth()/2 - topBg.getWidth()/2, topY);
    fuelCurrentFill.draw(ofGetWidth()/2 - topBg.getWidth()/2 + 67 + (fillTotalWidth - fuelCurrentFill.width), topY + 45);
    healthCurrentFill.draw(ofGetWidth()/2 - topBg.getWidth()/2 + 468, topY + 45);
    bottomBg.draw(ofGetWidth()/2 - bottomBg.getWidth()/2, bottomY);
    
    fuelBorderShown.draw(ofGetWidth()/2 - fuelBorderShown.width - 5, topY + topBg.height/2 + 3);
    healthBorderShown.draw(ofGetWidth()/2 + 5, topY + topBg.height/2 + 3);
    
    fuelImageShown.draw(ofGetWidth()/2 - fuelImageShown.width - 5, topY + topBg.height + 5);
    healthImageShown.draw(ofGetWidth()/2 + 5, topY + topBg.height + 5);
    
    iconAltitude.draw(ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.05, topY+5);
    iconSpeed.draw(ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.22 , topY+5);
    iconTime.draw(ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.44 , topY+5);
    iconTemperature.draw(ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.625 , topY+5);
    iconCoins.draw(ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.755 , topY+5);
    
    iconPowerUp1.draw(ofGetWidth()/2 - bottomBg.getWidth()/2 + bottomBg.getWidth()*0.12, bottomY + 46);
    iconPowerUp2.draw(ofGetWidth()/2 - bottomBg.getWidth()/2 + bottomBg.getWidth()*0.4, bottomY + 46);
    iconPowerUp3.draw(ofGetWidth()/2 - bottomBg.getWidth()/2 + bottomBg.getWidth()*0.7, bottomY + 46);
    
    ofSetColor(255,255,255,255*(0.6*alpha));
    ostringstream convert;
    
    string altitudeStr;
    convert << altitude << " km";
    altitudeStr = convert.str();
    font->drawString(altitudeStr, ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.05 + 35, topY + 30);
    convert.str("");
    convert.clear();
    
    string speedStr;
    convert << speed << " km / u";
    speedStr = convert.str();
    font->drawString(speedStr, ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.22 + 35, topY + 30);
    convert.str("");
    convert.clear();
    
    string timeStr;
    convert << time << " ms";
    timeStr = convert.str();
    font->drawString(timeStr, ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.44 + 35, topY + 30);
    convert.str("");
    convert.clear();
    
    string temperatureStr;
    convert << temperature << "C";
    temperatureStr = convert.str();
    font->drawString(temperatureStr, ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.625 + 35, topY + 30);
    convert.str("");
    convert.clear();
    
    string coinsStr;
    convert << coins << " munten";
    coinsStr = convert.str();
    font->drawString(coinsStr, ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth()*0.755 + 35, topY + 30);
    convert.str("");
    convert.clear();
    
    string powerup1Str;
    convert << "leeg";
    powerup1Str = convert.str();
    font2->drawString(powerup1Str, ofGetWidth()/2 - bottomBg.getWidth()/2 + bottomBg.getWidth()*0.12 + iconPowerUp1.width + 20, bottomY + 80);
    convert.str("");
    convert.clear();
    
    string powerup2Str;
    convert << "leeg";
    powerup2Str = convert.str();
    font2->drawString(powerup2Str, ofGetWidth()/2 - bottomBg.getWidth()/2 + bottomBg.getWidth()*0.4 + iconPowerUp2.width + 20, bottomY + 80);
    convert.str("");
    convert.clear();
    
    string powerup3Str;
    convert << "leeg";
    powerup3Str = convert.str();
    font2->drawString(powerup3Str, ofGetWidth()/2 - bottomBg.getWidth()/2 + bottomBg.getWidth()*0.7 + iconPowerUp3.width + 20, bottomY + 80);
    convert.str("");
    convert.clear();
    
    ofSetColor(255,255,255,255);
}