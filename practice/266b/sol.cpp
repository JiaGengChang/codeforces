#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "../../debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

void solve() {
    int n; cin >> n;
    int t; cin >> t;
    vector<int> a(n);
    for(int i=0;i<n;++i){
        char g;
        cin>>g;
        a[i] = g=='B'?1:0;
    }
    while(t--){
        int i=0;
        while(i<n-1){
            if(a[i]==1 & a[i+1]==0){
                swap(a[i],a[i+1]);
                ++i;
            }
            ++i;
        }
    }
    for(int i=0;i<n;++i){
        cout << (a[i]?"B":"G");
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


