#ifndef PLOT_H
#define PLOT_H
#include <iostream>
#include <string.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Constants.h"
#include "../Vector-64/Vector.h"
#include <vector>
#include "shunting_yard.h"
#include "coord_translation.h"
using namespace std;

class Plot
{
public:
    Plot();
    Plot(Graph_Info* info);
    void Set_Info();
    void Set_Info(Graph_Info* info);
    Vector<sf::Vector2f> operator()();
private:
    Graph_Info* _info;
    Queue<Token*> _postfix;
};

#endif // PLOT_H
