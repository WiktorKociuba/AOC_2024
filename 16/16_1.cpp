#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXI = 141;
char graf[MAXI][MAXI];
bool odw[MAXI][MAXI];
ll odl[MAXI][MAXI];
int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};

void dijkstra(){
    odl[MAXI-2][1] = 0;
    priority_queue<pair<ll,pair<ll,pair<ll,ll>>>> p;
    p.push({0,{0,{MAXI-2,1}}});
    while(!p.empty()){
        pair<ll,ll> poz = p.top().second.second;
        ll ki = p.top().second.first;
        p.pop();
        if(odw[poz.first][poz.second]){
            continue;
        }
        odw[poz.first][poz.second] = true;
        for(int i = 0; i < 4; i++){
            if(ki == i){
                if(graf[poz.first+dx[i]][poz.second+dy[i]] == '#'){
                    continue;
                }
                if(odl[poz.first+dx[ki]][poz.second+dy[ki]] > odl[poz.first][poz.second] + 1){
                    odl[poz.first+dx[ki]][poz.second+dy[ki]] = odl[poz.first][poz.second] + 1;
                    p.push({-odl[poz.first+dx[ki]][poz.second+dy[ki]],{ki,{poz.first+dx[ki],poz.second+dy[ki]}}});
                }
            }
            else{
                if(graf[poz.first+dx[i]][poz.second+dy[i]] == '#'){
                    continue;
                }
                if(odl[poz.first+dx[i]][poz.second+dy[i]] > odl[poz.first][poz.second] + 1001){
                    odl[poz.first+dx[i]][poz.second+dy[i]] = odl[poz.first][poz.second] + 1001;
                    p.push({-odl[poz.first+dx[i]][poz.second+dy[i]],{i,{poz.first+dx[i],poz.second+dy[i]}}});
                }
            }
        }
    }
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    for(int i = 0; i < MAXI; i++){
        for(int j = 0; j < MAXI; j++){
            cin >> graf[i][j];
            if(graf[i][j] == '#'){
                odw[i][j] = true;
            }
            odl[i][j] = LLONG_MAX;
        }
    }
    dijkstra();
    cout << odl[1][MAXI-2];
}