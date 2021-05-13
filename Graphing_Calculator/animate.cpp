#include "animate.h"

animate::animate()
{
    info = new Graph_Info;
    info->_window_dimensions = sf::Vector2f(SCREEN_WIDTH,SCREEN_HEIGHT);
    info->_domain = sf::Vector2f(-10,10);
    info->_scale = double((SCREEN_WIDTH/info->_domain.y)*2);
    info->_origin = sf::Vector2f(0,0);
    info->_translated_origin = sf::Vector2f(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
    if(sidebar[sidebar.LastItem()] != "HELP!")
    {
        info->_equation = sidebar[sidebar.LastItem()];
    }
    else
    {
        info->_equation = "sin(x)";
        help_focus = true;
    }

    sidebar.Set_info(info);
    system.Set_info(info);
    tf.set_info(info);

    if(!_font.loadFromFile("arial.ttf"))
    {
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

    _text.setFont(_font);
    _text.setCharacterSize(20);
    _text.setStyle(sf::Text::Bold);
    _text.setFillColor(sf::Color::Yellow);
    _text.setString(info->_equation);

    mouse = sf::CircleShape();
    mouse.setRadius(5);
    mouse.setFillColor(sf::Color::Red);
    mouseIn = true;


    help_bar.setSize(sf::Vector2f(575,315));
    help_bar.setPosition(sf::Vector2f(SCREEN_WIDTH/4 - 25
                                      ,SCREEN_HEIGHT/3 - 15));
    help_bar.setOutlineThickness(5);
    help_bar.setOutlineColor(sf::Color::Blue);
    help_bar.setFillColor(sf::Color::Black);


    string helpmenu = "Right Shift: Zoom out\n"
                      "Right Control: Zoom in\n"
                      "Left Alt: Opens up the Function Input Menu\n"
                      "Arrow Keys: Pan\n"
                      "H: Opens up the Help Menu [This menu]\n"
                      "Space Bar: Resets graph to default settings\n"
                      "ESC: Exits this Program\n"
                      "~Clicking on the History will set the current function\n"
                      "displayed to the clicked function.\n"
                      "~The Upper right hand corner has the current function,\n"
                      "As well as the bottom left corner.\n"
                      "Below the upper right is the function history!\n";
    help.setFont(_font);
    help.setStyle(sf::Text::Bold);
    help.setCharacterSize(20);
    help.setString(helpmenu);
    help.setPosition(sf::Vector2f(SCREEN_WIDTH/4,SCREEN_HEIGHT/3));

    cout << "   Animate:CNTR: Constructed Successfully, Drawing Graph!\n";

    window.create(sf::VideoMode(SCREEN_WIDTH + SIDEBAR_WIDTH,SCREEN_HEIGHT)
                  ,"Graphing Calculator");
    window.setFramerateLimit(20);
}

animate::animate(const animate& RHS)
{
    info = nullptr;
    info = new Graph_Info;
    copyinfo(RHS.info);
}

animate& animate::operator =(const animate& RHS)
{
    if(this == &RHS) {return *this;}
    info = nullptr;
    info = new Graph_Info;
    copyinfo(RHS.info);
    return *this;
}

animate::~animate()
{
    delete info;
}

void animate::copyinfo(Graph_Info* cinfo)
{
    info->_equation = cinfo->_equation;
    info->_scale = cinfo->_scale;
    info->_origin = cinfo->_origin;
    info->_translated_origin = info->_translated_origin;
    info->_domain = cinfo->_domain;
    info->_points_amount = cinfo->_points_amount;
    info->_increment = cinfo->_increment;
    info->_window_dimensions = cinfo->_window_dimensions;
}

void animate::Run()
{
    while(window.isOpen())
    {
        Process_Events();
        Update();
        Render();
    }
}

void animate::Update()
{
    system.Step(command);
    if (mouseIn)
    {
        mouse.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);
    }
    command = 0;
}

void animate::Render()
{
    window.clear();
    system.Draw(window);
    sidebar.Draw(window);
    if(mouseIn)
    {
        window.draw(mouse);
    }
    if(help_focus)
    {
        window.draw(help_bar);
        window.draw(help);
    }
    if(function)
    {
        tf.Draw(window);
    }
    _text.setString(info->_equation); //Current Function
    _text.setPosition(10, SCREEN_HEIGHT - 30);
    window.draw(_text);
    window.display();
}

void animate::Process_Events()
{
    sf::Event event;

    while(window.pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::Closed:
        {
            window.close();
            break;
        }
        case sf::Event::MouseButtonReleased:
        {
            if(event.mouseButton.button == sf::Mouse::Right)
            {
                cout << "the right button was pressed" << endl;
                cout << "mouse x: " << event.mouseButton.x << endl;
                cout << "mouse y: " << event.mouseButton.y << endl;
                sidebar.DeleteClick(sf::Vector2f(event.mouseButton.x
                                                 ,event.mouseButton.y));
            }
            else
            {
                cout << "left button" << endl;
                cout << "mouse x: " << event.mouseButton.x << endl;
                cout << "mouse y: " << event.mouseButton.y << endl;
                string click =
                        sidebar.OnClick(
                            sf::Vector2f(event.mouseButton.x
                                         ,event.mouseButton.y));
                if(click != "")
                {
                    info->_equation = click;
                }
            }

            break;
        }
        case sf::Event::MouseEntered:
        {
            mouseIn = true;
            break;
        }
        case sf::Event::MouseLeft:
        {
            mouseIn = false;
            break;
        }
        case sf::Event::KeyPressed:
        {
            switch(event.key.code)
            {
            case(sf::Keyboard::RShift):
                command = OZOOM;
                break;
            case(sf::Keyboard::RControl):
                command = IZOOM;
                break;
            case(sf::Keyboard::Right):
                command = RPAN;
                break;
            case(sf::Keyboard::Left):
                command = LPAN;
                break;
            case(sf::Keyboard::Up):
                command = UPAN;
                break;
            case(sf::Keyboard::Down):
                command = DPAN;
                break;
            case(sf::Keyboard::LAlt):
            {
                function = true;
                window.pollEvent(event);
                break;
            }
            case(sf::Keyboard::Enter):
                function = false;
                sidebar.Input(tf.output());
                tf.EmptyString();
                break;
            case(sf::Keyboard::H):
                if(help_focus)
                {
                    help_focus = false;
                }
                else
                {
                    help_focus = true;
                }
                break;
            case(sf::Keyboard::Space):
                command = RESET;
                break;
            case(sf::Keyboard::Escape):
                window.close();
                break;
            default:
                break;
            }
        }
        case sf::Event::TextEntered:
        {
            if(function)
            {
                if(event.text.unicode < 128)
                {
                    tf.Input(event);
                }
            }
            break;
        }
        default:
            break;
        }
    }
}
