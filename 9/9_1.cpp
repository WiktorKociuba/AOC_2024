#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    string x;
    vector<int> disk;
    cin >> x;
    int id = 0;
    for(int i = 0; i < x.size(); i++){
        if(i % 2 == 0){
            for(int j = 0; j < x[i] - '0'; j++){
                disk.push_back(id);
            }
            id++;
        }
        else{
            for(int j = 0; j < x[i] - '0'; j++){
                disk.push_back(-1);
            }
        }
    }
    int lpoz = 0;
    ll wyn = 0;
    for(int i = disk.size()-1; i >= 0; i--){
        if(lpoz >= i){
            break;
        }
        int pom = disk[i];
        disk[i] = -1;
        for(int j = lpoz; j < disk.size(); j++){
            if(disk[j] == -1){
                disk[j] = pom;
                lpoz = j;
                break;
            }
        }
    }
    for(int i = 0; i < disk.size(); i++){
        if(disk[i] == -1){
            break;
        }
        wyn += i*(disk[i]);
    }
    cout << wyn;
}