#include <iostream>
#include <fstream>
#define INF 1000
using namespace std;
ifstream in("../graf.txt");
void Moore(int nodStart, int nrNoduri, int matAd[100][100], int l[])
{
    int Q[100], st = 1, dr = 1;

    l[nodStart] = 0;
    Q[st] = nodStart;

    for (int i = 1; i <= nrNoduri; i++)
        if (i != nodStart)
            l[i] = INF;

    while (st <= dr)
    {
        int x = Q[st];
        for (int y = 1; y <= nrNoduri; y++)
            if (matAd[x][y] == 1 && l[y] == INF)
            {
                l[y] = l[x] + 1;
                Q[++dr] = y;
            }
        st++;
    }
}
void citesteGraf(int &nrNoduri, int &nodStart, int matAd[100][100])
{
    int x, y;
    in >> nrNoduri >> nodStart;
    while (in >> x >> y)
    {
        matAd[x][y] = matAd[y][x] = 1;
    }
}
int main()
{
    int nrNoduri, nodStart, matAd[100][100], l[100];
    citesteGraf(nrNoduri, nodStart, matAd);
    Moore(nodStart, nrNoduri, matAd, l);

    cout << "Distante minime de la nodul " << nodStart << ":\n";
    for (int i = 1; i <= nrNoduri; i++)
        if (l[i] == INF)
            cout << "Nodul " << i << ": nu este accesibil\n";
        else
            cout << "Nodul " << i << ": " << l[i]<<"\n";



    return 0;
}
