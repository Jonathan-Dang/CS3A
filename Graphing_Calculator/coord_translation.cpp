#include "coord_translation.h"

coord_translation::coord_translation()
{
    //
}

coord_translation::coord_translation(Graph_Info* info)
{
    _info = info;
}

sf::Vector2f coord_translation::Translate(sf::Vector2f point)
{
    double x = point.x;
    double y = -point.y;

    x *= _info->_scale;
    x += _info->_translated_origin.x;

    y *= _info->_scale;
    y += _info->_translated_origin.y;

    return sf::Vector2f(x,y);
}

void coord_translation::Translate_origin(sf::Vector2f origin)
{
    double x = origin.x;
    double y = -origin.y;

    x *= _info->_scale;
    x += _info->_window_dimensions.x/2;

    y *= _info->_scale;
    y += _info->_window_dimensions.y/2;

    _info->_translated_origin = sf::Vector2f(x,y);
}

sf::Vector2f coord_translation::operator()(sf::Vector2f point)
{
    return Translate(point);
}
