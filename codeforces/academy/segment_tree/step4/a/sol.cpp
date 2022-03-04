#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

struct segtree{
  int sz;
  vector<int> vals;

  segtree(int n){
    sz=1;
    while (sz < n) sz*=2;
    vals.assign(2*sz-1, 0);
  }

  void build(vector<int>& a, int x, int l, int r){
    if (r-l==1){
      if (l < a.size()){
        vals[x] = l%2==0 ? a[l] : -1*a[l];
      }
      return;
    }
    int m = (l+r)/2;
    build(a, 2*x+1, l, m);
    build(a, 2*x+2, m, r);
    vals[x] = vals[2*x+1] + vals[2*x+2];
  }
  void build(vector<int>& a){
    build(a, 0, 0, sz);
  }
  void set(int i, int j){
    set(i, j, 0, 0, sz);
    debug(vals);
  }
  void set(int i, int j, int x, int l, int r){
    if (r-l==1){
      vals[x] = i%2==0 ? j : -1*j;
      return;
    }
    int m = (l+r)/2;
    if (i < m){
      set(i, j, 2*x+1, l, m);
    } else {
      set(i, j, 2*x+2, m, r);
    }
    vals[x] = vals[2*x+1] + vals[2*x+2];
  }
  int get(int l, int r) {
    int ans = get(l, r, 0, 0, sz);
    return l%2==0 ? ans : -1*ans;
  }
  int get(int l, int r, int x, int lx, int rx){
    if (lx >= r || rx <= l) return 0;
    if (lx >= l && rx <= r) return vals[x];
    if (rx - lx == 1){
      return vals[x];
    }
    int m = (lx+rx)/2;
    int s1, s2;
    s1 = get(l, r, 2*x+1, lx, m);
    s2 = get(l, r, 2*x+2, m, rx);
    return s1+s2;
  }
};

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (int& u:a) cin >> u;
  segtree st(n); 
  st.build(a);
  debug(st.vals);

  int q; cin >> q;
  while(q--){
    int t; cin >> t;
    debug(t);
    if (t==0){
      int i,j; cin >> i >> j;
      --i;
      debug(t,i,j);
      st.set(i, j);
    } else {
      int l, r; cin >> l >> r;
      --l; 
      debug(t, l, r);
      int ans = st.get(l, r);
      cout << ans << '\n';
    }
  }

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
  solve();
}


