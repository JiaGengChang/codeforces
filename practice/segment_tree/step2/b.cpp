#include <bits/stdc++.h>

using namespace std;

struct item {
	int c;
};

struct segtree {
	int size;
	vector<item> values;

	item NEUTRAL_ITEM = {0};
	
	item single (int v) {
		return {v};
	}
	
	item merge (item a, item b){
		return {a.c + b.c};
	}

	segtree(int n){
		size = 1;
		while (size < n) size *= 2;
		values.assign(2*size-1, NEUTRAL_ITEM);
	}

	void build(vector<int>& a, int x, int lx, int rx){
		if (rx-lx==1){
			if (lx < a.size()){
				values[x] = single(a[lx]); 
			} else {
				values[x] = NEUTRAL_ITEM;
			}
			return;
		} 
		int m = (lx + rx)/2;
		build(a, 2*x+1, lx, m);
		build(a, 2*x+2, m, rx);
		values[x] = merge(values[2*x+1], values[2*x+2]);
	}

	void build (vector<int> &a){
		build(a, 0, 0, size);
	}

	void set (int i, int x, int lx, int rx){
		if (rx-lx==1){
			values[x] = single(v ^ 1);
			return;
		}
		int m = (lx + rx)/2;
		if (i < m)
			set(i, v, 2*x + 1, lx, m);
		else
			set(i, v, 2*x + 2, m, rx);
		values[x] = merge(values[2*x+1], values[2*x+2]);
	}

	void set (int i){
		set(i, 0, 0, size);
	}

	item calc (int k, int x, int lx, int rx){
		if (rx - lx == 1 && ) {
			return lx;
		}
		if (values[x] < k) {
			return calc(k-values[x], 2*x+2, m, rx, l, r);
		}
		if (values[x] > k) {
			return calc(k, 2*x+1, lx, m, l, r);
		}
	}	

	item calc (int k){
		return calc (0, 0, size);
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
	item res = st.calc(0,n);
	cout << res.seg << '\n';
	while (m--){
		int i, v; cin >> i >> v;
		st.set(i, v);
		res = st.calc(0,n);
		cout << res.seg << '\n';
	}
}

