#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

int n,c;
 
void solve() {
    cin >> n >> c;
    vector<int> a(n),cnt(c+1,0),pref(c+1,0);
    for(auto &x:a){
        cin>>x;
        ++cnt[x];
    }
    for(int i=1;i<=c;++i) 
        pref[i]=pref[i-1]+cnt[i];
    if (!cnt[1]) {
        cout<<"No\n";
        return;
    }
    debug(pref);
    for(int y=1;y<=c;++y) if (cnt[y]) {
        for(int r=1; r<=c/y;++r) if (!cnt[r]) {
            debug(y,r);
            if (cnt[r*y] || pref[min(c,r*y+y-1)]>pref[r*y]){
                cout<<"No\n";
                return;
            }
        }
    }
    cout<<"Yes\n";
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
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cerr << "Case #" << tc << '\n';
        solve();
    }
#ifndef ONLINE_JUDGE
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(stop-start);
    cerr << duration.count() << "ms\n";
#endif
    return 0;
}


