#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool sprawdz(vector<int> l){
    bool czy;
    if(l[0] == l[1]){
        return false;
    }
    if(l[0] > l[1]){
        czy = true;
    }
    else{
        czy = false;
    }
    for(int i = 0; i < l.size()-1; i++){
        if(czy && (l[i] <= l[i+1] || l[i] - l[i+1] > 3)){
            return false;
        }
        else if(!czy && (l[i] >= l[i+1] || l[i+1] - l[i] > 3)){
            return false;
        }
    }
    return true;
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    int res1 = 0, res2 = 0;
    for(int i = 0; i < 1000; i++){
        string x;
        getline(cin,x);
        vector<int> l;
        string pom;
        for(int j = 0; j < x.size();j++){
            if(x[j] != ' '){
                pom.push_back(x[j]);
            }
            else{
                l.push_back(stoi(pom));
                pom.clear();
            }
        }
        l.push_back(stoi(pom));
        pom.clear();
        if(sprawdz(l)){
            res1++;
        }
        for(int i = 0; i < l.size(); i++){
            vector<int> pom = l;
            pom.erase(pom.begin()+i);
            if(sprawdz(pom)){
                res2++;
                break;
            }
        }
        l.clear();
        x.clear();
    }
    cout << "Part 1: " << res1 << ", Part 2: " << res2;
}