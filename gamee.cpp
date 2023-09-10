#include "gamee.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <fstream>

using namespace std;
game::game()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            board[i][j] = 0;
        }
    }
    srand(time(0));
    int x = (rand()%4);
    int y = (rand()%4);
    int b =0;
    int a =0;

    for(int i =0; i<10; i++)
    {
         a = (rand()%4);
         b = (rand()%4);
         if(a != x && b != y)
         {
             break;
         }
    }

    board[x][y] = 2;
    board[a][b] = 2;
    score = 0;
    ifstream File("bestscore.txt");
    File >> checkrecord;
}

void game::random(char l)
{
       if(l == 1)
       {
       int coordinate[32];
       int c = 0;
       for(int i=0; i<4; i++)
       {
           for(int j=0; j<4; j++)
           {
               if(board[i][j] == 0)
               {
                   coordinate[c]=i;
                   coordinate[c+1]=j;
                   c = c+2;
               }
           }
       }
       srand(time(0));
       int x = (rand()%(c-1));
       int kek = (rand()%10);
       if(x%2==0)
       {
            if(kek < 9)
            {
                  board[coordinate[x]][coordinate[x+1]] = 2;
            }
            else
            {
                  board[coordinate[x]][coordinate[x+1]] = 4;
            }
       }
       else
       {
            if(kek < 9)
            {
                 board[coordinate[x-1]][coordinate[x]] = 2;
            }
            else
            {
                 board[coordinate[x-1]][coordinate[x]] = 4  ;
            }
       }
    }
}

void game::scoreplus(int a, int b)
{
    this->score = this->score + a+b;
}

void game::cleargame()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            board[i][j] = 0;
        }
    }
    srand(time(0));
    int x = (rand()%4);
    int y = (rand()%4);
    int b =0;
    int a =0;

    for(int i =0; i<10; i++)
    {
         a = (rand()%4);
         b = (rand()%4);
         if(a != x && b != y)
         {
             break;
         }
    }

    board[x][y] = 2;
    board[a][b] = 2;
    score = 0;
}

void game::print()
{
    ifstream file("bestscore.txt");
    int bestscore;
    file >> bestscore;
    file.close();
    string boards[4][4];
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(board[i][j] < 10 && board[i][j] >0)
            {
                boards[i][j] =  to_string(board[i][j])+"   | ";
            }
            if(board[i][j] >= 10 && board[i][j] < 100)
            {
                boards[i][j] = to_string(board[i][j]) + "  | ";
            }
            if(board[i][j] >= 100 && board[i][j] < 1000)
            {
                boards[i][j] = to_string(board[i][j])+" | " ;
            }
            if(board[i][j] >= 1000 && board[i][j] < 10000)
            {
                boards[i][j] = to_string(board[i][j])+"| ";
            }
            if(board[i][j] == 0)
            {
                boards[i][j] = "    | ";
            }
        }
    }
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout <<boards[i][j];

        }
        cout << endl << "-----------------------" << endl;
    }
    cout<< endl;
    cout << "Your score is: " <<this->score << endl;
        cout << "Your record is: " << bestscore << endl << endl;
        cout << "Control Keys: " << endl;
        cout << "(C) Continue" << endl;
        cout << "(R) Restart" << endl;
        cout << "(X) Save Game" << endl;
        cout << "(Q) Quit" << endl;
        cout << "(W) Up" << endl;
        cout << "(A) Left" << endl;
        cout << "(S) Down" << endl;
        cout << "(D) Right" << endl;
}

bool game::endgame()
{
    bool b = true;
    for(int i=0; i<4;i++)
    {
        for(int j=0; j<3; j++)
        {

            if(board[i][j] == board[i][j+1])
            {
                b = false;
            }
            else if(board[j][i]== board[j+1][i])
            {
                b=false;
            }
        }
    }
    for(int i=0; i<4;i++)
    {
        for(int j=0; j<4; j++)
        {
               if(board[i][j] == 0)
            {
                b = false;
            }
        }
    }
    return b;
}

void game::saveboard ()
{
    ofstream File("example.txt");
     for(int i=0; i<4; i++)
       {
           for(int j=0; j<4; j++)
           {

              File << board[i][j] << " ";
           }
       }
       File.close();

       ofstream Scorefile("scorelastgame.txt");
       Scorefile << score;
}

void game::loadgame()
{
    for(int i=0; i<4; i++)
       {
           for(int j=0; j<4; j++)
           {

              board[i][j] =0;
           }
       }

    string test;
    ifstream inFile("example.txt");
    int x=0;
    int y=0;
    while(inFile >> test)
    {
      int number = stoi(test);
      board[y][x] = number;
      x++;
      if(x==4){
      y++;
      x = 0;}
    }
    inFile.close();
    ifstream kekk("scorelastgame.txt");
    kekk >> score;
}
void game::bestscore()
{
     if(score > checkrecord)
     {
         ofstream File;
         File.open("bestscore.txt", ofstream::trunc);
         File << score;
     }
}

