#include <bits/stdc++.h>

using namespace std;

// segment tree over suffix sum
struct segtree {
	int size;
	vector<int> values;
	int NEUTRAL_ITEM = 0;

	int merge(int lv, int rv){
		return lv + rv;
	}
	
	//kth one from the right
	int find_right (int k, int x, int lx, int rx){
		if (rx - lx == 1) {
			return lx;
		}
		int m = (lx + rx)/2;
		int sr = values[2*x+2];
		if (k < sr) {
			return find_right(k, 2*x+2, m, rx);
		} else {
			return find_right(k-sr, 2*x+1, lx, m);
		}
	}	

	int find_right (int k){
		return find_right(k, 0, 0, size);
	} 

	void set(int i, int v, int x, int lx, int rx){
		if (rx - lx==1){
			values[x] = v;
			return;
		}
		int m = (lx+rx)/2;
		if (i < m) {
			set(i, v, 2*x+1, lx, m);
		} else {
			set(i, v, 2*x+2, m, rx);
		}
		values[x] = merge(values[2*x+1],values[2*x+2]);
	}

	void set(int i, int v){
		set(i, v, 0, 0, size);
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
		values.assign(2*size-1, NEUTRAL_ITEM);
		build(a);
	}

};

void solve() {
	int n;
	cin >> n;
	vector<int> a(n,1), p(n), ans(n);
   	segtree st(n,a);

	for (auto &u:p) {
		cin >> u; 
	}

	for (int i=n-1; i>=0; --i){
		ans[i] = st.find_right(p[i]);
		st.set(ans[i], 0);
	}
	for (auto u:ans) cout << u+1 << ' '; 
	cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	solve();
	return 0;
}

