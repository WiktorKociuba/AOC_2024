//brute force
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXI = 130;
char grid[MAXI][MAXI];
int z = 0, o = 100000000;

pair<int,int> find_guard(){
    for(int i = 0; i < MAXI; i++ ){
        for(int j = 0; j < MAXI; j++){
            if(grid[i][j] == '>' || grid[i][j] == '<' || grid[i][j] == '^' || grid[i][j] == 'v'){
                return {i,j};
            }
        }
    }
    return {0,0};
}

int czy_cykl(int x, int y,int a, int b, char tab[MAXI][MAXI]){
    cout << a << " " << b << endl;
    int ile[4] = {0,0,0,0}, h = 0;
    while(x >= 0 && x < MAXI && y >= 0 && y < MAXI){
        if(tab[x][y] == '>'){
            if(y+1 < MAXI && tab[x][y+1] == '#'){
                if(x == a && y+1 == b){
                    ile[0]++;
                }
                tab[x][y] = 'v';
            }
            else{
                tab[x][y] = 'X';
                y++;
                if(y<MAXI){
                    tab[x][y] = '>';
                }
            }
        }
        else if(tab[x][y] == '<'){
            if(y-1 >= 0 && tab[x][y-1] == '#'){
                tab[x][y] = '^';
                if(x == a && y-1 == b){
                    ile[1]++;
                }
            }
            else{
                tab[x][y] = 'X';
                y--;
                if(y>=0){
                    tab[x][y] = '<';
                }
            }
        }
        else if(tab[x][y] == '^'){
            if(x-1>=0 && tab[x-1][y] == '#'){
                if(x-1 == a && y == b){
                    ile[2]++;
                }
                tab[x][y] = '>';
            }
            else{
                tab[x][y] = 'X';
                x--;
                if(x>=0){
                    tab[x][y] = '^';
                }
            }
        }
        else if(tab[x][y] == 'v'){
            if(x+1 < MAXI && tab[x+1][y] == '#'){
                if(x+1 == a && y == b){
                    ile[3]++;
                }
                tab[x][y] = '<';
            }
            else{
                tab[x][y] = 'X';
                x++;
                if(x<MAXI){
                    tab[x][y] = 'v';
                }
            }
        }
        for(int k = 0; k<4; k++){
            if(ile[k] > 1){
                return 1;
            }
        }
        h++;
        if(o==h){
            return 1;
        }
    }
    return 0;
}

int main(){
    for(int i = 0; i < MAXI; i++ ){
        for(int j = 0; j < MAXI; j++){
            cin >> grid[i][j];
            cout << grid[i][j];
        }
        cout << endl;
    }
    pair<int,int> guard = find_guard();
    int x = guard.first, y = guard.second;
    int wyn = 0;
    for(int i = 0; i < MAXI; i++){
        for(int j = 0; j < MAXI; j++){
            if(grid[i][j] == '.'){
                grid[i][j] = '#';
                char pom[MAXI][MAXI];
                for(int i = 0; i < MAXI; i++){
                    for(int j = 0; j < MAXI; j++){
                        pom[i][j] = grid[i][j];
                    }
                }
                wyn+=czy_cykl(x,y,i,j,pom);
                grid[i][j] = '.';
            }
        }
    }
    cout << wyn;
}