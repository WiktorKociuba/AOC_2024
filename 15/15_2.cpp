#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXI = 50, MAXJ = 100;
vector<char> ma[MAXI];
string ins;
pair<int,int> poz;
char prz[MAXI][MAXJ];
bool odw[MAXI][MAXJ], fl = true;
int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};

void dfs(int x, int y, int ki){
    if(odw[x][y]){
        return;
    }
    odw[x][y] = true;
    prz[x][y] = ma[x][y];
    if(ma[x+dx[ki]][y] == '#'){
        fl = false;
    }
    else if(ma[x][y] == ']'){
        if(ma[x+dx[ki]][y] == '[' || ma[x+dx[ki]][y] == ']'){
            dfs(x+dx[ki],y,ki);
        }
        dfs(x,y-1,ki);
    }
    else if(ma[x][y] == '['){
        if(ma[x+dx[ki]][y] == '[' || ma[x+dx[ki]][y] == ']'){
            dfs(x+dx[ki],y,ki);
        }
        dfs(x,y+1,ki);
    }
}

void czysc(){
    for(int i = 0; i < MAXI; i++){
        for(int j = 0; j < MAXJ; j++){
            odw[i][j] = false;
            prz[i][j] = '.';
        }
    }
}

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
        default:
            if(dy[ki] != 0){
                for(int j = y; j >= 0 && j < MAXJ; j+=dy[ki]){
                    if(ma[x][j] == '#'){
                        break;
                    }
                    if(ma[x][j] == '.'){
                        ma[x].erase(ma[x].begin()+j);
                        ma[x].insert(ma[x].begin()+y,'.');
                        poz = {x,y+dy[ki]};
                        break;
                    }
                }
            }
            else if(dx[ki] != 0){
                fl = true;
                czysc();
                odw[x][y] = true;
                prz[x][y] = '@';
                dfs(x+dx[ki],y,ki);
                if(fl){
                    ma[x][y] = '.';
                    if(ma[x+dx[ki]][y] == ']'){
                        ma[x+dx[ki]][y-1] = '.';
                    }
                    if(ma[x+dx[ki]][y] == '['){
                        ma[x+dx[ki]][y+1] = '.';
                    }
                    for(int i = 0; i < MAXI; i++){
                        for(int j = 0; j < MAXJ; j++){
                            if(odw[i][j]){
                                ma[i][j] = '.';
                            }
                        }
                    }
                    for(int i = 0; i < MAXI; i++){
                        for(int j = 0; j < MAXJ; j++){
                            if(odw[i][j]){
                                ma[i+dx[ki]][j] = prz[i][j];
                            }
                        }
                    }
                    poz = {x+dx[ki],y};
                }
            }
    }
}

ll zlicz(){
    ll wyn = 0;
    for(int i = 0; i < MAXI; i++){
        for(int j = 0; j < MAXJ; j++){
            if(ma[i][j] == '['){
                wyn += i*100+j;
            }
        }
    }
    return wyn;
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    for(int i = 0; i < MAXI; i++){
        for(int j = 0; j < MAXJ; j++){
            char p1;
            cin >> p1;
            ma[i].push_back(p1);
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