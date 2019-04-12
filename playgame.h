#ifndef PLAYGAME_H
#define PLAYGAME_H
#include<bits/stdc++.h>
#include"SPARSEMATRIX.h"
using namespace std;

// Template class to play game for a player
template<class T>
class playGame
{
private:
    int score;
    int coins;
    int moves;
    int n;
public:
    // Constructor
    playGame(int sze)
    {
        score=0;
        coins=0;
        moves=0;
        n=sze;
    }
    // Function return's final score of the player
    pair<pair<int, int>, int> playerResult()
    {
        pair<pair<int, int>, int> res;
        res.first.first = coins;
        res.first.second = moves;
        score = coins+moves;
        res.second = score;
        return res;
    }
    // Prints the Maze at each Step
    int printMaze(int x, int y,int isGameOver)
    {
        if(x<0 || x==n || y<0 || y==n)
        {
                isGameOver=-1;
                return isGameOver;
        }
        for(int i=0; i<n; i++)
        {
            cout<<"          ";
            for(int j=0; j<n; j++)
            {
                if(isGameOver==1)
                    cout<<"X ";
                else if(i==x && j==y)
                    printf("%c ",1);
				else if(x==n-1 && y==n-1)
					{printf("%c ",1);
					isGameOver=0;}
                else if(i==n-1 && j==n-1)
                    cout<<"END";
                else
                    cout<<"_ ";
            }
            cout<<endl;
        }
    return isGameOver;
	}
     // Prints player Current score at each step
    void printCurrentScore()
    {
        cout<<"\n\n";
        cout<<"   Player Current Score is:\n";
        cout<<"      Coins Collected So Far: "<<coins;
        cout<<"\n      Moves Moved: "<<moves<<endl;
    }

    // Main Function of the Game
    void startGame(T sp)
    {
        cout<<"               USE --W A S D--(in lowerCase) TO MOVE UP LEFT RIGHT AND DOWN respectively\n\n\n";
        char ch;
        int flag=1;
        int x=0,y=0;
        int a,b;
        SparseMatrix sm;
        int z = printMaze(x,y,2);
        printCurrentScore();
        while(1)
            {
                fflush(stdin);
                if(sp.get(x,y)==-1)
      	    	{
      	    	    flag=0;
      	    		cout<<"\t\t\tOOPS!!! YOU STEPPED ON THE PITHOLE\n\t\t\tGAME OVER\n\n";
      	    		break;
                }
                else
                {
                        coins+=sp.get(x,y);
                }
                ch=getchar();
                switch(ch)
                {
                    case 'w':
                        system("cls");
                        cout<<"-----------------------------------The UseLess Game--------------------------------------------\n\n\n";
                        cout<<"\t             USE --W A S D--(in lowerCase) TO MOVE UP LEFT RIGHT AND DOWN respectively\n\n\n";
                        a=x;
                        b=y;
                        x=x-1;
                        y=y;
                        z=printMaze(x,y,z);
                        if(z!=-1)
                            moves++;
                        else
                            {
                                if(sp.get(x,y)==-1)
                                {
                                    flag=0;
                                    cout<<"\t\t\tOOPS!!! YOU STEPPED ON THE PITHOLE\n\t\t\tGAME OVER\n\n";
                                    break;
				                }
				                else
                                {
                                    coins+=sp.get(x,y);
                                   printCurrentScore();
                                }
                            }
                        break;
      	    	case 'a':
      	    	    system("cls");
      	    	    cout<<"-----------------------------------\bThe UseLess Game--------------------------------------------\n\n\n";
      	    	    cout<<"               USE --W A S D--(in lowerCase) TO MOVE UP LEFT RIGHT AND DOWN respectively\n\n\n";
      	    	    a=x;
                    b=y;
                    x=x;
      	    	    y=y-1;
      	    	    z=printMaze(x,y,z);
      	    	    if(z!=-1)
                        moves++;
                    else
                        {
                            if(sp.get(x,y)==-1)
                            {
                                flag=0;
                                cout<<"\t\t\tOOPS!!! YOU STEPPED ON THE PITHOLE\n\t\t\tGAME OVER\n\n";
                                break;
                            }
                            else
                            {
                                coins+=sp.get(x,y);
                                printCurrentScore();
                            }
                        }
                    break;
      	    	case 's':
      	    	    system("cls");
      	    	    cout<<"-----------------------------------\bThe UseLess Game--------------------------------------------\n\n\n";
      	    	    cout<<"               USE --W A S D--(in lowerCase) TO MOVE UP LEFT RIGHT AND DOWN respectively\n\n\n";
      	    	    a=x;
      	    	    b=y;
      	    	    x=x+1;
      	    	    y=y;
                    if(x==n){
                            z=-1;
                       goto abc;
                    }
      	    	    z=printMaze(x,y,z);
      	    	    if(z!=-1)
                        moves++;
                    else
                    {
                        if(sp.get(x,y)==-1)
                        {
                            cout<<"\t\t\tOOPS!!! YOU STEPPED ON THE PITHOLE\n\t\t\tGAME OVER\n\n";
                            flag=0;
                            break;
                        }
                        else
                        {
                            coins+=sp.get(x,y);
                            printCurrentScore();
                        }
                    }
                    break;
      	    	case 'd':
      	    	    system("cls");
      	    	    cout<<"-----------------------------------\bThe UseLess Game--------------------------------------------\n\n\n";
      	    	    cout<<"               USE --W A S D--(in lowerCase) TO MOVE UP LEFT RIGHT AND DOWN respectively\n\n\n";
      	    	    a=x;
      	    	    b=y;
      	    	    x=x;
      	    	    y=y+1;
      	    	    z=printMaze(x,y,z);
      	    	    if(z!=-1)
                        moves++;
                    else
                    {
                        if(sp.get(x,y)==-1)
                        {
                            cout<<"\t\t\tOOPS!!! YOU STEPPED ON THE PITHOLE\n\t\t\tGAME OVER\n\n";
                            flag=0;
                            break;
                        }
                        else
                        {
                            coins+=sp.get(x,y);
                            printCurrentScore();
                        }
                    }
                    break;
      	    	default:
      	    	    cout<<"Please enter a valid key\n";
      	    	    continue;
			  }
			  fflush(stdout);
		abc:
		if(z==-1)
        {
			system("cls");
            cout<<"-----------------------------------\bThe UseLess Game--------------------------------------------\n\n\n";
            cout<<"               USE --W A S D--(in lowerCase) TO MOVE UP LEFT RIGHT AND DOWN respectively\n\n\n";
            z = printMaze(a,b,2);
            x=a;
            y=b;
            cout<<"\n\n\t\tINVALID MOVE\n\n";
		}
		if(z==0)
        {
            break;
		}
		if(flag==0)
		{
		    break;
		}
        printCurrentScore();
        cout<<endl;
    }
    }
};
#endif
