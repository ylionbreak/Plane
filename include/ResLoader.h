#ifndef RESLOADER_H
#define RESLOADER_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

class ResLoader{
    public:
        static void init();
        static Font& getMicroBlack();
        static SoundBuffer& getbang();
        static SoundBuffer& getpia();
    protected:
    private:
        static sf::Font microBlack;
        static sf::SoundBuffer bang;
        static sf::SoundBuffer pia;
};

#endif // RESLOADER_H
