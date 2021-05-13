#include "plot.h"
Plot::Plot()
{

}

Plot::Plot(Graph_Info* info)
{
    _info = info;
}

Vector<sf::Vector2f> Plot::operator()()
{
    Shunting_Yard sy;
    coord_translation ct(_info);

    sy = Shunting_Yard(_info->_equation);

    Queue<Token*> postfix = sy.postfix();

    Vector<sf::Vector2f> converted(500);
    for(double i = _info->_domain.x; i <= _info->_domain.y
        ; i = i + _info->_increment)
    {
        double x = i;
        double y = sy.RPN(i);
        converted.push_back(ct.Translate(sf::Vector2f(x,y)));
    }
    return converted;
}

void Plot::Set_Info(Graph_Info *info)
{
    _info = info;
}
