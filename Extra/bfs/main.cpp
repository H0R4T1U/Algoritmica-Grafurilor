#include <iostream>
#include <fstream>
using namespace std;
int a[100][100];
int v[100];
int queue[100];
int n,m;
int bfs(int start){
    int i,k,st,dr;
    st=dr=0;
    queue[st] = start;
    v[start] = 1;
    while(st <= dr) {
        for (i = 0; i < n; i++) {
            k = queue[st];
            if (v[i] == 0 && a[k][i] == 1) {
                v[i] = 1;
                queue[++dr] = i;
            }
        }
        st++;
    }
    return dr;
}
int main() {
    ifstream fin("../a.in");

    fin>>n;
    fin>>m;
    for(int i =0 ;i <m;i++){
        int x,y;
        fin >> x >>y;
        a[x][y]=a[y][x]=1;
    }
    cout<<"Noduri Vizitate din nodul 0:"<<bfs(0)<<endl;
    for(int i =0 ; i<n;i++){
        if(v[i]){
            cout<<i<<" ";
        }
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
