#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    vector<ll> lista1, lista2;
    for(int i = 0; i < 2000; i++){
        ll pom;
        cin >> pom;
        if(i % 2 == 0){
            lista1.push_back(pom);
        }
        else{
            lista2.push_back(pom);
        }
    }
    ll suma[100000];
    for(int i = 0; i < 100000; i++){
        suma[i] = 0;
    }
    for(int i = 0; i < 1000; i++){
        suma[lista2[i]]++; 
    }
    ll wyn = 0;
    for(int i = 0; i < 1000; i++){
        wyn += lista1[i] * suma[lista1[i]];
    }
    cout << wyn;
}