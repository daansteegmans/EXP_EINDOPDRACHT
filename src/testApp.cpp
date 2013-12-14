#include "testApp.h"
#include <time.h>

//--------------------------------------------------------------
void testApp::setup()
{
    /*ofAddListener(arduino.EInitialized, this, &testApp::setupArduino);
    arduino.connect("/dev/tty.usbmodem1411", 57600);*/
    
    functions = new Functions();
    player = new Player();
    background = new Background();
    objects = new Objects();
    display = new Display();
    
    timeStarted = ofGetElapsedTimeMillis();
    
    keys.resize(2);
    gameOverTime = 0;
}

void testApp::setupArduino(const int &version){
    ofRemoveListener(arduino.EInitialized, this, &testApp::setupArduino);
    ofLog() << "setup arduino " << version;
    arduino.sendDigitalPinMode(4, ARD_INPUT);
    arduino.sendDigitalPinMode(5, ARD_INPUT);
    
    arduino.sendDigitalPinMode(12, ARD_OUTPUT);
    arduino.sendDigitalPinMode(13, ARD_OUTPUT);
}

//--------------------------------------------------------------
void testApp::update()
{
    cout << display->fuel << endl;
    if(gameOverTime == 0 && !(display->fuel<=0) && !(display->health<=0)){
        display->time = ofGetElapsedTimeMillis()-timeStarted;
    
        for(int i=0; i<objects->coins.size(); i++){
            if(functions->checkCollision(player, objects->coins[i]) != "no collision"){
                vector<Coin *> coins;
                for(int j=0; j<objects->coins.size(); j++){
                    if(objects->coins[j] != objects->coins[i]){
                        coins.push_back(objects->coins[j]);
                    }
                }
                objects->coins = coins;
                display->coins++;
            }
        }
    
        /*arduino.update();
        ofLog() << "pin4: " << arduino.getDigital(4) << endl;
        ofLog() << "pin5: " << arduino.getDigital(5) << endl;*/
    
        if(/*arduino.getDigital(4) == 1 && arduino.getDigital(5) == 1*/keys[356] == true && keys[358] == true){
            background->speedY += 0.3;
            background->speedX = 0;
            objects->velX = 0;
            objects->velY = 4.5;
            display->fuel-=0.08;
        
            if(player->y > ((ofGetHeight() - player->img.getHeight()) / 2) - 50){
                player->velY += 0.07;
            }
        
            /*arduino.sendDigital(12, ARD_HIGH);
             arduino.sendDigital(13, ARD_HIGH);*/
        }else{
            background->speedY -= 0.05;
            objects->velX = 0;
            objects->velY = 1.5;
            display->fuel-=0.02;
        
            if(player->y < ((ofGetHeight() - player->img.getHeight()) / 2) + 70 && (player->y - player->velY) <= ((ofGetHeight() -  player->img.getHeight()) / 2) + 70){
                player->velY -= 0.1;
            } else {
                player->velY = 0;
            }
        
            //LEFT
            if(/*arduino.getDigital(4) == 1*/keys[356] == true){
                background->speedX = 3;
                objects->velX = 2.2;
            
                /*arduino.sendDigital(13, ARD_HIGH);
                arduino.sendDigital(12, ARD_LOW);*/
            }
        
            //RIGHT
            if(/*arduino.getDigital(5) == 1*/keys[358] == true){
                background->speedX = -3;
                objects->velX = -2.2;
            
                /*arduino.sendDigital(12, ARD_HIGH);
             arduino.sendDigital(13, ARD_LOW);*/
            }
        
            if(/*arduino.getDigital(4) != 1 && arduino.getDigital(5) != 1*/ keys[356] == false && keys[358] == false){
                background->speedX = 0;
            
                /*arduino.sendDigital(12, ARD_LOW);
                arduino.sendDigital(13, ARD_LOW);*/
            }
        }
    
        background->update();
        player->update();
        objects->update();
        display->update();
    }else{
        if(gameOverTime == 0){
            gameOverTime = ofGetElapsedTimeMillis()-timeStarted;
        }
        
        int currentTime = ofGetElapsedTimeMillis()-timeStarted;
        if(/*arduino.getDigital(4) == 1 && arduino.getDigital(5) == 1*/(keys[356] == true || keys[358] == true) && currentTime > (gameOverTime+2000)){
            gameOverTime = 0;
            
            timeStarted = 0;
            background->setDefault();
            player->setDefault();
            objects->setDefault();
            display->setDefault();
        }
    }
}

//--------------------------------------------------------------
void testApp::draw()
{
    background->draw();
    player->draw();
    objects->draw();
    display->draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
    keys[key] = true;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key)
{
    keys[key] = false;
}

