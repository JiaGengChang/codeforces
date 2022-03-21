#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

struct segtree {
    int sz;
    vector<int> vals;
    void segtree(int n){
        sz=1;
        while(sz<n) sz*=2;
        vals.assign(sz,0);
    }
    void build(vector<int>& a) {build(a, 0, 0, sz);}
    void build(vector<int>& a, int x, int l, int r){
        if (r-l==1){
            if (l < a.size()) vals[x] = a[l];
            return;
        }
        int m = (l+r)/2;
        build(a, 2*x+1, l, m);
        build(a, 2*x+2, m, r);
        vals[x] = vals[2*x+1] + vals[2*x+2];
    }
    int sum(int l, int r) {return sum(l, r, 0, 0, sz);}
    int sum(int l, int r, int x, int lx, int rx){
        if (lx >= l && rx <= r) return vals[x];
        if (rx <= l || lx >= r) return 0;
        int m = (lx+rx)/2;
        return sum(l,r,2*x+1,lx,m) + sum(l,r,2*x+2,m,rx);
    }
    int get(int i, int l, int r) {get(i, l, r, 0, 0, sz);}
    int get(int i, int l, int r, int x, int lx, int rx){
        if (lx >= l && rx <= r) return vals[x];
        if (rx <= l || lx >= r) return 0;
        int m = (lx+rx)/2;
        return get(i,l,r,2*x+1,lx,m) + get(i,l,r,2*x+2,m,rx);
    }
};

void solve(int tc) {
    int n, q; cin >> n >> q;
    vector<int> a(n);
    for (int& u:a) cin >> u;
    segtree st(n); st.build(a);

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
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
}
