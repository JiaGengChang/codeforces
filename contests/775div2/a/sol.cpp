#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

void solve(int tc) {
    int n; cin >> n;
    vector<int> a(n);
    int ans=0;
    for (int& u:a) {
        cin>>u;
    }
    //ans=distance between first and last 0
    int i1=0,i2=n-1;
    while(i1<n && a[i1]==1) ++i1;
    if(i1==n){
        cout<<"0\n";
        return;
    }
    while(i2>0 && a[i2]==1) --i2;
    debug(i1,i2);
    cout << i2-i1+2 << '\n';
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
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cerr << "Case #" << tc << '\n';
        solve(tc);
    }
#ifndef ONLINE_JUDGE
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(stop-start);
    cerr << duration.count() << "ms\n";
#endif
    return 0;
}


