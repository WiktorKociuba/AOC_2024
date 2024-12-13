#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll x=0,y=0,x2=0,y2=0,xc=0,yc=0;
pair<int,int> A[101], B[101];

void mnoz(){
    for(int i = 1; i < 101; i++){
        A[i] = {x*i,y*i};
        B[i] = {x2*i,y2*i};
    }
}

pair<int,int> sprawdz(){
    for(int i = 1; i < 101; i++){
        for(int j = 1; j < 101; j++){
            if(A[i].first + B[j].first == xc && A[i].second + B[j].second == yc){
                return {i,j};
            }
        }
    }
    return {0,0};
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll wyn = 0;
    for(int i = 0; i < 320; i++){
        cin >> x >> y;
        cin >> x2 >> y2;
        cin >> xc >> yc;
        mnoz();
        pair<int,int> w = sprawdz();
        wyn += w.first*3 + w.second*1;
    }
    cout << wyn;
    return 0;
}