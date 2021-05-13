#ifndef SYSTEM_H
#define SYSTEM_H
#include "graph.h"
#include "sidebar.h"
#include <iostream>
#include "Constants.h"
using namespace std;

class System
{
public:
    //Contructors
    System();
    System(Graph_Info* info);

    //Info Setter
    void Set_info(Graph_Info* info);

    //Animate Functions
    void Step(int command);
    void Draw(sf::RenderWindow& window);

private:
    Graph _g;
    Graph_Info* _info;
};

#endif // SYSTEM_H
