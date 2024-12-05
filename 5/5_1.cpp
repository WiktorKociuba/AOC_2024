//input without pipes and blank space
#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll p1 = 1176, p2 = 189;
vector<int> r[120];

bool czy_w_tab(int l, vector<int> c){
    for(int i = 0; i < c.size(); i++){
        if(c[i] == l)
            return true;
    }
    return false;
}

bool czy_przed(int in, int k, vector<int> c){
    for(int i = in; i < c.size(); i++){
        if(c[i] == k){
            return true;
        }
    }
    return false;
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll wyn = 0;
    for(int i = 0; i < p1; i++){
        int x,y;
        cin >> x >> y;
        r[x].push_back(y);
    }
    for(int i = 0; i < p2; i++){
        string l;
        getline(cin,l);
        vector<int> up;
        for(int j = 0; j < l.size(); j++){
            string pom = "";
            pom.push_back(l[j]);
            pom.push_back(l[j+1]);
            up.push_back(stoi(pom));
            j+=2;
        }
        if(i == 0){
            continue;
        }
        bool flag = true;
        for(int j = 0; j < up.size(); j++){
            for(int z = 0; z < r[up[j]].size(); z++){
                if(czy_w_tab(r[up[j]][z],up)){
                    if(!czy_przed(j,r[up[j]][z],up)){
                        flag = false;
                    }
                }
            }
        }
        if(flag){
            wyn+= up[up.size()/2];
        }
    }
    cout << wyn;
    return 0;
}