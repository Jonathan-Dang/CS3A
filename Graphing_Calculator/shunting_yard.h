#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#include <string.h>
#include <cmath>
#include "../Queue_List/Queue.h"
#include "../Stack_List/Stack.h"
#include "token.h"
#include "number.h"
#include "operator.h"
#include "lpar.h"
#include "rpar.h"
#include "variable.h"
#include "log.h"


class Shunting_Yard
{
public:
    Shunting_Yard();

    ~Shunting_Yard();

    Shunting_Yard(string input);

    void set_infix(Queue<Token*> input);

    Queue<Token*> postfix();

    double RPN(double vari = 0);

    Queue<Token*> Infix();

private:
    Queue<Token*> infix;
};

#endif // SHUNTING_YARD_H
