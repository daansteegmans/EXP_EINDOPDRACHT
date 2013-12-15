#include "testApp.h"
#include <time.h>

//--------------------------------------------------------------
void testApp::setup()
{
    /*ofAddListener(arduino.EInitialized, this, &testApp::setupArduino);
    arduino.connect("/dev/tty.usbmodem1411", 57600);*/
    
    timeStarted = ofGetElapsedTimeMillis();
    //delay until animation of player + display
    startDelay = 1000;
    //delay until player is controllable
    controlDelay = 3000;
    
    functions = new Functions();
    player = new Player();
    background = new Background();
    objects = new Objects();
    display = new Display();
    countDown = new Countdown(round(controlDelay/1000));
    
    keys.resize(2);
    gameOverTime = 0;
}

void testApp::setupArduino(const int &version){
    ofRemoveListener(arduino.EInitialized, this, &testApp::setupArduino);
    ofLog() << "setup arduino " << version;
    arduino.sendDigitalPinMode(4, ARD_INPUT);
    arduino.sendDigitalPinMode(5, ARD_INPUT);
    
    arduino.sendDigitalPinMode(11, ARD_OUTPUT);
    arduino.sendDigitalPinMode(12, ARD_OUTPUT);
    arduino.sendDigitalPinMode(13, ARD_OUTPUT);
}

//--------------------------------------------------------------
void testApp::update()
{
    //arduino.update();
    
    if(gameOverTime == 0 && !(display->fuel<=0) && !(display->health<=0)){
        if(!player->gameHasStarted){
            //countdown
            if(ofGetElapsedTimeMillis() - timeStarted > (countDown->currentCount+1)*1000){
                int newCurrentCount = countDown->currentCount+1;
                countDown->updateCurrentCount(newCurrentCount);
            }
            
            if(ofGetElapsedTimeMillis() > timeStarted+startDelay){
                if((player->y - player->velY) > player->defaultY){
                    float distance = (ofGetHeight() - player->img.getHeight()) - player->defaultY;
                    if(player->y > player->defaultY + (distance*0.5)){
                        player->velY += 0.03;
                    }else{
                        if(player->velY > 0.03){
                            player->velY -= 0.03;
                        }
                    }
                }
                if(ofGetElapsedTimeMillis() > timeStarted+startDelay+100){
                    if(display->topY < display->topDefaultY){
                        display->topY++;
                    }
                    if(display->bottomY > display->bottomDefaultY){
                        display->bottomY--;
                    }
                    if(display->alpha < 1-0.08){
                        display->alpha += 0.08;
                    }else{
                        display->alpha = 1;
                    }
                }
            }
            
            if(ofGetElapsedTimeMillis() > timeStarted + controlDelay + 1000){
                timeStarted = ofGetElapsedTimeMillis();
                player->y = player->defaultY;
                player->velY = 0;
                player->gameHasStarted = true;
            }
        } else {
        
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
    
            if(/*arduino.getDigital(4) == 1 && arduino.getDigital(5) == 1*/keys[356] == true && keys[358] == true){
                background->speedY += 0.3;
                background->speedX = 0;
                objects->velX = 0;
                objects->velY = 4.5;
                display->fuel-=0.08;
                display->speed = round(display->defaultSpeed*2);
        
                if(player->y > ((ofGetHeight() - player->img.getHeight()) / 2) - 50){
                    player->velY += 0.07;
                }
        
                /*arduino.sendDigital(11, ARD_HIGH);
                arduino.sendDigital(12, ARD_HIGH);
                arduino.sendDigital(13, ARD_HIGH);*/
            }else{
                background->speedY -= 0.05;
                objects->velX = 0;
                objects->velY = 1.5;
                display->fuel-=0.02;
                display->speed = display->defaultSpeed;
        
                if(player->y < player->defaultY && (player->y - player->velY) <= player->defaultY){
                    player->velY -= 0.1;
                } else {
                    player->velY = 0;
                }
        
                //LEFT
                if(/*arduino.getDigital(4) == 1*/ keys[356] == true){
                    background->speedX = 3;
                    objects->velX = 2.2;
            
                    /*arduino.sendDigital(11, ARD_LOW);
                    arduino.sendDigital(12, ARD_HIGH);
                    arduino.sendDigital(13, ARD_LOW);*/
                }
        
                //RIGHT
                if(/*arduino.getDigital(5) == 1*/ keys[358] == true){
                    background->speedX = -3;
                    objects->velX = -2.2;
            
                    /*arduino.sendDigital(11, ARD_LOW);
                    arduino.sendDigital(12, ARD_LOW);
                    arduino.sendDigital(13, ARD_HIGH);*/
                }
        
                if(/*arduino.getDigital(4) != 1 && arduino.getDigital(5) != 1*/ keys[356] == false && keys[358] == false){
                    background->speedX = 0;
            
                    /*arduino.sendDigital(11, ARD_LOW);
                    arduino.sendDigital(12, ARD_LOW);
                    arduino.sendDigital(13, ARD_LOW);*/
                }
            }
    
            objects->update();
            display->update();
        }
        
        if(!player->gameHasStarted){
            countDown->update();
            if(ofGetElapsedTimeMillis() > timeStarted+startDelay){
                background->update();
            }
        }else{
            background->update();
        }
        player->update();
    }else{
        /*arduino.sendDigital(11, ARD_LOW);
        arduino.sendDigital(12, ARD_LOW);
        arduino.sendDigital(13, ARD_LOW);*/
        
        player->velY = 0;
        player->velX = 0;
        
        if(display->topY > -(display->topBg.height)){
            display->topY--;
        }
        if(display->bottomY < ofGetHeight()){
            display->bottomY++;
        }
        if(display->alpha > 0){
            display->alpha -= 0.08;
        }
        
        if(gameOverTime == 0){
            gameOverTime = ofGetElapsedTimeMillis()-timeStarted;
        }
        
        int currentTime = ofGetElapsedTimeMillis()-timeStarted;
        if(/*(arduino.getDigital(4) == 1 || arduino.getDigital(5) == 1)*/ (keys[356] == true || keys[358] == true) && currentTime > (gameOverTime+3000)){
            gameOverTime = 0;
            
            timeStarted = currentTime + timeStarted;
            background->setDefault();
            player->setDefault();
            objects->setDefault();
            display->setDefault();
            countDown->setDefault(round(controlDelay/1000));
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
    if(!player->gameHasStarted){
        countDown->draw();
    }
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

