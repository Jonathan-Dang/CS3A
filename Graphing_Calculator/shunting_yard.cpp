#include "shunting_yard.h"

Shunting_Yard::Shunting_Yard()
{
    //
}

Shunting_Yard::~Shunting_Yard()
{
    infix.~Queue();
}

Shunting_Yard::Shunting_Yard(string input)
//Using a String as a Char Array system, detecting the first char within the
//string to tokenize to be able to use in the postfix and RPN.
{
    string Input = input;
    Queue<Token*> Infix;
    Infix.Push(new Number(0));
    int size = Input.size();
    bool log_variable = false;

    while(size > 0)
    {
        if(Input[0] == 'l' || Input[0] == 'L')
        {
            if(Input[1] == 'n' || Input[1] == 'N')
            {
                double base = 2.71828;
                Input.erase(Input.begin(),Input.begin()+2);
                size -= 2;
                if(Input[0] == '(')
                {
                    Input.erase(Input.begin());
                    size--;
                    string hold;
                    while(Input[0] != ')')
                    {
                        if(Input[0] == 'x') {log_variable = true;}
                        hold += Input[0];
                        Input.erase(Input.begin());
                        size--;
                    }
                    if(!log_variable)
                    {
                        double dot = stod(hold);
                        double exponent = dot;
                        Input.erase(Input.begin());
                        size--;
                        Infix.Push(new Log(base,exponent));
                    }
                    else
                    {
                        Input.erase(Input.begin());
                        size--;
                        Infix.Push(new Log(base,hold));
                    }
                }

            }
            else
            {
                Input.erase(Input.begin(),Input.begin()+3);
                size -=3;
                string hold;
                double exponent = 0, base;
                if((Input[0] > 48 && Input[0] < 57))
                {
                    while(Input[0] != '(')
                    {
                        hold += Input[0];
                        Input.erase(Input.begin());
                        size--;
                    }
                    base = stod(hold);
                }
                else if(Input[0] == '[')
                {
                    Input.erase(Input.begin());
                    size--;
                    string hold;
                    while(Input[0] != ']')
                    {
                        hold += Input[0];
                        Input.erase(Input.begin());
                        size--;
                    }
                    base = stod(hold);
                    Input.erase(Input.begin());
                    size--;
                }

                if(Input[0] == '(')
                {
                    Input.erase(Input.begin());
                    size--;
                    string hold;
                    while(Input[0] != ')')
                    {
                        if(Input[0] == 'x') {log_variable = true;}
                        hold += Input[0];
                        Input.erase(Input.begin());
                        size--;
                    }
                    if(!log_variable)
                    {
                        exponent = stod(hold);
                        Input.erase(Input.begin());
                        size--;
                        Infix.Push(new Log(base,exponent));
                    }
                    else
                    {
                        Input.erase(Input.begin());
                        size--;
                        Infix.Push(new Log(base,hold));
                    }
                }

            }
        }//Log and LN if statement
        else if(Input[0] > 48 && Input[0] < 57)
        {
            int holder_size = 0;
            for(int i = 0; i != size; i++)
            {
                if((Input[i] > 48 && Input[i] < 57) || Input[i] == 46)
                {
                    holder_size++;
                }
                else
                {
                    break;
                }
            }
            string pop = Input;
            pop.erase(pop.begin()+holder_size,pop.end());
            double push = 0;
            push = stod(pop);
            Infix.Push(new Number(push));
            Input.erase(Input.begin(),Input.begin()+holder_size);
            size -= holder_size;
            holder_size = 0;
        }// Number if statement
        switch(Input[0])
        {
        case('+'):
            Infix.Push(new Operator("+"));
            Input.erase(Input.begin());
            size--;
            break;
        case('-'):
            Infix.Push(new Operator("-"));
            Input.erase(Input.begin());
            size--;
            break;
        case('*'):
            Infix.Push(new Operator("*"));
            Input.erase(Input.begin());
            size--;
            break;
        case('/'):
            Infix.Push(new Operator("/"));
            Input.erase(Input.begin());
            size--;
            break;
        case('^'):
            Infix.Push(new Operator("^"));
            Input.erase(Input.begin());
            size--;
            break;
        case('('):
            Infix.Push(new lpar);
            Input.erase(Input.begin());
            size--;
            break;
        case(')'):
            Infix.Push(new rpar);
            Input.erase(Input.begin());
            size -= 3;
            break;
        case('S'):
        case('s'):
            Infix.Push(new Operator("sin"));
            Input.erase(Input.begin(),Input.begin()+3);
            size -= 3;
            break;
        case('C'):
        case('c'):
            Infix.Push(new Operator("cos"));
            Input.erase(Input.begin(),Input.begin()+3);
            size -= 3;
            break;
        case('T'):
        case('t'):
            Infix.Push(new Operator("tan"));
            Input.erase(Input.begin(),Input.begin()+3);
            size -= 3;
            break;
        case('X'):
        case('x'):
            Infix.Push(new Variable);
            Input.erase(Input.begin());
            size--;
            break;
        case('e'):
            Infix.Push(new Number(2.71828));
            Input.erase(Input.begin());
            size--;
            break;
        case(' '):
            Input.erase(Input.begin());
            size--;
            break;
        }//Switch Statement
    }

    set_infix(Infix);
}

