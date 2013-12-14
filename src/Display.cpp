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
    
    fuelBorderLeft = 0;
    fuelBorderRight = 0;
    healthBorderLeft = 0;
    healthBorderRight = 0;
}

void Display::update()
{
    //unsigned char *targetPixels = new unsigned char[n*4];
    //bottomBg.delete [] targetPixels;
    if(fuelBorderLeft > 0){
        for(int i=0; i<(fuelBorderRight-fuelBorderLeft); i++){
            for(int j=0; j<40; j++){
                topBg.setColor(i+fuelBorderLeft,j,ofColor(255, 0, 0));
                //topBg.setColor(fuelBorderLeft,j,ofColor(255, 0, 0));
                //topBg.setColor(fuelBorderRight-ofGetWidth()/2 - topBg.getWidth()/2,j,ofColor(255, 0, 0));
            }
        }
    }
    topBg.update();
}

void Display::draw()
{
    topBg.draw(ofGetWidth()/2 - topBg.getWidth()/2, 0);
    bottomBg.draw(ofGetWidth()/2 - bottomBg.getWidth()/2, ofGetHeight() - bottomBg.height);
    
    if(fuelBorderLeft == 0 || fuelBorderRight == 0){
        fuelBorderLeft = ofGetWidth()/2 - topBg.getWidth()/2 + 15;
        fuelBorderRight = topBg.getWidth()/2 - 4;
        cout << fuelBorderLeft << endl;
    }
    
    if(healthBorderRight == 0 || healthBorderRight == 0){
        healthBorderRight = ofGetWidth()/2 - topBg.getWidth()/2 + topBg.getWidth() - 60;
        healthBorderRight = topBg.getWidth()/2 + 4;
        cout << healthBorderRight << endl;
    }
}