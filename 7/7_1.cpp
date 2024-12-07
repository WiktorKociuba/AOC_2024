#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll szuk;
vector<ll> licz;
bool fl = false;

void szu(int i = 1, ll wyn = licz[0]){
    if(fl){
        return;
    }
    if(i == licz.size() && wyn == szuk){
        fl = true;
    }
    if(i >= licz.size()){
        return;
    }
    szu(i+1,wyn*licz[i]);
    szu(i+1,wyn+licz[i]);
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll wyn = 0;
    for(int i = 0; i < 850; i++){
        cin >> szuk;
        string pom,pom1="";
        getline(cin,pom);
        for(int j = 2; j < pom.size(); j++){
            if(pom[j] == ' '){
                licz.push_back(stoi(pom1));
                pom1.clear();
            }
            pom1.push_back(pom[j]);
        }
        licz.push_back(stoi(pom1));
        pom1.clear();
        szu();
        if(fl)
            wyn+=szuk;
        fl = false;
        licz.clear();
    }
    cout << wyn;
    return 0;
}