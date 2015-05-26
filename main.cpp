#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <cstdlib>
#include <ctime>
#include "MyGun.h"
using namespace std;
unsigned int gunNum=0;
int main(){

    sf::RenderWindow window(sf::VideoMode(600, 840), "plane");

    sf::Texture texture;
    texture.loadFromFile("myplane.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(250, 700));
    sf::Music music;
    music.openFromFile("music.ogg");
    music.play();
    MyGun *myGunList[50];

    for(int i=0;i<50;i++){
        MyGun *myGun = new MyGun();
        myGunList[i]=myGun;
    }



    sf::Texture gunTextture;
    gunTextture.loadFromFile("mygun.png");
    while (window.isOpen())
    {
        float planePosi;
        planePosi=sprite.getPosition().x;
        //×óÓÒÒÆ¶¯
        if(planePosi<550&&planePosi>-30){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
                sprite.move(1, 0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
                sprite.move(-1, 0);
            }
        }else if(planePosi<=-30){
            sprite.setPosition(sf::Vector2f(-29, 700));
        }else{
            sprite.setPosition(sf::Vector2f(549, 700));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            printf("x");

            if(gunNum-1>=0&&myGunList[gunNum-1]->exist&&myGunList[gunNum]->exist==false&&myGunList[gunNum]->getPosition().y>620){
                if(gunNum>48)
                    gunNum=0;
                gunNum++;
                printf("y");
                myGunList[gunNum]->exist=true;
                myGunList[gunNum]->setTexture(gunTextture);
                myGunList[gunNum]->setPosition(sf::Vector2f(sprite.getPosition().x+35, 660));
            }else if(gunNum-1>=0&&myGunList[gunNum]->exist==false&&!myGunList[gunNum-1]->exist){
                if(gunNum>48)
                    gunNum=0;
                gunNum++;
                printf("z");
                myGunList[gunNum]->exist=true;
                myGunList[gunNum]->setTexture(gunTextture);
                myGunList[gunNum]->setPosition(sf::Vector2f(sprite.getPosition().x+35, 660));
            }else if(gunNum-1>=0&&myGunList[gunNum]->exist==false&&!myGunList[gunNum-1]->exist){
                if(gunNum>48)
                    gunNum=0;
                gunNum++;
                printf("z");
                myGunList[gunNum]->exist=true;
                myGunList[gunNum]->setTexture(gunTextture);
                myGunList[gunNum]->setPosition(sf::Vector2f(sprite.getPosition().x+35, 660));
            }
        }

        //ÒÆ¶¯
        for(int i=0;i<=49;i++){
            if(myGunList[i]->exist){
                myGunList[i]->move(0 , -0.5);
            }
        }
        //Åö×²¼ì²â

        window.clear(sf::Color::White);
        window.draw(sprite);
        for(int i=0;i<50;i++){
            if(myGunList[i]->exist){
                if(myGunList[i]->getPosition().y>700){
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
