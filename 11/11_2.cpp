#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<ll,ll>> kam;

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll pom;
    for(int i = 0; i < 8; i++){
        cin >> pom;
        kam.push_back({pom,1});
    }
    map<ll,ll> ile;
    for(int i = 0; i < 75; i++){
        ile.clear();
        for(int j = 0; j < kam.size(); j++){
            if(kam[j].first == 0){
                ile[1] += kam[j].second; 
            }
            else if(to_string(kam[j].first).size() % 2 == 0){
                string pom1 = to_string(kam[j].first).substr(0,(to_string(kam[j].first).size()/2)), pom2 = to_string(kam[j].first).substr(to_string(kam[j].first).size()/2);
                if(stoll(pom1) == 0){
                    pom1 = "0";
                }
                ile[stoll(pom1)] += kam[j].second;
                ile[stoll(pom2)] += kam[j].second;
            }
            else{
                ll pom = kam[j].first*2024;
                ile[pom] += kam[j].second;
            }
        }
        kam.clear();
        for(const auto &p : ile){
            kam.push_back({p.first,p.second});
        }
    }
    ll wyn = 0;
    for(int i = 0; i < kam.size(); i++){
        wyn += kam[i].second;
    }
    cout << wyn;
}