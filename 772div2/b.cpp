#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto& aa:a) cin >> aa;
	int m=0;
	for (int i=1; i<=n-2; ++i){
		if (a[i] > a[i-1] && a[i] > a[i+1]){
			if (i != n-2) {
				a[i+1] = max(a[i],a[i+2]);
			} else {
				a[i+1] = a[i];
			}
			++m;
		}
	}
	cout << m << '\n';
	for (auto aa:a) cout << aa << ' '; cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}

