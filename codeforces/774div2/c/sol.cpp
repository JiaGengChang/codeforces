#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(x...)
#endif

using namespace std;
long long n;
vector<long long> facts;

void precompute(){
    facts.assign(15,1);
    for(int i=2;i<15;++i){
        facts[i] = facts[i-1]*i;
    }
}

void solve() {
    int ans = __builtin_popcountll(n);//max
    for (long long i=0;i<(1<<15);++i) {
        //number of distinct factorials
        long long s = 0;
        for (int j=0;j<15;++j){
            if (i & (1<<j)){
                s+=facts[j];
            }
        }
        if(s>n) continue;
        ans = min(ans,__builtin_popcountll(i)+__builtin_popcountll(n-s));
    }
    cout<<ans<<'\n';
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
    precompute();
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cin >> n;
        solve();
    }
#ifndef ONLINE_JUDGE
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(stop-start);
    cerr << duration.count() << "ms\n";
#endif
    return 0;
}


