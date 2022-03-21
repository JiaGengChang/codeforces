#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

void solve(int tc) {
    int n; cin >> n;
    vector<double> a(n);
    for (double& u:a) cin >> u;
    double m=*max_element(a.begin(),a.end());
    double s=accumulate(a.begin(),a.end(),0.0);
    debug(m,s);
    if(m==0) cout << "0\n";
    else {
        if(2*m <= s){
            cout << "1\n";
        } else {
            cout << (long long) (2*m-s) << "\n";
        }
    }
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


