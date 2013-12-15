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
        Menu();
        void update();
        void draw();
        ofImage img;
    
    private:
        int x;
        int y;
    
};


#endif /* defined(__ED_eindopdracht__Menu__) */
