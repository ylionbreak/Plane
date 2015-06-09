#include "LifeText.h"

LifeText::LifeText()
{
    setCharacterSize(24);
    setColor(sf::Color::Red);
}
void LifeText::setLifeText(int life){
    if(life==3){
        setString("***");
    }else if(life==2){
        setString("**");
    }else if(life==1){
        setString("*");
    }else if(life==0){
        setString("");
    }
}

