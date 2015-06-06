#include "TextureLoader.h"

sf::Texture TextureLoader::enemy2Textture1;
sf::Texture TextureLoader::enemy2Textture2;
sf::Texture TextureLoader::enemy2Textture3;
sf::Texture TextureLoader::enemyTextture1;
sf::Texture TextureLoader::enemyTextture2;
sf::Texture TextureLoader::gunTextture;
sf::Texture TextureLoader::myplaneTexture;
sf::Texture TextureLoader::enemyGunTexture;
void TextureLoader::init(){
        enemyTextture1.loadFromFile("enemy1.png");
        enemyTextture2.loadFromFile("enemy2.png");
        gunTextture.loadFromFile("mygun.png");
        myplaneTexture.loadFromFile("myplane.png");
        enemy2Textture1.loadFromFile("enemy21.png");
        enemy2Textture2.loadFromFile("enemy22.png");
        enemy2Textture3.loadFromFile("enemy23.png");
        enemyGunTexture.loadFromFile("enemygun.png");

}
Texture& TextureLoader::getMyplaneTexture(){
    return myplaneTexture;
}
Texture& TextureLoader::getEnemyTextture1(){
    return enemyTextture1;
}
Texture& TextureLoader::getEnemyTextture2(){
    return enemyTextture2;
}
Texture& TextureLoader::getGunTextture(){
    return gunTextture;
}
Texture& TextureLoader::getEnemyGunTextture(){
    return enemyGunTexture;
}
Texture& TextureLoader::getEnemy2TexttureAnim(int time){
    if(time==0){
        return enemy2Textture1;
    }else if(time==1){
        return enemy2Textture2;
    }else if(time==2){
        return enemy2Textture2;
    }else if(time==3){
        return enemy2Textture2;
    }
}
