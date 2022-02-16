#include <bits/stdc++.h>

using namespace std;

struct segtree {
	int len;
	vector<int> values;
	
	segtree(int n){
		len = 1;
		while (len < n) len *= 2;
		values.assign(2*len-1, 0);
	}

	void build(vector<int>& a, int x, int lx, int rx){
		if (rx-lx==1){
			values[x] = lx < a.size() ? a[lx] : 0;
			return;
		} 
		int m = (lx + rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		values[x] = min(values[2*x+1], values[2*x+2]);
	}

	void build (vector<int> &a){
		build(a, 0, 0, len);
	}

	void set (int i, int v, int x, int lx, int rx){
		if (rx-lx==1){
			values[x] = v;
			return;
		}
		int m = (lx + rx)/2;
		if (i < m)
			set(i, v, 2*x + 1, lx, m);
		else
			set(i, v, 2*x + 2, m, rx);
		values[x] = min(values[2*x+1], values[2*x+2]);
	}

	void set (int i, int v){
		set(i, v, 0, 0, len);
	}

	int calc (int x, int lx, int rx, int l, int r){
		if (lx >= r || l >= rx) return INT_MAX;
		if (l <= lx && rx <= r)	return values[x];
		int m = (lx + rx)/2;
		return min(calc(2*x+1, lx, m, l, r), calc(2*x+2, m, rx, l, r));
	}	

	int calc (int l, int r){
		return calc (0, 0, len, l, r);
	} 
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m; cin >> n >> m;
	vector<int> a(n);
	for (auto& u:a) cin >> u;
	segtree st(n);
	st.build(a);
	while (m--){
		int op; cin >> op;
		if (op==1){
			int i, v; cin >> i >> v;
			st.set(i, v);
		} else {
			int l, r; cin >> l >> r;
			cout << st.calc(l,r) << '\n';
		}
	}
}

