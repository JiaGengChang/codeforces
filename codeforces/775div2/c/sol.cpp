#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(x...)
#endif

using namespace std;
int n,m;
int cs[100001];

double md(vector<int> &v){
    int k=v.size();
    if(k==1) return 0;
    double ans=0.0;
    for(int i=0;i<k;++i){
        double tmp = (2*i-k+1);
        tmp *= (double)v[i];
        ans += tmp;
    }
    return ans;
}

void solve() {
    cin>>n>>m;
    vector<vector<pair<int,int>>> g;
    vector<int> ods;//colours
    for(int i=1;i<=100000;++i) cs[i]=-1;
    int t=0;//time at which we encountered c
    for (int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            int c; 
            cin>>c;
            if(cs[c]==-1){
                g.push_back({{i,j}});
                ods.push_back(c);
                cs[c] = t;
                ++t;
            } else {
                g[cs[c]].push_back({i,j});
            }
        }
    }
    double ans=0.0;
    for (int k=0; k<ods.size(); ++k){
        vector<int> r,c;
        for(auto u:g[k]){
            r.push_back(u.first);
            c.push_back(u.second);
        }
        sort(r.begin(),r.end());
        sort(c.begin(),c.end());
        ans += md(r);
        ans += md(c);
    }
    cout<<setprecision(20);
    cout<<ans<<'\n';
}

signed main() {
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


