#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MAXI = 140;
char dzial[MAXI][MAXI];
bool odw[MAXI][MAXI];
int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
ll pol = 1, plo = 0;

void dfs(ll x, ll y){
    if(odw[x][y]){
        pol = 0;
    }
    odw[x][y] = true;
    for(int i = 0; i < 4; i++){
        pair<ll,ll> sas = {x+dx[i],y+dy[i]};
        if(sas.first >= 0 && sas.first < MAXI && sas.second >= 0 && sas.second < MAXI){
            if(dzial[sas.first][sas.second] == dzial[x][y] && odw[sas.first][sas.second] == false){
                pol++;
                dfs(sas.first,sas.second);
            }
            else if(dzial[sas.first][sas.second] != dzial[x][y]){
                plo++;
            }
        }
        else if(sas.first < 0 || sas.first >= MAXI || sas.second < 0 || sas.second >= MAXI){
            plo++;
        }
    }
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    for(int i = 0; i < MAXI; i++){
        for(int j = 0; j < MAXI; j++){
            cin >> dzial[i][j];
        }
    }
    ll wyn = 0;
    for(int i = 0; i < MAXI; i++){
        for(int j = 0; j < MAXI; j++){
            dfs(i,j);
            cout << pol << " " << plo << endl;
                wyn += pol*plo;
            pol = 1;
            plo = 0;
        }
    }
    cout << wyn;
}