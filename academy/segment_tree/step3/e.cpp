#include <bits/stdc++.h>

using namespace std;
#define int long long

// segment tree of number of nested segments
struct segtree {
	int size;
	vector<int> values;

	int merge(int lv, int rv){
		return lv + rv;
	}
	
	int sum(int l, int r) {
		return sum(l, r, 0, 0, size);
	}

	int sum(int l, int r, int x, int lx, int rx){
		if (lx >= r || l >= rx) return 0;
		if (l <= lx && rx <= r)	return values[x];
		int m = (lx + rx)/2;
		return sum(l, r, 2*x+1, lx, m) + sum(l, r, 2*x+2, m, rx);
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
		values[x] = merge(values[2*x+1],values[2*x+2]);
	}

	void add(int i, int v){
		add(i, v, 0, 0, size);
	}
	
	void build(vector<int>& a, int x, int lx, int rx){
		if (rx-lx==1){
			if (lx < (int)a.size()){
				values[x] = a[lx];
			}
			return;
		}
		int m = (lx+rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		values[x] = merge(values[2*x+1], values[2*x+2]);
	}

	void build(vector<int>& a){
		build(a, 0, 0, size);
	}

	segtree(int n, vector<int>& a){
		size = 1;
		while (size < n) size *= 2;
		values.assign(2*size-1, 0);
		build(a);
	}

};

void solve() {
	int n,m; cin >> n >> m;
	vector<int> a(n,0);
	segtree st(n, a);
	while (m--){
		int op;
		cin >> op;
		if (op==1){
			int l,r,v;
			cin >> l >> r >> v;
			st.add(l, v);
			st.add(r, -v);
		} else {
			int i;
			cin >> i;
			cout << st.sum(0, i+1) << '\n';
		}
		if (m%100) cout << flush;
	}
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	solve();
	return 0;
}

