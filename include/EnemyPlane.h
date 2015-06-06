#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include "TextureLoader.h"
#include <iostream>
#include <cstdlib>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
using namespace sf;
using namespace std;
class EnemyPlane : public Sprite{
    public:
        Clock clock;
        Clock shootClock;
        EnemyPlane();
        bool exist=false;
        void initLifePoint(int _lifePoint);
        void hitted();
        void playAnim();
        int getLifePoint();
        int getMaxLifePoint();
        int getAnimTime();
        bool shoot();
    private:
        int maxLifePoint;
        int lifePoint;
        int animTime;
        int MaxAnimTime;
        int time;
};

#endif
