#include "twod.h"
//Non-templated Functions
inline void login(int** labs,int* sizes, int lab, int station, int id)
{
    if(is_valid(sizes,lab,station))
    {
        write(labs,sizes,lab,station,id);
    }
    else
    {
        cout << "Lab/station does not exist" << endl;
    }
}

inline void logout(int** labs, int* sizes, int id)
{
    int** walkerR = labs;
    int* walkerC;
    while(*sizes != -1)
    {
        walkerC = *walkerR;
        for(int i = 0;i<*sizes;i++)
        {
            if(*walkerC == id)
            {
                *walkerC = -1;
            }
        }
        walkerR++;
        sizes++;
    }
}

inline void print_lab(int** labs, int* sizes)
{
    cout << "    |Station1|Station2|Station3|Station4|" << endl;
    for(int i = 1;*sizes != -1;i++)
    {
        cout << "Lab"<<i<<"|";
        print(*labs, *sizes);
        cout << "=============+========+========+========|"<<endl;
        labs++;
        sizes++;
    }
}

inline void menu_lab(int** labs, int* sizes)
{
    char command;
    int id = 0;
    int lab;
    int station;

    cout<<"log[i]n    log[o]ut      e[x]it"<<endl;
    cout<<":"; cin>>command;

    while(toupper(command) != 'X')
    {
        switch(command)
        {
        case('i'):
        case('I'):
            cout<<"---- LOG IN: ------"<<endl;
            print_lab(labs,sizes);
            cout << "id: ";
            cin >> id;
            cout << "Lab: ";
            cin >> lab;
            cout << "Station: ";
            cin >> station;

            if(is_valid(sizes,lab,station))
            {
                int* check = get(labs,sizes,lab,station);
                if(*check == -1)
                {
                    login(labs,sizes,lab,station,id);
                    cout << "Logged In at lab " << lab<< ", station "
                         << station<< endl;
                }
                else
                {
                    cout << "Lab " << lab << ", station " <<station
                         << " is occupied" << endl;
                }
            }
            else
            {
                cout << "Lab/station location input is invalid" << endl;
            }

            break;
        case('o'):
        case('O'):
            cout<<"---- LOG OUT: ----"<<endl;
            cout << "id: ";
            cin >> id;
            cout << endl;

            logout(labs,sizes,id);
            cout << "Logout Successful" << endl;
            break;
        }//switch(command)

        print_lab(labs,sizes);
        cout<<"log[i]n    log[o]ut      e[x]it"<<endl;
        cout<<":"; cin>>command;
    }//while(toupper(command) != 'X')

    cout << "Exiting, Have a nice day!" << endl;
}

inline void lab_demo()
{
    int sizes[5] = {4,4,4,4,-1};
    int** lab = allocate<int>(sizes);
    init(lab,sizes,-1);
    menu_lab(lab,sizes);
}

//templated Functions
