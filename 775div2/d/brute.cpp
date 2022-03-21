#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

int n,c;
 
void solve() {
    cin >> n;
    cin >> c;
    vector<int> a(n);
    vector<bool> p(c+1,false);
    for (int i=0;i<n;++i){
        cin >> a[i];
        p[a[i]] = true;
    }
    sort(a.begin(),a.end());
    for (int x=c;x>0;--x) if (p[x]) {
        int i=0;
        do {
            if ((p[a[i]] && p[x/a[i]])){

            } else {
                cout<<"No\n";
                return;
            }
            ++i;
        } while (x/a[i]>1);
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


