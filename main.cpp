#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace std;

vector<int> set;
vector<int> Prim;

bool primvizsgalo(int x);
void kiir();
void primgeneralo(int ossz, int N, int S, int index,int db);
void primosszeg(int N, int S, int P,int db);
void primosszegF(int N, int S, int P,int db);


int main()
{
    int db=0;
    int S = 31, N = 3, P = 3;
    cout<<N<<" Prim szam melyek nagyobbak mint "<<P<<" es az osszeguk = "<<S<<" :\n";

    cout <<"\n Sima backtrack:\n";
    primosszeg(N, S, P,db);

    S = 31, N = 3, P = 3, db=0;
    cout <<"\n Backtrack +FWD:\n";
    primosszegF(N, S, P,db);

    return 0;
}

bool primvizsgalo(int x)
{
    int gyok = sqrt(x);
    bool flag = true;
    if (x == 1)
        return false;
    for (int i = 2; i <= gyok; i++)
        if (x % i == 0)
            return false;
    return true;
}
void kiir()
{
    int length = set.size();
    for (int i=0; i<length; i++)
        cout<<set[i]<<"\t";
    cout<<endl;
}
void primgeneralo(int ossz, int N, int S, int index,int db)
{
    if (ossz == S && set.size() == N)
    {
        db=+2;
        kiir();
        return;
    }
    if (ossz > S || index == Prim.size())
    {
        return;
    }
    db+=2;
    set.push_back(Prim[index]);
    primgeneralo(ossz+Prim[index], N, S, index+1,db);
    set.pop_back();
    primgeneralo(ossz, N, S, index+1,db);
}
void primosszeg(int N, int S, int P,int db)
{

    for (int i = P+1; i <=S ; i++)
    {
        if (primvizsgalo(i))
            Prim.push_back(i);
            db+=1;
    }
    primgeneralo(0, N, S, 0,db);
    cout <<"Ertekadasok szama:"<<db;
}
void primosszegF(int N, int S, int P,int db)
{

    for (int i = P+1; i <=S ; i++)
    {
        if (primvizsgalo(i))
            Prim.push_back(i);
            db+=1;

    }
    if (Prim.size() < N)
        return;
    primgeneralo(0, N, S, 0,db);
    db+=1;
    cout <<"Ertekadasok szama:"<<db;
}
