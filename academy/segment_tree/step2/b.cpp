#include <bits/stdc++.h>

using namespace std;

struct item {
	int c; //count of 1s
};

struct segtree {
	int size;
	vector<item> values;

	item NEUTRAL_ITEM = {0};
	
	item single (int v) {
		return {v};
	}
	
	item merge (item a, item b){
		return single(a.c + b.c);
	}

	segtree(int n){
		size = 1;
		while (size < n) size *= 2;
		values.assign(2*size-1, NEUTRAL_ITEM);
	}

	void build(vector<int>& a, int x, int lx, int rx){
		if (rx-lx==1) {
			if (lx < (int)a.size()){
				values[x] = single(a[lx]); 
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
			values[x].c = 1 - values[x].c;
			return;
		}
		int m = (lx + rx)/2;
		if (i < m)
			set(i, 2*x + 1, lx, m);
		else
			set(i, 2*x + 2, m, rx);
		values[x] = merge(values[2*x+1], values[2*x+2]);
	}

	void set (int i){
		set(i, 0, 0, size);
	}

	int get (int k, int x, int lx, int rx){
		if (rx - lx == 1) {
			return lx;
		}
		int m = (lx + rx)/2;
		int sl = values[2*x+1].c;
		if (k < sl) {
			return get(k, 2*x+1, lx, m);
		} else {
			return get(k-sl, 2*x+2, m, rx);
		}
	}	

	int get (int k){
		return get(k, 0, 0, size);
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
	// for (auto& u:st.values) cout << u.c << ' '; cout << '\n';
	while (m--){
		int op, x; cin >> op >> x;
		if (op==1) {
			st.set(x);
		} else {
			int res = st.get(x);
			cout << res << '\n';
		}
	}
}

