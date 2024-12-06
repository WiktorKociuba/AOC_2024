#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXI = 130;
char grid[130][130];

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
    while(x >= 0 && x < MAXI && y >= 0 && y < MAXI){
        if(grid[x][y] == '>'){
            if(y+1 < MAXI && grid[x][y+1] == '#'){
                grid[x][y] = 'v';
            }
            else{
                grid[x][y] = 'X';
                y++;
                if(y<MAXI){
                    grid[x][y] = '>';
                }
            }
        }
        if(grid[x][y] == '<'){
            if(y-1 >= 0 && grid[x][y-1] == '#'){
                grid[x][y] = '^';
            }
            else{
                grid[x][y] = 'X';
                y--;
                if(y>=0){
                    grid[x][y] = '<';
                }
            }
        }
        if(grid[x][y] == '^'){
            if(x-1>=0 && grid[x-1][y] == '#'){
                grid[x][y] = '>';
            }
            else{
                grid[x][y] = 'X';
                x--;
                if(x>=0){
                    grid[x][y] = '^';
                }
            }
        }
        if(grid[x][y] == 'v'){
            if(x+1 < MAXI && grid[x+1][y] == '#'){
                grid[x][y] = '<';
            }
            else{
                grid[x][y] = 'X';
                x++;
                if(x<MAXI){
                    grid[x][y] = 'v';
                }
            }
        }
    }
    int wyn = 0;
    for(int i = 0 ; i < MAXI; i++){
        for(int j = 0; j < MAXI; j++){
            if(grid[i][j] == 'X'){
                wyn++;
            }
        }
    }
    cout << wyn;
}