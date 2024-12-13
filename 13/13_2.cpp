#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll x=0,y=0,x2=0,y2=0,xc=0,yc=0;

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll wyn = 0;
    for(int i = 0; i < 320; i++){
        /*
        a*x+b*x2-xc=0
        a*y+b*y2-yc=0

        a=(xc-b*x2)/x
        a=(yc-b*y2)/y

        x(yc-b*y2)=y(xc-b*x2)
        x*yc-x*b*y2=y*xc-y*b*x2
        y*b*x2-x*b*y2=y*xc-x*yc
        b(y*x2-x*y2)=y*xc-x*yc
        b=(y*xc-x*yc)/(y*x2-x*y2)
        */
        cin >> x >> y >> x2 >> y2 >> xc >> yc;
        xc+=10000000000000;
        yc+=10000000000000;
        ll wb, wa;
        wb = (y*xc-x*yc)/(y*x2-x*y2);
        wa = (xc-wb*x2)/x;
        if((y*xc-x*yc) % (y*x2-x*y2) == 0 && (xc-wb*x2)%x==0){
            wyn+=wa*3+wb*1;
        }
    }
    cout << wyn;
    return 0;
}