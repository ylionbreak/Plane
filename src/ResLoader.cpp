#include "ResLoader.h"

sf::Font ResLoader::microBlack;
sf::SoundBuffer ResLoader::bang;
sf::SoundBuffer ResLoader::pia;

void ResLoader::init(){
        microBlack.loadFromFile("msyh.ttf");
        bang.loadFromFile("bang.wav");
        pia.loadFromFile("pia.wav");
}
Font& ResLoader::getMicroBlack(){
    return microBlack;
}
SoundBuffer& ResLoader::getbang(){
    return bang;
}
SoundBuffer& ResLoader::getpia(){
    return pia;
}
