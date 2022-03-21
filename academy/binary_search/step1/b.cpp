#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto& u:a) cin >> u;
	sort(a.begin(), a.end());
	int k; cin >> k;
	while (k--){
		int x, y; cin >> x >> y;
		int l = 0;
		int r = n-1;
		int ix, iy;
		while (l <= r){
			int m = (l+r)/2;
			if (y < a[m]) {
				r = m-1;
			} else {
				l = m+1;
			}
		}
		iy = r+1;
		//cout << "position of " << y << " is " << iy << '\n';
		l = 0;
		r = n-1;
		while (l <= r){
			int m = (l+r)/2;
			if (x <= a[m]){
				r = m-1;
			} else {
				l = m+1;
			}
		}
		ix = l;
		//cout << "position of " << x << " is " << ix << '\n';
		cout << iy - ix << '\n';
	}	
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}

