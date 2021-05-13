#include "sidebar.h"

Sidebar::Sidebar()
{
    //Sidebar body
    _bar.setSize(sf::Vector2f(SIDEBAR_WIDTH,SIDEBAR_HEIGHT));
    _bar.setFillColor(sf::Color(127,127,127));
    _bar.setPosition(SCREEN_WIDTH,0);

    //Current Function Seperator
    sb_sep.setSize(sf::Vector2f(SIDEBAR_WIDTH,3));
    sb_sep.setFillColor(sf::Color::Black);
    sb_sep.setPosition(sf::Vector2f(SCREEN_WIDTH,40));

    //Set up for loading "arial.tff"
    if(!_font.loadFromFile("arial.ttf"))
    {
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

    //_Text set up
    _text.setFont(_font);
    _text.setCharacterSize(20);
    _text.setStyle(sf::Text::Bold);
    _text.setFillColor(sf::Color::Yellow);

    //_History set up
    sf::Text history;
    history.setFont(_font);
    history.setCharacterSize(20);
    history.setStyle(sf::Text::Bold);
    history.setFillColor(sf::Color::Yellow);

    //Detecting File series
    instream.open("functions.txt");
    outstream.open("functions.txt",ios::app);
    outstream.close();
    if(instream.good())
    {
        cout << "   SIDEBAR:CNTR: TXT FILE ACTIVE\n";
    }
    else
    {
        cout << "   SIDEBAR:CNTR: HISTORY NOT DETECTED"
                ", CREATING NEW HISTORY\n";
        instream.clear();
    }

    if(instream.peek() == ifstream::traits_type::eof())
    {
        cout << "INPUTING DEFAULT FUNCTION\n";
        items += "HELP!";
        history.setString("HELP!");
        _history += history;
    }
    else
    {
        while(!instream.eof())
        {
            string temp;
            getline(instream,temp);
            if(temp == "")
            {
                break;
            }
            items.insert(0,temp);
            history.setString(temp);
            _history.insert(0,history);
            CheckItemsDups(temp);
        }
    }

    instream.close();

    cout << "   SIDEBAR:CNTR: Contructed Successfully!\n";
}

string Sidebar::OnClick(sf::Vector2f pos)
{
    for(int i = 0; i < _history.size(); i++)
    {
        if(_history[i].getGlobalBounds().contains(pos))
        {
            return _history[i].getString();
        }
    }

    return "";
}

void Sidebar::DeleteClick(sf::Vector2f pos)
{
    for(int i = 0; i < _history.size(); i++)
    {
        if(_history[i].getGlobalBounds().contains(pos))
        {
            _history.erase(i);
            items.erase(i);
            break;
        }
    }
}

Sidebar::~Sidebar()
{
    EditFile();
}

string& Sidebar::operator [](int index)
{
    return items[index];
}

void Sidebar::Set_info(Graph_Info* info)
{
    _info = info;
}

void Sidebar::Input(string input)
{
    if(items[0] == "HELP!" && _history[0].getString() == "HELP!")
    {
        items.erase(0);
        _history.erase(0);
    }

    items.push_back(input); //Keeping Track of Functions

    sf::Text temp; //Keeping Track of Texts Versions for History
    temp.setFont(_font);
    temp.setCharacterSize(20);
    temp.setStyle(sf::Text::Bold);
    temp.setFillColor(sf::Color::Yellow);
    temp.setString(input);
    _history.push_back(temp);

    CheckItemsDups(input);

    _info->_equation = input;
}

void Sidebar::Draw(sf::RenderWindow &window)
{
    window.draw(_bar);
    window.draw(sb_sep);

    _text.setString(_info->_equation);//file's functions
    _text.setPosition(_info->_window_dimensions.x + 10,5);
    window.draw(_text);

    float y = _text.getCharacterSize() + _text.getPosition().y + 20;
    for(int i = 0; i < _history.size(); i++)
    {
        _history[i].setPosition(sf::Vector2f(_text.getPosition().x,y));
        window.draw(_history[i]);
        if(y > _info->_window_dimensions.y)
        {
            items.erase(0);
            _history.erase(0);
        }
        y += _history[i].getCharacterSize() + 15;
    }

}

void Sidebar::CheckItemsDups(string input)
{
    bool Flag = false;
    for(int i = 0; i < items.size(); i++)
    {
        if(input.compare(items[i]) == 0)
        {
            if(Flag)
            {
                items.erase(i);
                _history.erase(i);
                break;
            }
            else
            {
                Flag = true;
            }
        }
    }
}

void Sidebar::EditFile()
{
    outstream.open("functions.txt",ios::out | ios::trunc);
    string walker;
    while(items.size())
    {
        walker = items.pop_back();
        walker += "\n";
        outstream << walker;
    }
    outstream.close();
}

int Sidebar::LastItem()
{
    return items.size() - 1;
}
