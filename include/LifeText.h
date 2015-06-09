#ifndef LIFETEXT_H
#define LIFETEXT_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
using namespace std;
using namespace sf;

class LifeText: public Text{
    public:
        LifeText();
        void setLifeText(int life);
    protected:
    private:
};

#endif // LIFETEXT_H
