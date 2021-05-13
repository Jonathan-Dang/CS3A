#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <string.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../Vector-64/Vector.h"
#include "Constants.h"
#include "plot.h"
using namespace std;

class Graph
{
public:
    //Constructors
    Graph();

    //Animate Functions
    void set_info(Graph_Info* info);
    void update();
    void draw(sf::RenderWindow& window);

private:
    Graph_Info* _info;
    Plot _plotter;
    Vector<sf::Vector2f> _points;
};

#endif // GRAPH_H
