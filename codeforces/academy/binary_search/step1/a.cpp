#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (auto& u:a) cin >> u;
	while (k--){
		int x; cin >> x;
		int l = 0;
		int r = n-1;
		bool found = false;
		while (l <= r){
			int m = (l+r)/2;
			if (x==a[m]){
				found = true;
				break;
			}
			if (x < a[m]) {
				r = m-1;
			} else {
				l = m+1;
			}
		}
		if (found){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
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

