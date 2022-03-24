#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(x...)
#endif

using namespace std;
#define ll long long

bool ckmin(ll& a, ll b){ return b < a ? a = b, true : false; }

void solve() {
    int n; cin >> n;
    vector<ll> a(n),b(n);
    for (ll& u:a) cin >> u;
    for (ll& u:b) cin >> u;

    ll ans=abs(a[0]-b[0])+abs(a[n-1]-b[n-1]);

    ll cost[4];
    for(int i=0;i<4;++i)cost[i]=LLONG_MAX;
    for(int i=0;i<n;++i){
        ckmin(cost[0],abs(a[0]-b[i]));
        ckmin(cost[1],abs(b[0]-a[i]));
        ckmin(cost[2],abs(a[n-1]-b[i]));
        ckmin(cost[3],abs(b[n-1]-a[i]));
    }
    //0...2
    //1...3
    ckmin(ans, abs(a[0]-b[0]) + cost[2] + cost[3]);
    ckmin(ans, abs(a[0]-b[n-1]) + cost[2] + cost[1]);
    ckmin(ans, abs(a[n-1]-b[0]) + cost[0] + cost[3]);
    ckmin(ans, abs(a[n-1]-b[n-1]) + cost[0] + cost[1]);
    
    ckmin(ans, cost[0]+cost[1]+cost[2]+cost[3]);

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


