//
//  Objects.h
//  ED_eindopdracht
//
//  Created by Daan Steegmans on 6/12/13.
//
//

#ifndef __ED_eindopdracht__Objects__
#define __ED_eindopdracht__Objects__

#include "ofMain.h"
#include "Oxygen.h"

class Objects
{
    public:
        Objects();
        void update();
        void draw();
        float velY;
    
    private:
        Oxygen* oxygen;
        vector<Oxygen *> oxygenBubbles;
    
};

#endif /* defined(__ED_eindopdracht__Objects__) */
