#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <cstdlib>
#include <ctime>
#include "MyGun.h"
#include "EnemyPlane.h"
using namespace std;
unsigned int gunNum=1;
unsigned int planeMaxNum=5;
unsigned int planeNum=0;
int main(){

    sf::RenderWindow window(sf::VideoMode(600, 840), "plane");
    sf::Music music;
    music.openFromFile("music.ogg");
    music.play();
    srand((unsigned)time(0));
    rand();

    sf::Texture myplaneTexture;
    myplaneTexture.loadFromFile("myplane.png");
    sf::Texture enemyTextture;
    enemyTextture.loadFromFile("enemy1.png");
    sf::Texture gunTextture;
    gunTextture.loadFromFile("mygun.png");

    sf::Sprite myPlane;
    myPlane.setTexture(myplaneTexture);
    myPlane.setPosition(sf::Vector2f(250, 700));
    MyGun *myGunList[50];
    EnemyPlane *enemyPlaneList[30];

    for(int i=0;i<30;i++){
        EnemyPlane *enemyPlane = new EnemyPlane();
        enemyPlaneList[i]=enemyPlane;
        enemyPlaneList[i]->setTexture(enemyTextture);
    }
    for(int i=0;i<50;i++){
        MyGun *myGun = new MyGun();
        myGunList[i]=myGun;
        myGunList[i]->setTexture(gunTextture);
    }
    window.setFramerateLimit(60);
    while (window.isOpen()){
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
        //飞机
        if(rand()%50==5&&planeNum<planeMaxNum){
            //printf("x");
            for(int i=0;i<planeMaxNum;i++){
                if(!enemyPlaneList[i]->exist){
                    enemyPlaneList[i]->exist=true;
                    enemyPlaneList[i]->setPosition(sf::Vector2f(rand()%400+50, -100));
                    planeNum++;
                    break;
                }
            }

        }
        for(int i=0;i<planeMaxNum;i++){
            if(enemyPlaneList[i]->exist){
                enemyPlaneList[i]->move( 0, 5);
            }
        }
        //碰撞
        for(int i=0;i<planeMaxNum;i++){
            if(enemyPlaneList[i]->exist){
                for(int j=0;j<50;j++){
                    if(myGunList[j]->exist){
                        if( enemyPlaneList[i]->getGlobalBounds().intersects(myGunList[j]->getGlobalBounds()) ){
                            myGunList[j]->exist=false;
                            enemyPlaneList[i]->exist=false;
                            planeNum--;
                        }

                    }
                }
            }
        }
        //绘制
        window.clear(sf::Color::White);
        window.draw(myPlane);
        for(int i=0;i<planeMaxNum;i++){
            if(enemyPlaneList[i]->exist){
                if(enemyPlaneList[i]->getPosition().y>840){
                    enemyPlaneList[i]->exist=false;
                    planeNum--;
                }
                if(enemyPlaneList[i]->exist)
                    window.draw(*enemyPlaneList[i]);
            }
        }
        for(int i=0;i<50;i++){
            if(myGunList[i]->exist){
                if(myGunList[i]->getPosition().y<0){
                    myGunList[i]->exist=false;
                }
                if(myGunList[i]->exist)
                    window.draw(*myGunList[i]);
            }
        }
        window.display();
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    return 0;

}
