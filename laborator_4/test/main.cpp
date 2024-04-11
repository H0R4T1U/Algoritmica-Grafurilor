#include <iostream>
#include <fstream>
#define INF 1000000
using namespace std;
int a[10000][10000];
ifstream fin("a.in");
int d[10000],v[10000];
int parinte[10000];
int n,n_start,finish;
void afisare_drum(int k){
    if(parinte[k] == -1){
        cout<<k<<" ";
        return;
    }
    afisare_drum(parinte[k]);
    cout<<k<<" ";
}
void dijkstra(int start){
    for(int i =0;i <n;i++){
        v[i] = 0;
        d[i] = a[start][i];
    }

    parinte[start] = -1;
    v[start] = 1;
    d[start] = 0;
    for(int k=0;k<n;k++){
        int pmin = INF;
        int imin = -1;
        for(int i = 0; i<n;i++){
            if(v[i] == 0 && d[i] < pmin){
                pmin = d[i];
                imin = i;
            }
        }
        if(imin != -1){
            for(int i =0;i<n;i++){
                if(v[i] == 0 && d[i] > d[imin]+a[imin][i]){
                    d[i] = d[imin]+a[imin][i];
                    parinte[i] = imin;
                }
            }
        }

    }
}

int main() {

    fin>>n>>n_start>>finish;
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            a[i][j] = INF;
        }
    }

    for(int i =0;i<n;i++){
        parinte[i] = -1;
    }
    int x,y,w;
    while(fin>>x>>y>>w){
        a[x][y] = w;
    }

    dijkstra(n_start);
    if(d[finish] != INF){
        afisare_drum(finish);
    }else{
        cout<<"Nu se poate ajunge in nodul" << finish << " Din:" << n_start;
    }

    return 0;
}
