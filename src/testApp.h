#pragma once

#include "ofMain.h"
#include "Functions.h"
#include "Player.h"
#include "Objects.h"
#include "Backgrounds.h"
#include "Display.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void setupArduino(const int & version);

		void keyPressed(int key);
		void keyReleased(int key);
		
    private:
        ofArduino arduino;
        Functions* functions;
        Player* player;
        Background* background;
        Objects* objects;
        Display* display;
        vector<int> keys;
};