Queue<Token*> Shunting_Yard::postfix()
{
    Stack<Token*> holder;
    Queue<Token*> postfix;
    Queue<Token*> INFIX = infix;
    Token* hold;

    do
    {
        hold = INFIX.Pop();
            switch(hold->type())
            {
            case(NUM):
                postfix.Push(hold);
                break;
            case(OPER):
                if(holder.Size() == 0)
                {
                    holder.Push(hold);
                }
                else if(hold->prec() == EXPO)
                {
                    holder.Push(hold);
                }
                else if(holder.Begin().operator*()->prec() >= hold->prec()
                        && holder.Size() != 0
                        && holder.Begin().operator*()->type() != lPAR)
                {
                    postfix.Push(holder.Pop());
                    holder.Push(hold);
                }
                else
                {
                    holder.Push(hold);
                }
                break;
            case(lPAR):
                holder.Push(hold);
                break;
            case(rPAR):
                while(holder.Size() != 0
                      && holder.Begin().operator*()->type() != lPAR)
                {
                    postfix.Push(holder.Pop());
                }
                holder.Pop();

                break;
            case(VARI):
                postfix.Push(hold);
                break;
            case(LOG):
                postfix.Push(hold);
                break;
            }//Switch
    }while(INFIX.Size());//Do -> while


    while(holder.Size())
    {
        postfix.Push(holder.Pop());
    }


    return postfix;
}

void Shunting_Yard::set_infix(Queue<Token *> input)
{
    infix = input;
}

Queue<Token*> Shunting_Yard::Infix()
{
    return infix;
}

double Shunting_Yard::RPN(double vari)
{
    double result = 0;
    Queue<Token*> post;
    Stack<Token*> hold;
    Token* pass;
    post = postfix();

    while(post.Size())
    {
        pass = post.Pop();
        switch(pass->type())
        {
        case(NUM):
            hold.Push(pass);
            break;
        case(VARI):
            hold.Push(new Number(vari));
            break;
        case(OPER):
            if(static_cast<Operator*>(pass)->op() == "^")
            {
                Token* temp = hold.Pop();
                Token* temp2 = hold.Pop();
                double x = static_cast<Number*>(temp)->num();
                double y = static_cast<Number*>(temp2)->num();
                hold.Push(new Number(pow(y,x)));
                break;
            }
            else if(static_cast<Operator*>(pass)->op() == "sin")
            {
                Token* temp = hold.Pop();
                double x = static_cast<Number*>(temp)->num();
                x = sin(x);
                hold.Push(new Number(x));
                break;
            }
            else if(static_cast<Operator*>(pass)->op() == "cos")
            {
                Token* temp = hold.Pop();
                double x = static_cast<Number*>(temp)->num();
                x = cos(x);
                hold.Push(new Number(x));
                break;
            }
            else if(static_cast<Operator*>(pass)->op() == "tan")
            {
                Token* temp = hold.Pop();
                double x = static_cast<Number*>(temp)->num();
                x = tan(x);
                hold.Push(new Number(x));
                break;
            }
            else
            {
                Token* temp = hold.Pop();
                Token* temp2 = hold.Pop();
                double x,y;
                x = static_cast<Number*>(temp)->num();
                y = static_cast<Number*>(temp2)->num();
                if(static_cast<Operator*>(pass)->op() == "+")
                {
                    hold.Push(new Number(x+y));
                }
                else if(static_cast<Operator*>(pass)->op() == "-")
                {
                    hold.Push(new Number(y-x));
                }
                else if(static_cast<Operator*>(pass)->op() == "*")
                {
                    hold.Push(new Number(x*y));
                }
                else if(static_cast<Operator*>(pass)->op() == "/")
                {
                    hold.Push(new Number(y/x));
                }
                break;
            }
        case(LOG):
        {
            Log* log = static_cast<Log*>(pass);
            if(log->variable())
            {
                double solution = 0;
                solution = (log10(vari))/(log10(log->base()));
                hold.Push(new Number(solution));
            }
            else
            {
                double solution = (log10(log->exponent()))
                        /(log10(log->base()));
                hold.Push(new Number(solution));
            }
        }//Log
        }//Switch
    }//While

    pass = hold.Pop();
    result = static_cast<Number*>(pass)->num();
    return result;
}
