#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXI = 50;
char tab[MAXI][MAXI], cop[MAXI][MAXI];
vector<pair<int,int>> poz[128];

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    for(int i = 0; i < MAXI; i++){
        for(int j = 0; j < MAXI; j++){
            char pom;
            cin >> pom;
            tab[i][j] = pom;
            cop[i][j] = pom;
            if(pom !='.'){
                poz[pom].push_back({i,j});
            }
        }
    }
    ll wyn = 0;
    for(int i = 0; i < MAXI; i++){
        for(int j = 0; j < MAXI; j++){
            if(tab[i][j] != '.'){
                if(!poz[tab[i][j]].empty()){
                    wyn++;
                }
                for(int z = 0; z < poz[tab[i][j]].size(); z++){
                    bool fs = false, sec = false;
                    pair<int,int> pom = poz[tab[i][j]][z];
                    if(pom == make_pair(i,j)){
                        continue;
                    }
                    int x,y;
                    if(pom.first < i){
                        x = pom.first - (i-pom.first);
                        fs = true;
                    }
                    else{
                        x = pom.first + (pom.first-i);
                        fs = false;
                    }
                    if(pom.second < j){
                        y = pom.second - (j-pom.second);
                        sec = true;
                    }
                    else{
                        y = pom.second + (pom.second-j);
                        sec = false;
                    }
                    while(x >= 0 && x < MAXI && y >= 0 && y < MAXI){
                        if(cop[x][y] == '.'){
                            cop[x][y] = '#';
                            wyn++;
                        }
                        if(fs){
                            x -= i-pom.first;
                        }
                        else{
                            x += pom.first-i;
                        }
                        if(sec){
                            y -= j-pom.second;
                        }
                        else{
                            y += pom.second-j;
                        }
                    }
                }
            }
        }
    }
    cout << wyn;
    return 0;
}