#ifndef ANIMATE_H
#define ANIMATE_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "string.h"
#include "system.h"
#include "sidebar.h"
#include "Constants.h"
#include "textfield.h"
using namespace std;

class animate
{
public:
    //Constructor
    animate();

    //Big 3
    animate(const animate& RHS);
    animate& operator =(const animate& RHS);
    ~animate();

    //Animate Functions
    void Run();
    void Process_Events();
    void Update();
    void Render();
private:
    //Void Function!
    void copyinfo(Graph_Info* cinfo);

    //Advanced Private Member Variables
    sf::RenderWindow window;
    Graph_Info* info;
    System system;
    Sidebar sidebar;

    //Lesser Private Member Variables
    int command = 0;
    string input;

    //Help Menu Private Member Variables
    sf::Text help;
    sf::RectangleShape help_bar;
    bool help_focus = false;

    //Textfield Input Private Member Variables
    TextField tf;
    bool function = false;

    //Asthetic Private Member Variables
    sf::Text text;
    sf::CircleShape mouse;
    bool mouseIn;
    sf::Font _font;
    sf::Text _text;


};

#endif // ANIMATE_H
