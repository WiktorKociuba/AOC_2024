#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXI = 45;
char mapa[MAXI][MAXI];
int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
ll wyn = 0;

void dfs_grid(int x, int y){
    if(mapa[x][y] == '9'){
        wyn++;
        return;
    }
    for(int i = 0; i < 4; i++){
        pair<int,int> sas = {x+dx[i],y+dy[i]};
        if(sas.first >= 0 && sas.first < MAXI && sas.second >= 0 && sas.second < MAXI){
            if(mapa[sas.first][sas.second] == mapa[x][y]+1){
                dfs_grid(sas.first,sas.second);
            }
        }
    }
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    for(int i = 0; i < MAXI; i++){
        for(int j = 0; j < MAXI; j++){
            cin >> mapa[i][j];
        }
    }
    for(int i = 0; i < MAXI; i++){
        for(int j = 0; j < MAXI; j++){
            if(mapa[i][j] == '0'){
                dfs_grid(i,j);
            }
        }
    }
    cout << wyn;
}