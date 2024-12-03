//for part 2 input must be in one line
#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> dos, donts;

bool czy(int p){
    int x1,x2;
    if(p < donts[0]){
        return false;
    }
    for(int i = 0; i < dos.size()-1; i++){
        if(dos[i] < p && dos[i+1] > p){
            x1 = dos[i];
        }
    }
    if(dos[dos.size()-1] < p){
        x1 = dos[dos.size()-1];
    }
    for(int i = 0; i < donts.size()-1; i++){
        if(donts[i] < p && donts[i+1] > p){
            x2 = donts[i];
        }
    }
    if(donts[donts.size()-1] < p){
        x2 = donts[donts.size()-1];
    }
    return x1 < x2;
}

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll wyn = 0;
    regex pattern("mul\\([0-9]+,[0-9]+\\)"), pat2("do\\(\\)"), pat3("don't\\(\\)");
    for(int i = 0; i < 1; i++){
        dos.clear();donts.clear();
        string x;
        getline(cin,x);
        dos.push_back(-1);
        for(sregex_iterator it = sregex_iterator(x.begin(),x.end(),pat2); it != sregex_iterator();it++){
            smatch m;
            m = *it;
            dos.push_back(m.position(0));
        }
        for(sregex_iterator it = sregex_iterator(x.begin(),x.end(),pat3); it != sregex_iterator(); it++){
            smatch m;
            m = *it;
            donts.push_back(m.position(0));
        }
        for(sregex_iterator it = sregex_iterator(x.begin(),x.end(),pattern);it != sregex_iterator(); it++){
            smatch m;
            m = *it;
            if(czy(m.position(0))){
                continue;
            }
            string pom = m.str(0),pom2 = "";
            int x1 = 0,x2 = 0;
            bool c = false;
            for(int j = 4; j < pom.size();j++){
                if(pom[j] == ','){
                    x1 = stoi(pom2);
                    pom2 = "";
                    c = true;
                    j++;
                }
                if(c && pom[j] == ')'){
                    x2 = stoi(pom2);
                    pom2 = "";
                    break;
                }
                pom2.push_back(pom[j]);
            }
            wyn += x1*x2;
        }
    }
    cout << wyn;
}