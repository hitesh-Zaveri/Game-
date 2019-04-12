#ifndef MAZEGENERATOR_H
#define MAZEGENERATOR_H
#include<bits/stdc++.h>
#include"SPARSEMATRIX.h"
using namespace std;

// Base Class to generate Random variables
template<class T>
class Make_maze
{
private:
    int size;
    vector<int> trackx;
    vector<int> tracky;
    vector<int> trackval;
public:
    // Constructor called
    Make_maze(int N)
    {
        size=N;
        //cout<<size<<endl;;
    }

    // Generate Random coordinates X, Y with Random values
    pair<pair<int, int>, int> generateRandom(pair<pair<int, int>, int> ap, bool opt)
    {
        srand( time(NULL) );
        while (1)
        {
        int x = rand()%size;
        int y = rand()%size;
        int value = -1;
        if(opt == true)
            value = rand()%(30);
        if(x==0 && y==0 && value==-1)
        {
            srand(time(NULL));
            x=rand()%size;
            y=rand()%size;
        }
        vector<int>::iterator it1,it2;
        //cout<<"inside generateRandom "<<x<<' '<<y<<' '<<value<<endl;
        if(trackx.empty() && tracky.empty())
        {
            //cout<<"inside if for empty of generateRandom "<<x<<' '<<y<<' '<<value<<endl;
            tracky.push_back(y);
            trackx.push_back(x);
            trackval.push_back(value);
            ap.first.first = x;
            ap.first.second = y;
            ap.second = value;
            return ap;
        }
        it1 = find(trackx.begin(), trackx.end(), x);
        it2 = find(tracky.begin(), tracky.end(), y);
        if(it1 == trackx.end() && it2 == tracky.end())
        {
            //cout<<x<<' '<<y<<' '<<value<<endl;
            tracky.push_back(y);
            trackx.push_back(x);
            trackval.push_back(value);
            ap.first.first = x;
            ap.first.second = y;
            ap.second = value;
            return ap;
        }
        }
    }
    // function return SparseMatrix with randomly generated values
    T create_maze(T sp)
    {
        pair<pair<int, int>, int> pa;
        switch(size)
        {
        case 10:
            //cout<<"Switched 10\n";
            for(int i=0; i<6; i++){
                    pa = generateRandom(pa, true);
                    sp.store(pa.first.first, pa.first.second, pa.second);
            }
            for(int i=0; i<4; i++){
                    pa = generateRandom(pa, false);
                    sp.store(pa.first.first, pa.first.second, pa.second);
            }
            return sp;

        case 20:
            for(int i=0; i<12; i++){
                    pa = generateRandom(pa, true);
                    sp.store(pa.first.first, pa.first.second, pa.second);
            }
             for(int i=0; i<8; i++){
                    pa = generateRandom(pa, false);
                    sp.store(pa.first.first, pa.first.second, pa.second);
            }
            return sp;

        case 30:
            for(int i=0; i<15; i++){
                    pa = generateRandom(pa, true);
                    sp.store(pa.first.first, pa.first.second, pa.second);
            }
             for(int i=0; i<15; i++){
                    pa = generateRandom(pa, false);
                    sp.store(pa.first.first, pa.first.second, pa.second);
            }
            return sp;

        }
    }
};
#endif
