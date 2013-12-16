//
//  Menu.h
//  ED_eindopdracht
//
//  Created by Bastiaan Andriessen on 15/12/13.
//
//

#ifndef __ED_eindopdracht__Menu__
#define __ED_eindopdracht__Menu__

#include "ofMain.h"

class Menu
{
    public:
        Menu(bool gameOver);
        void update();
        void draw();
    
    
    private:
        ofTrueTypeFont* font;
        bool isGameOver;
        ofImage imgTitle;
        ofImage imgMessageBg;
        ofImage imgStatsBg;
        ofImage imgReplayBg;
    
    
};


#endif /* defined(__ED_eindopdracht__Menu__) */
