#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    ll wyn = 0;
    regex pattern("mul\\([0-9]+,[0-9]+\\)");
    vector<int> dos, donts;
    for(int i = 0; i < 6; i++){
        dos.clear();donts.clear();
        string x;
        getline(cin,x);
        for(sregex_iterator it = sregex_iterator(x.begin(),x.end(),pattern);it != sregex_iterator(); it++){
            smatch m;
            m = *it;
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