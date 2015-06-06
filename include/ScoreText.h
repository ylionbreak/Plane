#ifndef SCORETEXT_H
#define SCORETEXT_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
using namespace std;
using namespace sf;

class ScoreText : public Text{
    public:
        ScoreText(int type);
        void addScore(int thisScore);

    protected:
    private:
        char buffer[50];
        string scoreString="0";
        int score=0;
};

#endif // SCORETEXT_H
