#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll MAXI = 140;
char dzial[MAXI][MAXI];
bool odw[MAXI][MAXI];
int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};
ll pol = 1, plo = 0;
char pom[10+MAXI*2][10+MAXI*2];

void dfs(ll x, ll y){
    if(odw[x][y]){
        pol = 0;
    }
    x++;
    y++;
    pom[x*2][y*2] = dzial[x-1][y-1];
    pom[x*2+1][y*2] = dzial[x-1][y-1];
    pom[x*2][y*2+1] = dzial[x-1][y-1];
    pom[x*2+1][y*2+1] = dzial[x-1][y-1];
    x--;
    y--;
    odw[x][y] = true;
    for(int i = 0; i < 4; i++){
        pair<ll,ll> sas = {x+dx[i],y+dy[i]};
        if(sas.first >= 0 && sas.first < MAXI && sas.second >= 0 && sas.second < MAXI){
            if(dzial[sas.first][sas.second] == dzial[x][y] && odw[sas.first][sas.second] == false){
                pol++;
                dfs(sas.first,sas.second);
            }
        }
    }
}

void czysc(){
    for(int i = 0; i < 10+MAXI*2; i++){
        for(int j = 0; j < 10+MAXI*2; j++){
            pom[i][j] = '.';
        }
    }
}

void znajdz(int x, int y, int k = -1){
    if(pom[x][y] == '/'){
        plo++;
        pom[x][y] = '1';
        return;
    }
    if(k == -1){
        pom[x][y] = '/';
        k = 0;
    }
    if(k == 0){
        if(pom[x][y+1] != '.' && pom[x-1][y+1] != '.'){
            plo++;
            znajdz(x-1,y+1,2);
        }
        else if(pom[x][y+1] != '.'){
            znajdz(x,y+1,0);
        }
        else{
            plo++;
            znajdz(x+1,y,3);
        }
    }
    else if(k == 1){
        if(pom[x][y-1] != '.' && pom[x+1][y-1] != '.'){
            plo++;
            znajdz(x+1,y-1,3);
        }
        else if(pom[x][y-1] != '.'){
            znajdz(x,y-1,1);
        }
        else{
            plo++;
            znajdz(x-1,y,2);
        }
    }
    else if(k == 2){
        if(pom[x-1][y] != '.' && pom[x-1][y-1] != '.'){
            plo++;
            znajdz(x-1,y-1,1);
        }
        else if(pom[x-1][y] != '.'){
            znajdz(x-1,y,2);
        }
        else{
            plo++;
            znajdz(x,y+1,0);
        }
    }
    else if(k == 3){
        if(pom[x+1][y] != '.' && pom[x+1][y+1] != '.'){
            plo++;
            znajdz(x+1,y+1,0);
        }
        else if(pom[x+1][y] != '.'){
            znajdz(x+1,y,3);
        }
        else{
            plo++;
            znajdz(x,y-1,1);
        }
    }
    pom[x][y] = '1';
}

void znajdz2(int x, int y, int k = -1){
    if(pom[x][y] == '/'){
        pom[x][y] = '1';
        return;
    }
    if(k == -1){
        pom[x][y] = '/';
        k = 0;
    }
    if(k == 0){
        if(pom[x+1][y+1] != '.' && pom[x+1][y] == '.'){
            plo++;
            znajdz2(x+1,y+1,3);
        }
        else if(pom[x-1][y] != '.' && pom[x][y+1] == '.'){
            plo++;
            znajdz2(x-1,y,2);
        }
        else{
            znajdz2(x,y+1,0);
        }
    }
    else if(k == 1){
        if(pom[x-1][y-1] != '.' && pom[x-1][y] == '.'){
            plo++;
            znajdz2(x-1,y-1,2);
        }
        else if(pom[x+1][y] != '.' && pom[x][y-1] == '.'){
            plo++;
            znajdz2(x+1,y,3);
        }
        else{
            znajdz2(x,y-1,1);
        }
    }
    else if(k == 2){
        if(pom[x-1][y+1] != '.' && pom[x][y+1] == '.'){
            plo++;
            znajdz2(x-1,y+1,0);
        }
        else if(pom[x][y-1] != '.' && pom[x-1][y] == '.'){
            plo++;
            znajdz2(x,y-1,1);
        }
        else{
            znajdz2(x-1,y,2);
        }
    }
    else if(k == 3){
        if(pom[x+1][y-1] != '.' && pom[x][y-1] == '.'){
            plo++;
            znajdz2(x+1,y-1,1);
        }
        else if(pom[x][y+1] != '.' && pom[x+1][y] == '.'){
            plo++;
            znajdz2(x,y+1,0);
        }
        else{
            znajdz2(x+1,y,3);
        }
    }
    pom[x][y] = '1';
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
            czysc();
            dfs(i,j);
            pair<int,int> poz = {0,0};
            bool fl = false;
            for(int x = 0; x < 10+MAXI*2; x++){
                for(int y = 0; y < 10+MAXI*2; y++){
                    if(pom[x][y]!='.'){
                        poz = {x,y};
                        fl = true;
                        break;
                    }
                }
                if(fl){
                    break;
                }
            }
            znajdz(poz.first,poz.second);
            for(int x = 0; x < 10+MAXI*2; x++){
                for(int y = 0; y < 10+MAXI*2; y++){
                    if(pom[x][y] != '.' && pom[x][y] != '1' && pom[x+1][y] == '.'){
                        znajdz2(x,y);
                    }
                }
            }
            wyn += pol*plo;
            pol = 1;
            plo = 0;
        }
    }
    cout << wyn;
    return 0;
}