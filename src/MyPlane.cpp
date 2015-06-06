#include "MyPlane.h"

MyPlane::MyPlane(){
    life=3;
}

void MyPlane::hitted(){
    if(life>0)
    life--;
}
int MyPlane::getLife(){
    return life;
}
