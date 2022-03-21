#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto& u:a) cin >> u;


	if (a[n-2] > a[n-1]) {
		cout << -1 << '\n';
		return;
	}

	if (a[n-1] < 0) {
		if (is_sorted(a.begin(),a.end())){
			cout << 0 << '\n';
		} else {
			cout << -1 << '\n';
		}
		return;
	}
	
	cout << n-2 << '\n';
	for (int i=0; i<n-2; ++i){
		cout << i+1 << ' ' << n-1 << ' ' << n << '\n';
	}

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t << ": \n";
        solve();
    }
}

