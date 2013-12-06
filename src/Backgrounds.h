//
//  Backgrounds.h
//  ED_eindopdracht
//
//  Created by Daan Steegmans on 2/12/13.
//
//

#ifndef __ED_eindopdracht__Backgrounds__
#define __ED_eindopdracht__Backgrounds__

#include "ofMain.h"
#include "Background.h"

class Backgrounds
{
public:
    Backgrounds();
    void update();
    void draw();
    void move();
    void moveFast();
    
    vector<Background *> backgrounds;
    
private:
    int x;
    int y;
};

#endif /* defined(__ED_eindopdracht__Backgrounds__) */
