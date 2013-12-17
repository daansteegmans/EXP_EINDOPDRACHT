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
    
    causeOfGameOver = "";
}

void testApp::setupArduino(const int &version){
    ofRemoveListener(arduino.EInitialized, this, &testApp::setupArduino);
    ofLog() << "setup arduino " << version;
    arduino.sendDigitalPinMode(3, ARD_INPUT);
    arduino.sendDigitalPinMode(4, ARD_INPUT);
    arduino.sendDigitalPinMode(5, ARD_INPUT);
    
    arduino.sendDigitalPinMode(10, ARD_OUTPUT);
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
            
            if(display->speed < display->defaultSpeed){
                display->speed = round((display->speed+0.3)*10)/10;
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
    
            if(/*arduino.getDigital(4) == 1 && arduino.getDigital(5) == 1*/ keys[356] == true && keys[358] == true){
                background->speedY += 0.3;
                background->speedX = 0;
                objects->velX = 0;
                objects->velY = 4.5;
                //display->fuel-=0.08;
                display->fuel-=0.7;
                display->speed = round((background->speedY*10)*2);
        
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
                if(round(background->speedY*50) < (background->maxSpeedY*10)*2){
                    display->speed = round(background->speedY*50);
                }else{
                    display->speed--;
                }
                
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
    
            display->altitude += round(background->speedY/60);
            cout << background->speedY << endl;
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
    }else{
        /*arduino.sendDigital(11, ARD_LOW);
        arduino.sendDigital(12, ARD_LOW);
        arduino.sendDigital(13, ARD_LOW);*/
        
        if(display->fuel <= 0 && causeOfGameOver == ""){
            causeOfGameOver = "fuel";
        }else if(display->health <= 0 && causeOfGameOver == ""){
            causeOfGameOver = "health";
        }
        
        player->velX = 0;
        
        if(display->topY > -(display->topBg.height)){
            display->topY-=0.5;
        }
        if(display->bottomY < ofGetHeight()){
            display->bottomY+=0.5;
        }
        if(display->alpha > 0){
            display->alpha -= 0.04;
        }
        
        if(gameOverTime == 0){
            gameOverTime = ofGetElapsedTimeMillis()-timeStarted;
            player->gameOver = true;
            menu = new Menu(true, causeOfGameOver, display->altitude, display->maxSpeed, display->time, display->coins);
        }
        
        if(menu->alpha < 1.9){
            menu->alpha += 0.03;
        }
        
        int currentTime = ofGetElapsedTimeMillis()-timeStarted;
        if(/*(arduino.getDigital(3) == 1 || arduino.getDigital(4) == 1 || arduino.getDigital(5) == 1)*/ (keys[356] == true || keys[358] == true) && currentTime > (gameOverTime+3000)){
            gameOverTime = 0;
            causeOfGameOver = "";
            
            timeStarted = currentTime + timeStarted;
            background->setDefault();
            player->setDefault();
            objects->setDefault();
            display->setDefault();
            countDown->setDefault(round(controlDelay/1000));
        }
        
        menu->update();
    }
    if(player->y > -player->img.height)player->update();
}

//--------------------------------------------------------------
void testApp::draw()
{
    background->draw();
    if(player->y > -player->img.height)player->draw();
    if(gameOverTime != 0){
        menu->draw();
    }else{
        objects->draw();
    }
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

