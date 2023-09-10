#ifndef GAMEE_H_INCLUDED
#define GAMEE_H_INCLUDED



#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class game
{
    public:
        game();
        void print();
        void gameplay(char a);
        void random(char l);
        void scoreplus(int x, int y);
        bool endgame(   );
        void cleargame();
        void saveboard();
        void bestscore();
        void loadgame();

    private:
        int board[4][4];
        int score;
        int checkrecord = 0;
};

#endif

