#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXI = 71;
char grid[MAXI][MAXI];
bool odw[MAXI][MAXI];
int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0}, odl[MAXI][MAXI];

void bfs(){
    for(int i = 0; i < MAXI; i++){
        for(int j = 0; j < MAXI; j++){
            odw[i][j] =false;
            odl[i][j] = 0;
        }
    }
    queue<pair<int,int>> q;
    q.push({0,0});
    odw[0][0] = true;
    odl[0][0] = 0;
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            pair<int,int> sas = {x+dx[i],y+dy[i]};
            if(sas.first >= 0 && sas.first < MAXI && sas.second >= 0 && sas.second < MAXI){
                if(odw[sas.first][sas.second] == false && grid[sas.first][sas.second] != '#'){
                    odw[sas.first][sas.second] = true;
                    q.push(sas);
                    odl[sas.first][sas.second] = odl[x][y] +1;
                }
            }
        }
    }
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    for(int i = 0; i < MAXI; i++){
        for(int j = 0; j < MAXI; j++){
            grid[i][j] ='.';
        }
    }
    for(int i = 0; i < 3450; i++){
        int x,y;
        cin >> y >> x;
        grid[x][y] = '#';
        bfs();
        if(odl[70][70] == 0){
            cout << x << " " << y;
            break;
        }
    }
    bfs();
    cout << odl[70][70];
}