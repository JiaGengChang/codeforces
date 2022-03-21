#include <bits/stdc++.h>

using namespace std;

// segment tree of number of nested segments
struct segtree {
	int size;
	vector<int> values;

	int merge(int lv, int rv){
		return lv + rv;
	}
	
	int sum(const int l, const int r) {
		return sum(l, r, 0, 0, size);
	}

	int sum(const int l, const int r, int x, int lx, int rx){
		if (lx >= r || l >= rx) return 0;
		if (l <= lx && rx <= r)	return values[x];
		int m = (lx + rx)/2;
		return sum(l, r, 2*x+1, lx, m) + sum(l, r, 2*x+2, m, rx);
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
		values.assign(2*size-1, 0);
		build(a);
	}

};

void solve() {
	int n; cin >> n;
	vector<int> a(2*n,0), left(n,-1), ans(n,-1); //left boundary position
   	segtree st(2*n,a);

	for (auto &u:a) cin >> u;

	for (int i=0; i<2*n; ++i){
		if (left[a[i]-1]!=-1){
			ans[a[i]-1] = st.sum(left[a[i]-1], i+1); //sum from i to i
			st.set(left[a[i]-1], 1);
		} else {
			left[a[i]-1] = i;
		}
	}
	for (auto u:ans) cout << u << ' ';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	solve();
	return 0;
}

