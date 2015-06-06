#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H
#include <SFML/Graphics/Texture.hpp>
using namespace sf;
class TextureLoader
{
    public:
        static void init();
        static Texture& getMyplaneTexture();
        static Texture& getEnemyTextture1();
        static Texture& getEnemyTextture2();
        static Texture& getGunTextture();
        static Texture& getEnemy2TexttureAnim(int time);

        static Texture& getEnemyGunTextture();
    protected:
    private:
        static sf::Texture enemy2Textture1;
        static sf::Texture enemy2Textture2;
        static sf::Texture enemy2Textture3;

        static sf::Texture enemyTextture1;
        static sf::Texture enemyTextture2;
        static sf::Texture gunTextture;
        static sf::Texture myplaneTexture;
        static sf::Texture enemyGunTexture;
};

#endif // TEXTURELOADER_H
