#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

void solve() {
    int n; cin >> n;
    int x=0,y=0,z=0;
    for(int i=0;i<n;++i){
        int dx,dy,dz;
        cin>>dx>>dy>>dz;
        x+=dx;
        y+=dy;
        z+=dz;
    }
    if (x==0 && y==0 && z==0){
        cout<<"YES\n";
    } else {
        cout<<"NO\n";
    }
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


