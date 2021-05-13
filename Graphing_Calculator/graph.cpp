#include "graph.h"

Graph::Graph()
{
    cout << "   GRAPH:CNTR: Contructed Successfully!\n";
}

void Graph::draw(sf::RenderWindow &window)
{
    //X-Axis
    sf::RectangleShape X_Axis(sf::Vector2f(1,_info->_window_dimensions.y));
    X_Axis.setFillColor(sf::Color::White);
    X_Axis.setPosition(_info->_translated_origin.x,0);
    window.draw(X_Axis);

    //Y_Axis
    sf::RectangleShape Y_Axis(sf::Vector2f(_info->_window_dimensions.x,1));
    Y_Axis.setFillColor(sf::Color::White);
    Y_Axis.setPosition(0,_info->_translated_origin.y);
    window.draw(Y_Axis);

    //Points
    sf::CircleShape point(SIZE,30);
    point.setFillColor(sf::Color::White);

    for(int i = 1; i <= _points.size(); i++)
    {
        int x = _points[i].x;
        int y = _points[i].y;
        point.setPosition(x-SIZE,y-SIZE);
        window.draw(point);
    }

}

void Graph::update()
{
    _points = _plotter();
}

void Graph::set_info(Graph_Info* info)
{
    _info = info;
    _plotter.Set_Info(info);
}
