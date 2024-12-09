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
    ll wyn = 0;
    int il = 0;
    for(int i = disk.size()-1; i >= 0; i--){
        int pom = disk[i];
        il++;
        if(disk[i] == disk[i-1]){
            continue;
        }
        bool fl = false;
        int ile = 0, poz = 0;
        for(int j = 0; j < disk.size(); j++){
            if(disk[j] == -1 && !fl){
                poz = j;
                fl = true;
            }
            if(disk[j] == -1 && fl){
                ile++;
            }
            if(disk[j] != -1 && fl){
                if(poz > i){
                    break;
                }
                if(ile>=il){
                    int h = il;
                    for(int z = poz; il>0; z++, il-- ){
                        disk[z] = pom;
                    }
                    for(int z = i; h > 0; z++, h--){
                        disk[z] = -1;
                    }
                    break;
                }
                ile = 0;
                fl = false;
            }
        }
        ile = 0;
        il = 0;
    }
    for(int i = 0; i < disk.size(); i++){
        if(disk[i] == -1){
            continue;
        }
        wyn += i*(disk[i]);
    }
    cout << wyn;
}