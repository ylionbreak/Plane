#ifndef ENEMYGUN_H
#define ENEMYGUN_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
using namespace sf;

class EnemyGun : public Sprite{
    public:
        EnemyGun();
        bool exist=false;
    protected:
    private:
};

#endif // ENEMYGUN_H
