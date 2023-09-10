#include <iostream>
#include "gamee.h"
#include <string>
#include <windows.h>
#include <conio.h>
#include <cctype>
#include <fstream>

using namespace std;

int main()
{
    cout << "2048" << endl;
    cout << "Control Keys: " << endl;
    cout << "(C) Continue" << endl;
    cout << "(R) Restart" << endl;
    cout << "(L) Load Old Game" << endl;
    cout << "(N) New Game" << endl;

    char gamepoint;
    gamepoint = tolower(_getch());
    game a;
    if(gamepoint == 'n')
    {
        system ("cls");
    while(gamepoint != 'q')
    {
        bool lol = true;
        a.print();
        gamepoint = tolower(_getch());
        a.gameplay(gamepoint);
        system("cls");
        lol = a.endgame();
        if(lol)
        {
            cout << "YOU LOST NOOB!!!!!" << endl;
            a.bestscore();
        }
        if(gamepoint == 'r')
        {
            a.cleargame();
            a.bestscore();

        }
        if(gamepoint == 'x')
        {
           a.saveboard();
        }
        if(gamepoint == 'q')
        {
            a.bestscore();
        }
    }
    }
        if(gamepoint == 'l')
        {
        a.loadgame();
        system ("cls");
    while(gamepoint != 'q')
    {
        bool lol = true;
        a.print();
        gamepoint = tolower(_getch());
        a.gameplay(gamepoint);
        system("cls");
        lol = a.endgame();
        if(lol)
        {
            cout << "YOU LOST NOOB!!!!!" << endl;
            a.bestscore();
        }
        if(gamepoint == 'r')
        {
            a.cleargame();
            a.bestscore();
        }
        if(gamepoint == 'x')
        {
           a.saveboard();
        }
        if(gamepoint == 'q')
        {
            a.bestscore();
        }
    }
        }
}
