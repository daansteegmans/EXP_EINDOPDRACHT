//
//  Display.h
//  ED_eindopdracht
//
//  Created by Bastiaan Andriessen on 13/12/13.
//
//

#ifndef __ED_eindopdracht__Display__
#define __ED_eindopdracht__Display__

#include "ofMain.h"

class Display
{
    public:
        Display();
        void update();
        void draw();

        ofImage topBg;
        ofImage bottomBg;
    
        int fuelBorderLeft;
        int fuelBorderRight;
        int healthBorderLeft;
        int healthBorderRight;
    
    private:
    
};

#endif /* defined(__ED_eindopdracht__Display__) */
