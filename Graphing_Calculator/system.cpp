#include "system.h"

System::System()
{
    cout << "   SYSTEM:CNTR: Constructed Successfully\n";
}

void System::Draw(sf::RenderWindow &window)
{
    _g.draw(window);
}

void System::Step(int command)
{
    _g.update();
    coord_translation ct(_info);

    switch(command)
    {
    case(LPAN):
        _info->_origin.x += 0.25;
        ct.Translate_origin(_info->_origin);

        _info->_domain.x -= 0.25;
        _info->_domain.y -= 0.25;
        break;
    case(RPAN):
        _info->_origin.x -= 0.25;
        ct.Translate_origin(_info->_origin);

        _info->_domain.x += 0.25;
        _info->_domain.y += 0.25;
        break;
    case(UPAN):
        _info->_origin.y -= 0.25;
        ct.Translate_origin(_info->_origin);
        break;
    case(DPAN):
        _info->_origin.y += 0.25;
        ct.Translate_origin(_info->_origin);
        break;
    case(IZOOM):
        _info->_scale += 10;
        if(_info->_domain.x <= -6 || _info->_domain.y >= 6)
        {
            _info->_domain.x += 5;
            _info->_domain.y -= 5;
        }
        break;
    case(OZOOM):
        if(_info->_scale > 10)
        {
            _info->_scale -= 10;
            if(_info->_scale > -40 || _info->_scale < 40)
            {
                _info->_domain.x -= 5;
                _info->_domain.y += 5;
            }
        }
        break;
    case(RESET):
        _info->_origin = sf::Vector2f(0,0);
        ct.Translate_origin(_info->_origin);
        _info->_domain = sf::Vector2f(-10,10);
        _info->_scale = double((SCREEN_WIDTH/_info->_domain.y)*2);
        break;
    default:
        break;
    }
}

void System::Set_info(Graph_Info* info)
{
    _info = info;
    _g.set_info(info);
}
