#include<bits/stdc++.h>
//header file for Multi-List
#include"SPARSEMATRIX.h"
// Header file to generate Random variables in Multi-list
#include"MAZEGENERATOR.h"
#include"PLAYGAME.h"
using namespace std;
//Function display's Heading/Name of the Game at each instance
void printHeader()
{
    system("cls");
    cout<<"-----------------------------------\bThe UseLess Game--------------------------------------------\n\n\n";
}

// Prints game Rules and Regulations
void printInfo()
{
    cout<<"\tYour task will be to reach to the End of the Maze.\n\tWhen a coin place will be encountered your score will automatically update.\n\tIf you";
    cout<<"encounter a pit Hole Game will automatically  be over and Next starts playing.\n\tIf he also will encounter a pit Hole Game Over and result Displays.\n";
    cout<<"\tAt the end the player with Maximum coins and less Moves will win the Game\n";
    cout<<"\tExtra point's will be awarded to player who reaches the End\n";
    // cout<<"\tWhen a player encounters a pit hole it will be represented by 'X' symbol.\n";
    cout<<"\n\n\t         Happy Playing!          \n";
    system("pause");
}

// Function returns an integer deppecting the level chosen by the user
int selectLevel()
{
    int choice;
    // cout<<"-----------------------The UseLess Game------------------------------\n\n\n";
    cout<<"Select Your Level\n1. Easy\n2. Medium\n3. Hard\n(Note-If Entered choice is not present above then by Default Hard will be considered)\n";
    cin>>choice;
    switch(choice)
    {
        case 1:
            return 10;
        case 2:
            return 20;
        case 3:
            return 30;
        default:
            return 30;
    }
}

// When a player finishes game or he fells in a pit hole his overall score is displayed
void printPlayerInfo(int n, int coins, int moves, int score)
{
    system("cls");
    printHeader();
    cout<<"Player "<<n<<" Score:\n\n";
    cout<<"\tTotal Coins Collected "<<coins<<endl;
    cout<<"\tTotal No. of Moves "<<moves<<endl;
    cout<<"\tTotal Score "<<score<<endl<<endl;
    if(n==1)
    {
        cout<<"\t\tPlayer 2 play's Now\n";
    }
    system("pause");
}

// Prints the maze and where the coins/pit holes were
void printMatrix(SparseMatrix sparseMatrix, int N)
{
    system("pause");
    system("cls");
    printHeader();
    cout<<"\n\t\tThe Maze was: \n\n"<<endl;
    for (int i=0; i<N; i++)
    {
        cout<<"          ";
        for (int j=0; j<N; j++)
        {
            if (sparseMatrix.get(i,j) == NULL)
                cout<<"_ ";
            else
                cout<<sparseMatrix.get(i,j)<<' ';
        }
        cout<<endl;
    }
    cout<<"\n\n\nTotal no of Coin's + Pit Holes were: "<<sparseMatrix.elementCount()<<endl;
}

// Prints result at the End of the Game
int printResult(SparseMatrix sparseMatrix,int player1Score, int player2Score, int N)
{
    char choice;
    char enteredChoice;
    cout<<"              GAME RESULT'S!\n\n\n\n";
    cout<<"                WOOOOOW\n";
    if (player1Score > player2Score)
        cout<<"           PLAYER "<<1<<" WINS THE GAME\n\n\n\n\n\n\n\n";
    else if(player1Score < player2Score)
        cout<<"           PLAYER "<<2<<" WINS THE GAME\n\n\n\n\n\n\n\n";
    if(player1Score==player2Score)
        cout<<"           It's a DRAW\n\n\n\n\n\n\n\n";
    cout<<"\tWant to see where the pit holes and coins were (Y/N)(Default No):";
    cin>>choice;
    if(choice=='y' || choice=='Y')
        printMatrix(sparseMatrix, N);
    system("pause");
    cout<<"    Play Again (Y/N): ";
    cin>>enteredChoice;
    if(enteredChoice=='y' || enteredChoice=='Y')
        return 1;
    else
        return 0;

}

// Driver Program
int main()
{
    fflush(stdout);

    system("color 0A");
    system("title The UseLess Game");
    system("cls");
    printHeader();
    printInfo();
    while(1)
    {
        // Size of the Matrix
        int N;
        printHeader();
        N = selectLevel();
        system("cls");
        printHeader();

        // Creating Multi-List
        SparseMatrix sparseMatrix(N);
        Make_maze<SparseMatrix> mz(N);
        sparseMatrix = mz.create_maze(sparseMatrix);
        playGame<SparseMatrix> player1(N), player2(N);

        // Player 1 Turn
        player1.startGame(sparseMatrix);
        system("pause");
        system("cls");
        printHeader();
        pair<pair<int, int>, int> player1Result = player1.playerResult();
        printPlayerInfo(1, player1Result.first.first, player1Result.first.second, player1Result.second);

        // Player 2 turn
        system("cls");
        printHeader();
        player2.startGame(sparseMatrix);
        pair<pair<int, int>, int> player2Result = player2.playerResult();
        printPlayerInfo(2, player2Result.first.first, player2Result.first.second, player2Result.second);

        // End Result
        system("cls");
        printHeader();
        if(printResult(sparseMatrix, player1Result.second, player2Result.second, N))
        {
            continue;
        }
        else
            break;
        system("pause");
        fflush(stdout);
    }
    return 0;
}
