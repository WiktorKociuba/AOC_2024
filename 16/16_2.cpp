#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXI = 141;
bool odw[MAXI][MAXI];
ll odl[MAXI][MAXI];
int dx[] = {0,0,-1,1}, dy[] = {1,-1,0,0};

vector<pair<ll,ll>> odt(pair<ll,ll> popr[MAXI][MAXI]){
    ll p1 = MAXI-2, p2 = 1;
    vector<pair<ll,ll>> path;
    for(pair<ll,ll> i = {p2,p1}; i != make_pair(p1,p2); i = popr[i.first][i.second]){
        path.push_back(i);
    }
    reverse(path.begin(),path.end());
    return path;
}

pair<vector<pair<ll,ll>>,ll> dijkstra(vector<char> graf[MAXI]){
    pair<ll,ll> popr[MAXI][MAXI];
    for(int i = 0; i < MAXI; i++){
        for(int j = 0; j < MAXI; j++){
            if(graf[i][j] == '#'){
                odw[i][j] = true;
            }
            else{
                odw[i][j] = false;
            }
            odl[i][j] = LLONG_MAX;
        }
    }
    odl[MAXI-2][1] = 0;
    priority_queue<pair<ll,pair<ll,pair<ll,ll>>>> p;
    p.push({0,{0,{MAXI-2,1}}});
    while(!p.empty()){
        pair<ll,ll> poz = p.top().second.second;
        ll ki = p.top().second.first;
        p.pop();
        if(odw[poz.first][poz.second]){
            continue;
        }
        odw[poz.first][poz.second] = true;
        for(int i = 0; i < 4; i++){
            if(ki == i){
                if(graf[poz.first+dx[i]][poz.second+dy[i]] == '#'){
                    continue;
                }
                if(odl[poz.first+dx[ki]][poz.second+dy[ki]] > odl[poz.first][poz.second] + 1){
                    popr[poz.first+dx[ki]][poz.second+dy[ki]] = poz;
                    odl[poz.first+dx[ki]][poz.second+dy[ki]] = odl[poz.first][poz.second] + 1;
                    p.push({-odl[poz.first+dx[ki]][poz.second+dy[ki]],{ki,{poz.first+dx[ki],poz.second+dy[ki]}}});
                }
            }
            else{
                if(graf[poz.first+dx[i]][poz.second+dy[i]] == '#'){
                    continue;
                }
                if(odl[poz.first+dx[i]][poz.second+dy[i]] > odl[poz.first][poz.second] + 1001){
                    popr[poz.first+dx[i]][poz.second+dy[i]] = poz;
                    odl[poz.first+dx[i]][poz.second+dy[i]] = odl[poz.first][poz.second] + 1001;
                    p.push({-odl[poz.first+dx[i]][poz.second+dy[i]],{i,{poz.first+dx[i],poz.second+dy[i]}}});
                }
            }
        }
    }
    if(odl[1][MAXI-2] == LLONG_MAX){
        return {{},LLONG_MAX};
    }
    return {odt(popr),odl[1][MAXI-2]};
}

ll yens(vector<char> graf[MAXI]){
    vector<vector<pair<ll,ll>>> kshort;
    vector<pair<ll,ll>> gdzie[100000];
    pair<vector<pair<ll,ll>>,ll> pier = dijkstra(graf);
    kshort.push_back(pier.first);
    for(int k = 1; k < 100; k++){
        cout << k << endl;
        if(k > kshort.size()){
            break;
        }
        vector<pair<ll,ll>> lastpath = kshort[k-1];
        for(int i = 1; i < lastpath.size(); i++){
            for(int j = 0; j < gdzie[k-1].size(); j++){
                graf[gdzie[k-1][j].first][gdzie[k-1][j].second] = '#';
            }
            graf[lastpath[i].first][lastpath[i].second] = '#';
            pair<vector<pair<ll,ll>>,ll> kan = dijkstra(graf);
            graf[lastpath[i].first][lastpath[i].second] = '.';
            for(int j = 0; j < gdzie[k-1].size(); j++){
                graf[gdzie[k-1][j].first][gdzie[k-1][j].second] = '.';
            }
            if(kan.second == pier.second){
                kshort.push_back(kan.first);
                gdzie[kshort.size()-1] = gdzie[k-1];
                gdzie[kshort.size()-1].push_back(lastpath[i]);
            }
        }
    }
    ll wyn = 0;
    for(int i = 0; i < kshort.size(); i++){
        for(int j = 0; j < kshort[i].size(); j++){
            graf[kshort[i][j].first][kshort[i][j].second] = 'O';
        }
    }
    for(int i = 0; i < MAXI; i++){
        for(int j = 0; j < MAXI; j++){
            if(graf[i][j] == 'O'){
                wyn++;
            }
        }
    }
    wyn++;
    return wyn;
}

int main(){
    vector<char> graf[MAXI];
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);
    for(int i = 0; i < MAXI; i++){
        for(int j = 0; j < MAXI; j++){
            char pom;
            cin >> pom;
            graf[i].push_back(pom);
        }
    }
    cout << yens(graf);
}