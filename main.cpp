#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "MyPlane.h"
#include "MyGun.h"
#include "TextureLoader.h"
#include "EnemyPlane.h"
#include "ScoreText.h"
#include "EnemyGun.h"
using namespace std;
unsigned int gunNum=1;
unsigned int planeMaxNum=5;
unsigned int planeNum=0;
unsigned int enemyGunNum=0;
int main(){
    sf::RenderWindow window(sf::VideoMode(600, 840), "plane");
    sf::Music music;
    music.openFromFile("music.ogg");
    music.play();
    srand((unsigned)time(0));
    TextureLoader::init();
    //字体
    Font font;
    font.loadFromFile("msyh.ttf");
    ScoreText score(1);
    score.setFont(font);
    //声音
    sf::SoundBuffer bangBuffer;
    bangBuffer.loadFromFile("bang.wav");
    sf::Sound breakSound;
    breakSound.setBuffer(bangBuffer);
    sf::SoundBuffer piaBuffer;
    piaBuffer.loadFromFile("pia.wav");
    sf::Sound hitSound;
    hitSound.setBuffer(piaBuffer);
    //
    MyPlane myPlane;
    myPlane.setTexture(TextureLoader::getMyplaneTexture());
    myPlane.setPosition(sf::Vector2f(250, 700));
    MyGun *myGunList[50];
    EnemyPlane *enemyPlaneList[30];
    EnemyGun *enemyGunList[200];
    for(int i=0;i<30;i++){
        EnemyPlane *enemyPlane = new EnemyPlane();
        enemyPlaneList[i]=enemyPlane;
    }
    for(int i=0;i<50;i++){
        MyGun *myGun = new MyGun();
        myGunList[i]=myGun;
        myGunList[i]->setTexture(TextureLoader::getGunTextture());
    }
    for(int i=0;i<200;i++){
        EnemyGun *enemyGun = new EnemyGun();
        enemyGunList[i]=enemyGun;
        enemyGunList[i]->setTexture(TextureLoader::getEnemyGunTextture());
    }
    window.setFramerateLimit(60);
    while (window.isOpen()){
        if(myPlane.getLife()>0){
            float planePosi;
            planePosi=myPlane.getPosition().x;
            if(planePosi<550&&planePosi>-30){
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                    myPlane.move(10, 0);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                    myPlane.move(-10, 0);
                }
            }else if(planePosi<=-30){
                myPlane.setPosition(sf::Vector2f(-29, 700));
            }else{
                myPlane.setPosition(sf::Vector2f(549, 700));
            }
            //子弹
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                //first one
                if(gunNum==1){
                    myGunList[gunNum]->exist=true;
                    myGunList[gunNum]->setPosition(sf::Vector2f(myPlane.getPosition().x+35, 660));
                    gunNum++;
                    if(gunNum>47)
                        gunNum=1;
                }//other,this don't exist,before fly away
                else if(myGunList[gunNum]->exist==false&&myGunList[gunNum-1]->exist&&myGunList[gunNum-1]->getPosition().y<600){
                    myGunList[gunNum]->exist=true;
                    myGunList[gunNum]->setPosition(sf::Vector2f(myPlane.getPosition().x+35, 660));
                    gunNum++;
                    if(gunNum>47)
                        gunNum=1;
                }else if(!myGunList[gunNum]->exist&&!myGunList[gunNum-1]->exist){
                    myGunList[gunNum]->exist=true;
                    myGunList[gunNum]->setPosition(sf::Vector2f(myPlane.getPosition().x+35, 660));
                    gunNum++;
                    if(gunNum>47)
                        gunNum=1;
                }
            }
            for(int i=0;i<=49;i++){
                if(myGunList[i]->exist){
                    myGunList[i]->move(0 , -5);
                }
            }
            //敌机子弹
            for(int i=0;i<planeMaxNum;i++){
                if(enemyGunNum>199)
                        enemyGunNum=0;
                if(enemyPlaneList[i]->exist&&enemyPlaneList[i]->getMaxLifePoint()>1&&enemyPlaneList[i]->shoot()&&enemyPlaneList[i]->getLifePoint()>0){
                    enemyGunList[enemyGunNum]->exist=true;
                    enemyGunList[enemyGunNum]->setPosition(enemyPlaneList[i]->getPosition().x+25,enemyPlaneList[i]->getPosition().y+100);
                    enemyGunNum++;
                }
            }
            for(int i=0;i<200;i++){
                enemyGunList[i]->move( 0, 6);
            }
            //飞机
            if(rand()%30==3&&planeNum<planeMaxNum){
                for(int i=0;i<planeMaxNum;i++){
                    if(!enemyPlaneList[i]->exist){
                        enemyPlaneList[i]->exist=true;
                        if(rand()%2==0){
                            enemyPlaneList[i]->setTexture(TextureLoader::getEnemyTextture1(),true);
                            enemyPlaneList[i]->initLifePoint(1);
                        }else{
                            enemyPlaneList[i]->setTexture(TextureLoader::getEnemyTextture2(),true);
                            enemyPlaneList[i]->initLifePoint(3);
                            enemyPlaneList[i]->shootClock.restart();
                        }
                        enemyPlaneList[i]->setPosition(sf::Vector2f(rand()%400+50, -100));
                        planeNum++;
                        break;
                    }
                }
            }
            for(int i=0;i<planeMaxNum;i++){
                if(enemyPlaneList[i]->exist&&enemyPlaneList[i]->getLifePoint()>0){
                    enemyPlaneList[i]->move( 0, 4);
                }
            }
            //碰撞
            for(int i=0;i<planeMaxNum;i++){
                if(enemyPlaneList[i]->exist){
                    for(int j=0;j<50;j++){
                        if(myGunList[j]->exist){
                            if( enemyPlaneList[i]->getGlobalBounds().intersects(myGunList[j]->getGlobalBounds()) ){
                                if(enemyPlaneList[i]->exist){
                                        if(enemyPlaneList[i]->getLifePoint()>0&&enemyPlaneList[i]->getMaxLifePoint()>1){
                                            enemyPlaneList[i]->hitted();
                                            enemyPlaneList[i]->clock.restart();
                                            myGunList[j]->exist=false;
                                            hitSound.play();
                                        }else if(enemyPlaneList[i]->getMaxLifePoint()==1){
                                            myGunList[j]->exist=false;
                                            enemyPlaneList[i]->exist=false;
                                            planeNum--;
                                            breakSound.play();
                                            score.addScore(1);
                                        }
                                }
                            }
                        }
                    }
                }
            }
            //飞机碰撞
            for(int i=0;i<planeMaxNum;i++){
                if(enemyPlaneList[i]->exist){
                    for(int j=0;j<199;j++){
                        if( enemyGunList[j]->exist ){
                            if( enemyGunList[j]->getGlobalBounds().intersects( myPlane.getGlobalBounds() ) ){
                                myPlane.hitted();
                                enemyGunList[j]->exist=false;
                            }
                        }
                    }
                    if( enemyPlaneList[i]->getGlobalBounds().intersects( myPlane.getGlobalBounds() ) ){
                        enemyPlaneList[i]->exist=false;
                        myPlane.hitted();
                    }
                }
            }
            //绘制
            window.clear(sf::Color::White);
            window.draw(myPlane);
            //存在的飞机
            for(int i=0;i<planeMaxNum;i++){
                if(enemyPlaneList[i]->exist&&enemyPlaneList[i]->getLifePoint()>0){
                    if(enemyPlaneList[i]->getPosition().y>840){
                        enemyPlaneList[i]->exist=false;
                        planeNum--;
                    }
                    if(enemyPlaneList[i]->exist)
                        window.draw(*enemyPlaneList[i]);
                }
            }
            for(int i=0;i<200;i++){
                if(enemyGunList[i]->exist)
                    window.draw(*enemyGunList[i]);
            }
            //子弹
            for(int i=0;i<50;i++){
                if(myGunList[i]->exist){
                    if(myGunList[i]->getPosition().y<0){
                        myGunList[i]->exist=false;
                    }
                    if(myGunList[i]->exist)
                        window.draw(*myGunList[i]);
                }
            }
            //飞机动画
            for(int i=0;i<planeMaxNum;i++){
                if(enemyPlaneList[i]->exist&&enemyPlaneList[i]->getLifePoint()==0){
                    enemyPlaneList[i]->playAnim();
                    window.draw(*enemyPlaneList[i]);
                    if(enemyPlaneList[i]->getAnimTime()==0){
                        breakSound.play();
                        score.addScore(1);
                        enemyPlaneList[i]->exist=false;
                        planeNum--;
                    }
                }
            }
            window.draw(score);

            window.display();
            sf::Event event;
            while (window.pollEvent(event)){
                if (event.type == sf::Event::Closed)
                    window.close();
            }
        }else{
            window.clear(sf::Color::White);
            ScoreText deadText(2);
            deadText.setFont(font);
            deadText.setPosition(225,350);
            window.draw(deadText);
            window.display();
        }
    }
    return 0;
}
