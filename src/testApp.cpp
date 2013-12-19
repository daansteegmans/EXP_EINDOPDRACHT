#include "testApp.h"
#include <time.h>

//--------------------------------------------------------------
void testApp::setup()
{
    ofAddListener(arduino.EInitialized, this, &testApp::setupArduino);
    arduino.connect("/dev/tty.usbmodem1411", 57600);
    
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
    coinsGroupsMade = 0;
    blinkOn = false;
    startBlinking = false;
    timeArduinoInitialized = 0;
    
    lastPowerUpActivated = 0;
    powerUpsMade = 0;
    shieldActivated = false;
    batteryActivated = false;
    doubleActivated = false;
    
    boostsMade = 0;
    
    backgroundMusic.loadSound("music/awesomearcademusic.mp3");
    bgMusicIsPlaying = false;
    coinSound.loadSound("sounds/coin.mp3");
    gameOverSound.loadSound("sounds/gameover.mp3");
    getPowerUpSound.loadSound("sounds/getpowerup.mp3");
    activateShieldSound.loadSound("sounds/activateshield.mp3");
    activateBatterySound.loadSound("sounds/activatebattery.mp3");
    activateDoubleSound.loadSound("sounds/activatedouble.mp3");
}

void testApp::startUpBlink(){
    if(blinkOn){
        arduino.sendDigital(10, ARD_LOW);
        arduino.sendDigital(11, ARD_LOW);
        arduino.sendDigital(12, ARD_LOW);
        arduino.sendDigital(13, ARD_LOW);
    }else{
        arduino.sendDigital(10, ARD_HIGH);
        arduino.sendDigital(11, ARD_HIGH);
        arduino.sendDigital(12, ARD_HIGH);
        arduino.sendDigital(13, ARD_HIGH);
    }
    blinkOn = !blinkOn;
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
    
    startBlinking = true;
    timeArduinoInitialized = ofGetElapsedTimeMillis();
}

