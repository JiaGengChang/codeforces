#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;
#define int long long

// segment tree of number of nested segments
struct segtree {
	int sz;
	vector<int> values;

	segtree(int n, vector<int>& a){
		sz = 1;
		while (sz < n) sz *= 2;
		values.assign(2*sz-1, 0);
	}

	int sum(int l, int r) {
		return sum(l, r, 0, 0, sz);
	}
	int sum(int l, int r, int x, int lx, int rx){
		if (lx >= r || rx <= l) return 0;
		if (lx >= l && rx <= r)	return values[x];
		int m = (lx + rx)/2;
		return sum(l, r, 2*x+1, lx, m) + sum(l, r, 2*x+2, m, rx);
	}

	void add(int i, int v){
		add(i, v, 0, 0, sz);
	}
	void add(int i, int v, int x, int lx, int rx){
		if (rx - lx==1){
			values[x] += v;
			return;
		}
		int m = (lx+rx)/2;
		if (i < m) {
			add(i, v, 2*x+1, lx, m);
		} else {
			add(i, v, 2*x+2, m, rx);
		}
		values[x] = values[2*x+1]+values[2*x+2];
	}
};

void solve() {
	int n,m; cin >> n >> m;
	vector<int> a(n,0);
	segtree st(n+1, a);
	while (m--){
		int op;
		cin >> op;
    debug(op);
		if (op==1) {
			int l,r,v;
			cin >> l >> r >> v;
      debug(l,r,v);
			st.add(l, v);
			st.add(r, -v);
      debug(st.values);
    }
    if (op==2) {
			int i;
			cin >> i;
      debug(i);
      debug(st.values);
			cout << st.sum(0, i+1) << endl;
		}
	}
}

signed main() {
  #ifndef ONLINE_JUDGE
  freopen("random_input.txt", "r",stdin);
  freopen("output.txt", "w",stdout);
  freopen("error.txt","w",stderr);
  #endif
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
	solve();
	return 0;
}

