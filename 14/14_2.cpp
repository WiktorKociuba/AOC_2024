//manual search
#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXX = 103, MAXY = 101;
int ma[MAXX][MAXY];
int x,y,vx,vy;

void sym(){
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

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    for(int i = 0; i < MAXX; i++){
        for(int j = 0; j < MAXY; j++){
            ma[i][j] = 0;
        }
    }
    ll p = 0, d = 0, t = 0, c = 0;
    ll py[500], px[500], pvy[500], pvx[500];
    for(int i = 0; i < 500; i++){
        cin >> py[i] >> px[i] >> pvy[i] >> pvx[i];
    }
    for(int i = 0; i < 10000; i++){
        cout << i << endl;
        for(int j = 0; j < 500; j++){
            y = py[j]; x = px[j]; vy = pvy[j]; vx = pvx[j];
            if(ma[x][y] != 0){
                ma[x][y]--;
            }
            sym();
            ma[x][y]++;
            py[j] = y;
            px[j] = x;
        }
        for(int i = 0; i < MAXX; i++){
            for(int j = 0; j < MAXY; j++){
                cout << ma[i][j];
            }
            cout << endl;
        }
        cout << endl;
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
        }
    }
    cout << p*d*t*c;
}