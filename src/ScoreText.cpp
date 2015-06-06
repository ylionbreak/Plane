#include "ScoreText.h"

ScoreText::ScoreText(int type){
    if(type==1){
        setCharacterSize(24);
        setColor(sf::Color::Red);
        sprintf(buffer,"%d",score);
        setString(buffer);
    }else if(type==2){
        setCharacterSize(50);
        setColor(sf::Color::Red);
        setString("dead^ ^");
    }
}
void ScoreText::addScore(int thisScore){

    score=score + thisScore;
    sprintf(buffer,"%d",score);
    //scoreString=static_cast<char>(score);

    setString(buffer);
}
