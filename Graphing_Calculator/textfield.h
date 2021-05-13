#ifndef TEXTFIELD_H
#define TEXTFIELD_H
#include "Constants.h"
#include "string.h"
#include <iostream>
using namespace std;

class TextField
{
public:
    TextField();
    void Draw(sf::RenderWindow& window);
    void set_info(Graph_Info* info);
    void Input(sf::Event e);
    void Reset();
    void EmptyString() {_input = "";}
    string output() {return _input;}
private:
    Graph_Info* _info;
    sf::RectangleShape _field;
    string _input;
    sf::Font _font;
    sf::Text _text;
};

#endif // TEXTFIELD_H
