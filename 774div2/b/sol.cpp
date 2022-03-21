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
    for (int& u:a) cin >> u;
    sort(a.begin(),a.end());
    int i=0; //i = blue index, 
    int j=n-1; //j = red index
    long long sred=a[j],sblue=a[i];
    int cred=1,cblue=1;
    bool flag=false;
    while(i<j) {
        while(i<j && cblue <= cred) {
            ++i;
            sblue += a[i];
            cblue += 1;
        }
        while(i<j && sred <= sblue) {
            --j;
            sred += a[j];
            cred += 1;
        }
        if (cred < cblue && sred > sblue){
            flag=true; 
            break;
        }
    }
    if(flag) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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


