#ifndef MYPLANE_H
#define MYPLANE_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
using namespace sf;

class MyPlane: public Sprite{

    public:
       MyPlane();
       int getLife();
       void hitted();
    protected:
    private:
        int life;
};

#endif // MYPLANE_H
