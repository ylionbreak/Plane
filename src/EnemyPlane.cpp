#include "EnemyPlane.h"

EnemyPlane::EnemyPlane(){
}
void EnemyPlane::initLifePoint(int _lifePoint){
    lifePoint=_lifePoint;
    maxLifePoint=_lifePoint;
    if(maxLifePoint>1){
        animTime=3;
        MaxAnimTime=3;
        time=0;
    }
}
int EnemyPlane::getLifePoint(){
    return lifePoint;
}
void EnemyPlane::hitted(){
    if(lifePoint>0)
        lifePoint--;
}
int EnemyPlane::getMaxLifePoint(){
    return maxLifePoint;
}
int EnemyPlane::getAnimTime(){
    return animTime;
}
void EnemyPlane::playAnim(){
    if(clock.getElapsedTime().asSeconds()>0.05){
        setTexture(TextureLoader::getEnemy2TexttureAnim(MaxAnimTime-animTime));
        clock.restart();
        animTime--;
    }
    /*time++;
    if(time>15){
        setTexture(TextureLoader::getEnemy2TexttureAnim(MaxAnimTime-animTime));
        time=0;
        animTime--;
    }*/
}
bool EnemyPlane::shoot(){
    if(shootClock.getElapsedTime().asSeconds()>1){
        shootClock.restart();
        return true;
    }else
        return false;
}
