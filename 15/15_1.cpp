#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXI = 50;
char ma[MAXI][MAXI];
string ins;
pair<int,int> poz;

int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};

void prze(char k){
    int ki;
    switch(k){
        case '>':
            ki = 0;
            break;
        case '<':
            ki = 1;
            break;
        case '^':
            ki = 2;
            break;
        case 'v':
            ki = 3;
            break;
    }
    int x = poz.first, y = poz.second;
    switch(ma[x+dx[ki]][y+dy[ki]]){
        case '.':
            ma[x][y] = '.';
            ma[x+dx[ki]][y+dy[ki]] = '@';
            poz = {x+dx[ki],y+dy[ki]};
            break;
        case '#':
            break;
        case 'O':
            if(dx[ki] != 0){
                for(int i = x; i >= 0 && i < MAXI; i+=dx[ki]){
                    if(ma[i][y] == '.'){
                        ma[i][y] = 'O';
                        ma[x+dx[ki]][y] = '@';
                        poz = {x+dx[ki],y};
                        ma[x][y] = '.';
                        break;
                    }
                    if(ma[i][y] == '#'){
                        break;
                    }
                }
            }
            else if(dy[ki] != 0){
                for(int j = y; j >= 0 && j < MAXI; j+=dy[ki]){
                    if(ma[x][j] == '.'){
                        ma[x][j] = 'O';
                        ma[x][y+dy[ki]] = '@';
                        poz = {x,y+dy[ki]};
                        ma[x][y] = '.';
                        break;
                    }
                    if(ma[x][j] == '#'){
                        break;
                    }
                }
            }
            break;
    }
}

ll zlicz(){
    ll wyn = 0;
    for(int i = 0; i < MAXI; i++){
        for(int j = 0; j < MAXI; j++){
            if(ma[i][j] == 'O'){
                wyn += i*100+j;
            }
        }
    }
    return wyn;
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    for(int i = 0; i < MAXI; i++){
        for(int j = 0; j < MAXI; j++){
            cin >> ma[i][j];
            if(ma[i][j] == '@'){
                poz = {i,j};
            }
        }
    }
    cin >> ins;
    for(int i = 0; i < ins.size(); i++){
        char k = ins[i];
        prze(k);   
    }
    cout << zlicz();
    return 0;
}