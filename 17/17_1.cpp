#include <bits/stdc++.h>
using namespace std;
#define ll long long

int A = 0, B = 0, C = 0;

int combo(int li){
    if(li <= 3){
        return li;
    }
    else if(li == 4){
        return A;
    }
    else if(li == 5){
        return B;
    }
    else if(li == 6){
        return C;
    }
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    cin >> A >> B >> C;
    vector<int> pro;
    for(int i = 0; i < 6; i++){
        int pom;
        cin >> pom;
        pro.push_back(pom);
    }
    int i = 0;
    while(i<pro.size()){
        if(pro[i] == 3){
            if(A == 0){
                i+=2;
                continue;
            }
            i = pro[i+1];
        }
        else if(pro[i] == 0){
            A = A/pow(2,combo(pro[i+1]));
            i+=2;
        }
        else if(pro[i] == 1){
            int p = pro[i+1];
            int pr = B^p;
            B = pr;
            i+=2;
        }
        else if(pro[i] == 2){
            B = combo(pro[i+1])%8;
            i+=2;
        }
        else if(pro[i] == 4){
            int p = B^C;
            B = p;
            i+=2;
        }
        else if(pro[i] == 5){
            cout << combo(pro[i+1]) % 8 << ',';
            i+=2;
        }
        else if(pro[i] == 6){
            B = A/(pow(2,combo(pro[i+1])));
            i+=2;
        }
        else if(pro[i] == 7){
            C = A/(pow(2,combo(pro[i+1])));
            i+=2;
        }
    }
}