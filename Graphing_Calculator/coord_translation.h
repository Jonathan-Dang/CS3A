#ifndef COORD_TRANSLATION_H
#define COORD_TRANSLATION_H
#include "Constants.h"
using namespace std;

class coord_translation
{
public:
    //CNTR
    coord_translation();
    coord_translation(Graph_Info* info);

    //TRANSLATION FUNCTIONS
    sf::Vector2f Translate(sf::Vector2f point);
    void Translate_origin(sf::Vector2f origin);
    sf::Vector2f operator()(sf::Vector2f point);
private:
    Graph_Info* _info;
};

#endif // COORD_TRANSLATION_H
