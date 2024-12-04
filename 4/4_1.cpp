#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<string> l;
const int MAXI = 140;

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    for(int i = 0; i < MAXI; i++){
        string s;
        cin >> s;
        l.push_back(s);
    }
    ll wyn = 0;
    for(int i = 0; i < MAXI; i++){
        for(int j = 0; j < l[i].size(); j++){
            if(l[i][j] == 'X'){
                if(i+3<MAXI)
                    if(l[i+1][j] == 'M' && l[i+2][j] == 'A' && l[i+3][j] == 'S'){
                        wyn++;
                    }
                if(i+3<MAXI&&j+3<l[i].size())
                    if(l[i+1][j+1] == 'M' && l[i+2][j+2] == 'A' && l[i+3][j+3] == 'S'){
                        wyn++;
                    }
                if(j+3<l[i].size())
                    if(l[i][j+1] == 'M' && l[i][j+2] == 'A' && l[i][j+3] == 'S'){
                        wyn++;
                    }
                if(i-3>=0&&j+3<l[i].size())
                    if(l[i-1][j+1] == 'M' && l[i-2][j+2] == 'A' && l[i-3][j+3] == 'S'){
                        wyn++;
                    }
                if(i-3>=0)
                    if(l[i-1][j] == 'M' && l[i-2][j] == 'A' && l[i-3][j] == 'S'){
                        wyn++;
                    }
                if(i-3>=0&&j-3>=0)
                    if(l[i-1][j-1] == 'M' && l[i-2][j-2] == 'A' && l[i-3][j-3] == 'S'){
                        wyn++;
                    }
                if(j-3>=0)
                    if(l[i][j-1] == 'M' && l[i][j-2] == 'A' && l[i][j-3] == 'S'){
                        wyn++;
                    }
                if(i+3<MAXI&&j-3>=0)
                    if(l[i+1][j-1] == 'M' && l[i+2][j-2] == 'A' && l[i+3][j-3] == 'S'){
                        wyn++;
                    }
            }
        }
    }
    cout << wyn;
    return 0;
}