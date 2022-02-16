#include <bits/stdc++.h>

using namespace std;

struct item {
	int val;
};

struct segtree {
	int size;
	vector<item> values;

	item NEUTRAL_ITEM = {INT_MIN};
	
	item single (int v) {
		return {v};
	}
	
	item merge (item a, item b){
		return single(max(a.val, b.val));
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

	void set (int i, int v, int x, int lx, int rx){
		if (rx-lx==1){
			values[x] = single(v);
			return;
		}
		int m = (lx + rx)/2;
		if (i < m)
			set(i, v, 2*x + 1, lx, m);
		else
			set(i, v, 2*x + 2, m, rx);
		values[x] = merge(values[2*x+1], values[2*x+2]);
	}

	void set (int i, int v){
		set(i, v, 0, 0, size);
	}

	int get (int k, int x, int lx, int rx){
		if (k > values[x].val) {
			return -1;
		}
		if (rx - lx == 1) {
			return lx;
		}
		int m = (lx + rx)/2;
		int vl = values[2*x+1].val;
		if (k <= vl) {
			return get(k, 2*x+1, lx, m);
		} else {
			return get(k, 2*x+2, m, rx);
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
	//cout << "debug: \n";
	//for (auto& u:st.values) cout << u.val << ' '; cout << '\n';
	while (m--){
		int op; cin >> op;
		if (op==1) {
			int i,v; cin>> i >> v;
			st.set(i,v);
		} else {
			int x; cin >> x;
			int res = st.get(x);
			cout << res << '\n';
		}
	}
}

