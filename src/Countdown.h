//
//  Countdown.h
//  ED_eindopdracht
//
//  Created by Bastiaan Andriessen on 15/12/13.
//
//

#ifndef __ED_eindopdracht__Countdown__
#define __ED_eindopdracht__Countdown__

#include "ofMain.h"

class Countdown
{
    public:
        Countdown(int count);
        void setDefault(int count);
        void updateCurrentCount(int count);
        void update();
        void draw();
        int currentCount;
        string current;
    private:
        ofTrueTypeFont *font;
        int totalCount;
        float alpha;
    
};

#endif /* defined(__ED_eindopdracht__Countdown__) */
