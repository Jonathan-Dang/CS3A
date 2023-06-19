#include "twod.h"
//Non-templated functions
inline void print_plane(bool** plane, int* sizes)
{
    bool** walkerR = plane;
    bool* walkerC;
    char letters[4]={'A','B','C','D'};
    int N=1;

    cout << endl << "=============+========+========+========|"<<endl;
    while(*sizes != -1)
    {
        walkerC = *walkerR;
        cout << "   "<<N<<"|";
        for(int i = 0;i < *sizes;i++)
        {
            if(!(*walkerC))
            {
                cout << "   X    |";
            }
            else
            {
                cout << "   " << letters[i] << "    |";
            }
            walkerC++;
        }
        cout << endl << "=============+========+========+========|"<<endl;
        walkerR++;
        sizes++;
        N++;
    }
}

inline void reserve(bool** plane, int* sizes, int lab, char station)
{
    int chair=0;
    switch(tolower(station))
    {
    case('a'):
        chair = 1;
        break;
    case('b'):
        chair = 2;
        break;
    case('c'):
        chair = 3;
        break;
    case('d'):
        chair = 4;
        break;
    }

    write(plane,sizes,lab,chair,false);
}

inline void cancel(bool** plane, int* sizes,int lab, char station)
{
    int chair=0;
    switch(tolower(station))
    {
    case('a'):
        chair = 1;
        break;
    case('b'):
        chair = 2;
        break;
    case('c'):
        chair = 3;
        break;
    case('d'):
        chair = 4;
        break;
    }

    write(plane,sizes,lab,chair,true);
}

inline void menu_plane(bool** plane, int* sizes)
{
    char command;
    int lab;
    char station;

    cout<<"[r]eserve    [c]ancel      e[x]it"<<endl;
    cout<<":"; cin>>command;

    while(toupper(command) != 'X')
    {
        int chair = 0;
        switch(toupper(command))
        {
        case('R'):
            cout<<"---- Reservations ----"<<endl;
            print_plane(plane,sizes);
            cout << "row: ";
            cin >> lab;
            cout << "seat letter:";
            cin >> station;

            switch(tolower(station))
            {
            case('a'):
                chair = 1;
                break;
            case('b'):
                chair = 2;
                break;
            case('c'):
                chair = 3;
                break;
            case('d'):
                chair = 4;
                break;
            }
            if(is_valid(sizes,lab,chair))
            {
                bool* check = get(plane,sizes,lab,chair);
                if(*check)
                {
                    reserve(plane,sizes,lab,station);
                    cout << "Reservation placed at " << lab << station << endl;
                }
                else
                {
                    cout << "Chair " << station<< " in row " << lab
                         << " is occupied"<< endl;
                }
            }//if
            else
            {
                cout << "Row/Chair input is invalid" << endl;
            }//else

            print_plane(plane,sizes);
            break;
        case('C'):
            cout << "---- Cancel a Reservation ----" << endl;
            print_plane(plane,sizes);
            cout << "row: ";
            cin >> lab;
            cout << "seat letter: ";
            cin >> station;

            cancel(plane,sizes,lab,station);
            print_plane(plane,sizes);
            break;
        }

        cout<<"[r]eserve    [c]ancel      e[x]it"<<endl;
        cout<<":"; cin>>command;
    }
    cout << "Exiting, Have a nice Day!" <<endl;
}

inline void plane_demo()
{
    int sizes[5] = {4,4,4,4,-1};
    bool** plane = allocate<bool>(sizes);
    init(plane,sizes,true);
    menu_plane(plane,sizes);
}
//templated functions