void game::gameplay (char a)
{
    if(a == 'w')
    {
       int l = 0;
       for(int i=0; i<4; i++)
       {
           for(int j=0; j<3; j++)
           {
               if(board[j][i] == 0 && board[j+1][i] != 0)
               {
                   board[j][i] = board[j+1][i];
                   board[j+1][i] = 0;
                   l=1;
               }
           }
       }

       for(int i=0; i<4; i++)
       {
           for(int j=0; j<3; j++)
           {
               if(board[j][i] == 0 && board[j+1][i] != 0)
               {
                   board[j][i] = board[j+1][i];
                   board[j+1][i] = 0;
                   l=1;
               }
           }
       }


       for(int i=0; i<4; i++)
       {
           for(int j=0; j<3; j++)
           {
               if(board[j][i] == board[j+1][i] && board[j][i] != 0)
               {
                   board[j][i] = board[j+1][i] + board[j][i];
                   board[j+1][i] = 0;
                   l=1;
                   scoreplus(board[j+1][i], board[j][i]);
               }
           }
       }

       for(int i=0; i<4; i++)
       {
           for(int j=0; j<3; j++)
           {
               if(board[j][i] == 0 && board[j+1][i] != 0)
               {
                   board[j][i] = board[j+1][i];
                   board[j+1][i] = 0;
                   l=1;
               }
           }
       }
       random(l);
}
    else if(a == 'd')
    {
        int l = 0;
       for(int i=0; i<4; i++)
       {
           for(int j=3; j>0; j--)
           {
               if(board[i][j] == 0 && board[i][j-1] != 0)
               {
                   board[i][j] = board[i][j-1];
                   board[i][j-1] = 0;
                   l =1;
               }
           }
       }

       for(int i=0; i<4; i++)
       {
           for(int j=3; j>0; j--)
           {
               if(board[i][j] == 0 && board[i][j-1] != 0)
               {
                   board[i][j] = board[i][j-1];
                   board[i][j-1] = 0;
                   l =1;
               }
           }
       }


       for(int i=0; i<4; i++)
       {
           for(int j=3; j>0; j--)
           {
               if(board[i][j] == board[i][j-1] && board[i][j] != 0)
               {
                   board[i][j] = board[i][j-1] + board[i][j];
                   board[i][j-1] = 0;
                   l=1;
                   scoreplus(board[i][j-1], board[i][j]);
               }
           }
       }

       for(int i=0; i<4; i++)
       {
           for(int j=3; j>0; j--)
           {
               if(board[i][j] == 0 && board[i][j-1] != 0)
               {
                   board[i][j] = board[i][j-1];
                   board[i][j-1] = 0;
                   l =1;
               }
           }
       }
     random(l);
    }
    else if(a == 's')
    {
       int l = 0;
       for(int i=0; i<4; i++)
       {
           for(int j=3; j>0; j--)
           {
               if(board[j][i] == 0 && board[j-1][i] != 0)
               {
                   board[j][i] = board[j-1][i];
                   board[j-1][i] = 0;
                   l =1;
               }
           }
       }

       for(int i=0; i<4; i++)
       {
           for(int j=3; j>0; j--)
           {
               if(board[j][i] == 0 && board[j-1][i] != 0)
               {
                   board[j][i] = board[j-1][i];
                   board[j-1][i] = 0;
                   l =1;
               }
           }
       }


       for(int i=0; i<4; i++)
       {
           for(int j=3; j>0; j--)
           {
               if(board[j][i] == board[j-1][i] && board[j][i] != 0)
               {
                   board[j][i] = board[j-1][i] + board[j][i];
                   board[j-1][i] = 0;
                   l=1;
                   scoreplus(board[j-1][i], board[j][i]);
               }
           }
       }

       for(int i=0; i<4; i++)
       {
           for(int j=3; j>0; j--)
           {
               if(board[j][i] == 0 && board[j-1][i] != 0)
               {
                   board[j][i] = board[j-1][i];
                   board[j-1][i] = 0;
                   l =1;
               }
           }
       }
       random(l);
    }
    else if(a == 'a')
    {
       int l = 0;
       for(int i=0; i<4; i++)
       {
           for(int j=0; j<3; j++)
           {
               if(board[i][j] == 0 && board[i][j+1] != 0)
               {
                   board[i][j] = board[i][j+1];
                   board[i][j+1] = 0;
                   l =1;
               }
           }
       }

       for(int i=0; i<4; i++)
       {
           for(int j=0; j<3; j++)
           {
               if(board[i][j] == 0 && board[i][j+1] != 0)
               {
                   board[i][j] = board[i][j+1];
                   board[i][j+1] = 0;
                   l =1;
               }
           }
       }


       for(int i=0; i<4; i++)
       {
           for(int j=0; j<3; j++)
           {
               if(board[i][j] == board[i][j+1] && board[i][j] != 0)
               {
                   board[i][j] = board[i][j+1] + board[i][j];
                   board[i][j+1] = 0;
                   l=1;
                   scoreplus(board[i][j+1], board[i][j]);
               }
           }
       }

       for(int i=0; i<4; i++)
       {
           for(int j=0; j<3; j++)
           {
               if(board[i][j] == 0 && board[i][j+1] != 0)
               {
                   board[i][j] = board[i][j+1];
                   board[i][j+1] = 0;
                   l = 1;
               }
           }
       }
       random(l);
    }
}

