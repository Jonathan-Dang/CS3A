#ifndef CONSTANTS_H
#define CONSTANTS_H
#include <iostream>
#include <string.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace std;
const double SCREEN_WIDTH = 800; // x of Window Dimensions
const double SCREEN_HEIGHT = 800; // y of Window Dimensions
const double SIDEBAR_WIDTH = SCREEN_WIDTH/4;
const double SIDEBAR_HEIGHT = SCREEN_HEIGHT;
const double ZOOM_FACTOR = 9;

enum COMMAND : int {LPAN = 1, RPAN = 2, UPAN =3
                    , DPAN = 4, IZOOM = 5, OZOOM = 6, RESET = -1};

const double SIZE = 1;

//I decided to make the graph info structure here since it seems like the
//best possible place to put it

struct Graph_Info{
public:
    string _equation;

    sf::Vector2f _window_dimensions;
    sf::Vector2f _origin;
    sf::Vector2f _translated_origin;
    double _scale;
    sf::Vector2f _domain = sf::Vector2f(-5,5);

    int _points_amount = 500;
    double _increment = (_domain.y - _domain.x)/_points_amount;
};
#endif // CONSTANTS_H
