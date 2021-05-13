#ifndef SIDEBAR_H
#define SIDEBAR_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include "Constants.h"
#include "../Vector-64/Vector.h"
using namespace std;

const int TEXTSIZE = 15;

class Sidebar
{
public:
    //Animate functions
    Sidebar();
    ~Sidebar();
    void Draw(sf::RenderWindow& window);
    void Set_info(Graph_Info* info);
    void Input(string input);
    int LastItem();

    //History Events
    string OnClick(sf::Vector2f pos); //Left Click: brings up clicked Function
    void DeleteClick(sf::Vector2f pos); //Right Click: Deletes Function

    //File dependent functions
    string& operator [](int index); //Start up function

private:
    //private VOID functions
    void EditFile(); //When program ends, then edit the file
    void CheckItemsDups(string input); //No dups

    //Private Member Variables
    ifstream instream;
    ofstream outstream;
    sf::RectangleShape _bar;
    sf::RectangleShape sb_sep; // Seperates current functions from history
    Graph_Info* _info;
    sf::Font _font;
    sf::Text _text;
    Vector<sf::Text> _history;
    Vector<string> items;
};

#endif // SIDEBAR_H
