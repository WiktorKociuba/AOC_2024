#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXX = 103, MAXY = 101;
int ma[MAXX][MAXY];
int x,y,vx,vy;

void sym(){
    for(int i = 0; i < 100; i++){
        x+=vx;
        y+=vy;
        if(x >= MAXX){
            x-=MAXX;
        }
        if(x<0){
            x+=MAXX;
        }
        if(y>=MAXY){
            y-=MAXY;
        }
        if(y<0){
            y+=MAXY;
        }
    }
    ma[x][y]++;
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    for(int i = 0; i < MAXX; i++){
        for(int j = 0; j < MAXY; j++){
            ma[i][j] = 0;
        }
    }
    ll p = 0, d = 0, t = 0, c = 0;
    for(int i = 0; i < 500; i++){
        cin >> y >> x >> vy >> vx;
        sym();
    }
    int xlim = (MAXX-1)/2, ylim = (MAXY-1)/2;
    for(int i = 0; i < MAXX; i++){
        for(int j = 0; j < MAXY; j++){
            if(i<xlim && j<ylim){
                p+=ma[i][j];
            }
            else if(i<xlim && j>ylim){
                d+=ma[i][j];
            }
            else if(i>xlim && j<ylim){
                t+=ma[i][j];
            }
            else if(i>xlim && j>ylim){
                c+=ma[i][j];
            }
            else{
                ma[i][j] = 9;
            }
        }
    }
    for(int i = 0; i < MAXX; i++){
        for(int j = 0; j < MAXY; j++){
            cout << ma[i][j];
        }
        cout << endl;
    }
    cout << p*d*t*c;
}