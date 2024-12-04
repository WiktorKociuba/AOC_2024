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
            if(l[i][j] == 'M'){
                if(i-2>=0&&j+2<l[i].size())
                    if(l[i-1][j+1] == 'A' && l[i-2][j+2] == 'S' && l[i][j+2] == 'M' && l[i-2][j] == 'S'){
                        wyn++;
                    }
                    /*
                    S.S
                    .A.
                    M.M
                    */
                if(j+2<l[i].size()&&i+2<MAXI)
                    if(l[i+1][j+1] == 'A' && l[i+2][j+2] == 'S' && l[i][j+2] == 'M' && l[i+2][j] == 'S'){
                        wyn++;
                    }
                    /*
                    M.M
                    .A.
                    S.S
                    */
                if(i+2<MAXI&&j+2<l[i].size())
                    if(l[i+1][j+1] == 'A' && l[i+2][j+2] == 'S' && l[i+2][j] == 'M' && l[i][j+2] == 'S'){
                        wyn++;
                    }
                    /*
                    M.S
                    .A.
                    M.S
                    */
                if(j-2>=0&&i+2<MAXI)
                    if(l[i+1][j-1] == 'A' && l[i+2][j-2] == 'S' && l[i+2][j] == 'M' && l[i][j-2] == 'S'){
                        wyn++;
                    }
                    /*
                    S.M
                    .A.
                    S.M
                    */
            }
        }
    }
    cout << wyn;
    return 0;
}