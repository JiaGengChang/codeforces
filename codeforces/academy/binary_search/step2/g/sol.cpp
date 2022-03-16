#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

int k,n;
vector<long long> a;
bool good(long long m){
    //m councils, k seats each
    //total m*k slots
    long long slots = m*k;
    for (int i=0;i<n;++i){
        slots -= min(m,a[i]);//# each group can send off
    }
    //have all slots been filled
    return slots <= 0;
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
    cin >> k >> n;
    a.resize(n);
    for (int i=0;i<n;++i) cin >> a[i];
    long long l=0; //good
    long long r=5e10;//bad
    while(r-l>1){
        long long m=(l+r)/2;
        if(good(m)) l=m; else r=m;
    }
    cout << l << '\n';
#ifndef ONLINE_JUDGE
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(stop-start);
    cerr << duration.count() << "ms\n";
#endif
    return 0;
}