//--------------------------------------------------------------
void testApp::update()
{
    arduino.update();
    player->currentSpriteSheetFrame+=0.3;
    
    //startup blinking
    if(startBlinking && numBlinks < 6 && ofGetElapsedTimeMillis() - timeArduinoInitialized >  150*(numBlinks*2)){
        testApp::startUpBlink();
        numBlinks++;
    }
    if(numBlinks>=6)startBlinking = false;
    
    //play background music
    if(backgroundMusic.isLoaded() && !bgMusicIsPlaying){
        cout << "music loaded" << endl;
        backgroundMusic.play();
        backgroundMusic.setLoop(true);
        bgMusicIsPlaying = !bgMusicIsPlaying;
    }
    
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
                    coinSound.play();
                    for(int j=0; j<objects->coins.size(); j++){
                        if(objects->coins[j] != objects->coins[i]){
                            coins.push_back(objects->coins[j]);
                        }
                    }
                    objects->coins = coins;
                    if(doubleActivated){
                        display->coins+=2;
                    }else{
                        display->coins++;
                    }
                }
            }
            
            for(int i=0; i<objects->powerups.size(); i++){
                if(functions->checkCollisionPowerup(player, objects->powerups[i]) != "no collision" && display->powerupNames.size() < display->maxPowerups){
                    vector<Powerup *> powerups;
                    getPowerUpSound.play();
                    for(int j=0; j<objects->powerups.size(); j++){
                        if(objects->powerups[j] != objects->powerups[i]){
                            powerups.push_back(objects->powerups[j]);
                        }
                    }
                    switch(display->powerupNames.size()){
                        case 0:
                            if(objects->powerups[i]->name == "shield"){
                                display->iconPowerUp1Shown = display->iconPowerUpShield;
                                display->powerUp1Text = "shield";
                            }else if(objects->powerups[i]->name == "battery"){
                                display->iconPowerUp1Shown = display->iconPowerUpBattery;
                                display->powerUp1Text = "battery";
                            }else if(objects->powerups[i]->name == "double"){
                                display->iconPowerUp1Shown = display->iconPowerUpDouble;
                                display->powerUp1Text = "double";
                            }
                            display->iconPowerUp1OffsetY = 18;
                            break;
                        case 1:
                            if(objects->powerups[i]->name == "shield"){
                                display->iconPowerUp2Shown = display->iconPowerUpShield;
                                display->powerUp2Text = "shield";
                            }else if(objects->powerups[i]->name == "battery"){
                                display->iconPowerUp2Shown = display->iconPowerUpBattery;
                                display->powerUp2Text = "battery";
                            }else if(objects->powerups[i]->name == "double"){
                                display->iconPowerUp2Shown = display->iconPowerUpDouble;
                                display->powerUp2Text = "double";
                            }
                            display->iconPowerUp2OffsetY = 18;
                            break;
                        case 2:
                            if(objects->powerups[i]->name == "shield"){
                                display->iconPowerUp3Shown = display->iconPowerUpShield;
                                display->powerUp3Text = "shield";
                            }else if(objects->powerups[i]->name == "battery"){
                                display->iconPowerUp3Shown = display->iconPowerUpBattery;
                                display->powerUp3Text = "battery";
                            }else if(objects->powerups[i]->name == "double"){
                                display->iconPowerUp3Shown = display->iconPowerUpDouble;
                                display->powerUp3Text = "double";
                            }
                            display->iconPowerUp3OffsetY = 18;
                            break;
                    }
                    display->powerupNames.push_back(objects->powerups[i]->name);
                    objects->powerups = powerups;
                }
            }
            
            arduino.sendDigital(10, ARD_LOW);
            if(lastPowerUpActivated!=0 && ofGetElapsedTimeMillis() > lastPowerUpActivated + 5000){
                shieldActivated = false;
                batteryActivated = false;
                doubleActivated = false;
                arduino.sendDigital(10, ARD_HIGH);
            }
            
            //POWERUPS
            if(arduino.getDigital(3) == 1 /*keys[32] == true && ofGetElapsedTimeMillis()*/ > lastPowerUpActivated + 5000 && lastPowerUpActivated!=0){
                cout << "powerup activated: " << display->powerupNames[0] << endl;
                lastPowerUpActivated = ofGetElapsedTimeMillis();
                
                if(display->powerupNames[0] == "shield"){
                    activateShieldSound.play();
                    shieldActivated = true;
                }else if(display->powerupNames[0] == "battery"){
                    activateBatterySound.play();
                    batteryActivated = true;
                }else if(display->powerupNames[0] == "double"){
                    activateDoubleSound.play();
                    doubleActivated = true;
                }
                
                switch(display->powerupNames.size()){
                    case 1:
                        display->iconPowerUp1Shown = display->iconEmpty1;
                        display->iconPowerUp1OffsetY = 0;
                        display->powerUp1Text = "leeg";
                        break;
                    case 2:
                        display->iconPowerUp1Shown = display->iconPowerUp2Shown;
                        display->iconPowerUp2Shown = display->iconEmpty2;
                        display->iconPowerUp2OffsetY = 0;
                        display->powerUp1Text = display->powerUp2Text;
                        display->powerUp2Text = "leeg";
                        break;
                    case 3:
                        display->iconPowerUp1Shown = display->iconPowerUp2Shown;
                        display->iconPowerUp2Shown = display->iconPowerUp3Shown;
                        display->iconPowerUp3Shown = display->iconEmpty3;
                        display->iconPowerUp3OffsetY = 0;
                        display->powerUp1Text = display->powerUp2Text;
                        display->powerUp2Text = display->powerUp3Text;
                        display->powerUp3Text = "leeg";
                        break;
                }
                
                vector<string> powerupNames;
                for(int i=0; i<display->powerupNames.size(); i++){
                    if(i!=0){
                        powerupNames.push_back(display->powerupNames[i]);
                    }
                }
                display->powerupNames = powerupNames;
            }
            
            if(batteryActivated){
                display->fuel-= (background->speedY/50)*0.3;
            }else{
                display->fuel-= background->speedY/50;
            }
    
            //BOOST
            if(arduino.getDigital(4) == 1 && arduino.getDigital(5) == 1 /*keys[356] == true && keys[358] == true*/){
                player->action = "boost";
                background->speedY += 0.3;
                background->speedX = 0;
                objects->velX = 0;
                objects->velY = 6.5;
                display->speed = round((background->speedY*10)*2);
        
                if(player->y > player->minY)player->velY += 0.07;
        
                arduino.sendDigital(11, ARD_HIGH);
                arduino.sendDigital(12, ARD_HIGH);
                arduino.sendDigital(13, ARD_HIGH);
            }else{
                objects->velX = 0;
                objects->velY = 3.5;
                if(round(background->speedY*50) < (background->maxSpeedY*15)*2){
                    if(round(background->speedY*50) > 65){
                        display->speed = round(background->speedY*25);
                    }else{
                        display->speed = round(background->speedY*50);
                    }
                }else{
                    display->speed--;
                }
                
                if(player->y < player->defaultY){
                    player->velY -= 0.1;
                } else {
                    player->velY = 0;
                }
                
                if(!startBlinking){
                    arduino.sendDigital(11, ARD_LOW);
                    arduino.sendDigital(12, ARD_LOW);
                    arduino.sendDigital(13, ARD_LOW);
                }
        
                //LEFT
                if(arduino.getDigital(4) == 1 /*keys[356] == true*/){
                    player->velY += 0.15;
                    arduino.sendDigital(11, ARD_LOW);
                    arduino.sendDigital(12, ARD_HIGH);
                    arduino.sendDigital(13, ARD_LOW);

                    if(background->speedY < background->manoeuvreSpeedY){
                        background->speedY += 0.2;
                    }else{
                        background->speedY -= 0.05;
                    }
                    if(background->x < -30){
                        background->speedX = 3;
                        objects->velX = 5.2;
                        player->action = "left";
                    }else if(background->x > -0.1){
                        background->x = 0;
                        background->speedX = 0;
                    }else{
                        background->speedX *= 0.8;
                    }
                }
        
                //RIGHT
                if(arduino.getDigital(5) == 1 /*keys[358] == true*/){
                    player->velY += 0.15;
                    arduino.sendDigital(11, ARD_LOW);
                    arduino.sendDigital(12, ARD_LOW);
                    arduino.sendDigital(13, ARD_HIGH);
                    
                    if(background->speedY < background->manoeuvreSpeedY){
                        background->speedY += 0.2;
                    }else{
                        background->speedY -= 0.05;
                    }
                    if(background->x > -background->img.width + ofGetWidth() +30){
                        background->speedX = -3;
                        objects->velX = -5.2;
                        player->action = "right";
                    }else if(background->x < -background->img.width + ofGetWidth() + 0.1){
                        background->x = -background->img.width + ofGetWidth();
                        background->speedX = 0;
                    }else{
                        background->speedX *= 0.8;
                    }
                }
        
                //NOTHING
                if(arduino.getDigital(4) != 1 && arduino.getDigital(5) != 1 /*keys[356] == false && keys[358] == false*/){
                    background->speedX = 0;
                    background->speedY -= 0.05;
                    player->action = "normal_ascend";
                }
            }
    
            objects->update();
        }
        
        //object generating
        int backgroundOriginalY = -background->img.getHeight()*2 + ofGetHeight();
        if(background->y > backgroundOriginalY + 800 + 600*boostsMade){
            if(background->x > -ofGetWidth()/2){
                int maxRandom = ofGetWidth() - (ofGetWidth()/2 + round(background->x)) - 50;
                objects->makeBoost((rand() % maxRandom) + ofGetWidth()/2 + background->x);
            }else if(background->x < -background->img.width + ofGetWidth() + ofGetWidth()/2){
                int maxRandom = ofGetWidth() - abs(-background->img.width + ofGetWidth() + ofGetWidth()/2) - 100;
                objects->makeBoost((rand() % maxRandom) + 50);
            }else{
                objects->makeBoost((rand() % ofGetWidth() - 200) + 100);
            }
            boostsMade++;
        }
        
        if(background->y > backgroundOriginalY + 1100*powerUpsMade){
            if(background->x > -ofGetWidth()/2){
                int maxRandom = ofGetWidth() - (ofGetWidth()/2 + round(background->x)) - 50;
                objects->makePowerup((rand() % maxRandom) + ofGetWidth()/2 + background->x);
            }else if(background->x < -background->img.width + ofGetWidth() + ofGetWidth()/2){
                int maxRandom = ofGetWidth() - abs(-background->img.width + ofGetWidth() + ofGetWidth()/2) - 100;
                objects->makePowerup((rand() % maxRandom) + 50);
            }else{
                objects->makePowerup((rand() % ofGetWidth() - 200) + 100);
            }
            powerUpsMade++;
        }
        
        if(background->y > backgroundOriginalY + 900*coinsGroupsMade){
            if(background->x > -ofGetWidth()/2){
                int maxRandom = ofGetWidth() - (ofGetWidth()/2 + round(background->x)) - 50;
                objects->makeCoinGroup((rand() % maxRandom) - ofGetWidth()/2 + ofGetWidth()/2 + background->x);
            }else if(background->x < -background->img.width + ofGetWidth() + ofGetWidth()/2){
                int maxRandom = ofGetWidth() - abs(-background->img.width + ofGetWidth() + ofGetWidth()/2) - 100;
                objects->makeCoinGroup((rand() % maxRandom) - ofGetWidth()/2 + 50);
            }else{
                objects->makeCoinGroup((rand() % ofGetWidth() - 200) - ofGetWidth()/2 + 100);
            }
            coinsGroupsMade++;
        }
        
        if(!player->gameHasStarted){
            countDown->update();
            if(ofGetElapsedTimeMillis() > timeStarted+startDelay){
                background->update();
            }
        }else{
            background->update();
        }
        
        display->altitude += background->speedY;
        display->altitude = round(display->altitude);
        display->temperature -= (background->speedY*0.08);
        display->update();
    }else{
        if(display->fuel <= 0 && causeOfGameOver == ""){
            causeOfGameOver = "fuel";
        }else if(display->health <= 0 && causeOfGameOver == ""){
            causeOfGameOver = "health";
        }
        
        player->velX = 0;
        if(player->alpha > 0) player->alpha-=0.01;
        
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
            cout << "game over" << endl;
            gameOverSound.play();
            gameOverTime = ofGetElapsedTimeMillis()-timeStarted;
            player->gameOver = true;
            menu = new Menu(true, causeOfGameOver, display->altitude, display->maxSpeed, display->time, display->coins, objects->numTotalCoins);
            numBlinks = 0;
            display->alarmSound.stop();
            
            arduino.sendDigital(11, ARD_LOW);
            arduino.sendDigital(12, ARD_LOW);
            arduino.sendDigital(13, ARD_LOW);
        }
        
        if(numBlinks < 6 && ofGetElapsedTimeMillis() - gameOverTime - timeStarted >  500 + 150*(numBlinks*2) && gameOverTime != 0){
            //testApp::startUpBlink();
            numBlinks++;
        }
        
        if(menu->alpha < 1.9){
            menu->alpha += 0.03;
        }
        
        int currentTime = ofGetElapsedTimeMillis()-timeStarted;
        if((arduino.getDigital(3) == 1 || arduino.getDigital(4) == 1 || arduino.getDigital(5) == 1) /*(keys[356] == true || keys[358] == true)*/ && currentTime > (gameOverTime+3000)){
            gameOverTime = 0;
            causeOfGameOver = "";
            coinsGroupsMade = 0;
            
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
    if(gameOverTime == 0) objects->draw();
    if(player->y > -player->img.height)player->draw();
    if(gameOverTime != 0)menu->draw();
    display->draw();
    if(!player->gameHasStarted) countDown->draw();
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

