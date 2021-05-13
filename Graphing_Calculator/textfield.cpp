#include "textfield.h"

TextField::TextField()
{
    //field set up
    _field.setSize(sf::Vector2f(15*30,20));
    _field.setFillColor(sf::Color::White);
    _field.setOutlineThickness(3);
    _field.setOutlineColor(sf::Color(127,127,127));

    if(!_font.loadFromFile("arial.ttf"))
    {
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

    //text set up
    _font.loadFromFile("arial.ttf");
    _text.setFont(_font);
    _text.setStyle(sf::Text::Bold);
    _text.setFillColor(sf::Color::Black);
    _text.setCharacterSize(15);
}

void TextField::Draw(sf::RenderWindow& window)
{
    _field.setPosition(_info->_window_dimensions.x/5
                    ,_info->_window_dimensions.y - 60);
    _text.setPosition(_info->_window_dimensions.x/5 + 10
                      ,_info->_window_dimensions.y - 60);
    _text.setString(_input);
    window.draw(_field);
    window.draw(_text);
}

void TextField::set_info(Graph_Info *info)
{
    _info = info;
}

void TextField::Input(sf::Event e)
{
    if (e.type != sf::Event::TextEntered) {return;}

    if (e.text.unicode == 8) //DELETE
    {
        _input = _input.substr(0, _input.size() - 1);
    }
    else
    {
        _input += e.text.unicode;
    }
    _text.setString(_input);
}
