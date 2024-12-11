#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<string> kam;

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    string pom;
    for(int i = 0; i < 8; i++){
        cin >> pom;
        kam.push_back(pom);
    }
    int lim = kam.size();
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < kam.size(); j++){
            if(kam[j] == "0"){
                kam[j] = "1";
            }
            else if(kam[j].size() % 2 == 0){
                string pom1 = kam[j].substr(0,(kam[j].size()/2)), pom2 = kam[j].substr(kam[j].size()/2);
                if(stoll(pom1) == 0){
                    pom1 = "0";
                }
                kam[j] = pom1;
                pom2 = to_string(stoll(pom2));
                kam.insert(kam.begin()+j+1,pom2);
                j++;
            }
            else{
                ll pom = stoll(kam[j])*2024;
                kam[j] = to_string(pom);
            }
        }
    }
    cout << kam.size();
}