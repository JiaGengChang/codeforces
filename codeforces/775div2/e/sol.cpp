#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(x...)
#endif


using namespace std;
int n,m;
const int mod = 998244353;
const int mxs = 10;//200000
int fact(int x){
    int ans=1;
    for (int i=2;i<=x;++i) ans *= i;
    return ans;
}
int perms(vector<int> &v){
    int s = accumulate(v.begin(),v.end(),0);
    int ans = fact(s);
    for (int i=0; i<v.size(); ++i){
        ans /= max(1,fact(v[i]));
    }
    return ans;
}
int ways(vector<int> &cnt, vector<int> &t){
    if(!t.size()) return 1;
    int ans=0;
    for(int i=0; i<=t[0]; ++i) if (cnt[i]) {
        vector<int> rt(t.begin()+1,t.end());
        vector<int> rcnt(cnt);
        --rcnt[i];
        if (i == t[0]){
            ans += ways(rcnt, rt);
        } else {
            ans += perms(rcnt);
        }
    }
    return ans;
}
void solve() {
    cin >> n >> m;
    vector<int> cnt(mxs,0),t(m);
    for (int i=0;i<n; ++i){
        int x;
        cin>>x;
        ++cnt[x];
    }
    for (int& u:t) cin >> u;
    cout << ways(cnt, t) << '\n';
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


