#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(x...)
#endif

using namespace std;
int n,m,c;

int md(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

void solve() {
    cin>>n>>m;
    vector<vector<pair<int,int>>> g;
    vector<int> ods;//colours
    for (int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>c;
            auto f = find(ods.begin(),ods.end(),c);
            if(f==ods.end()){
                g.push_back({{i,j}});
                ods.push_back(c);
            } else {
                int k = distance(ods.begin(), f);
                g[k].push_back({i,j});
            }
        }
    }
    debug(ods);
    debug(g);
    long long ans=0;
    for (int k=0; k<ods.size(); ++k){
        for(int i=0; i<g[k].size(); ++i) {
            for(int j=i+1; j<g[k].size(); ++j){
                pair<int,int> &p = g[k][i];
                pair<int,int> &q = g[k][j];
                ans += md(p.first,p.second,q.first,q.second);
            }
        }
    }
    cout<<ans<<'\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
    auto start=chrono::high_resolution_clock::now();
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    solve();
#ifndef ONLINE_JUDGE
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(stop-start);
    cerr << duration.count() << "ms\n";
#endif
    return 0;
}


