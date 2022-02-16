#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<unsigned int> a1, a2;
	for (int i=0; i<n; ++i){
		int x; cin >> x;
		if (x%2==0){
			a1.push_back(x);
		} else {
			a2.push_back(x);
		}
	}
	if (is_sorted(a1.begin(), a1.end()) && is_sorted(a2.begin(), a2.end())){
		cout << "yes\n";
	} else {
		cout << "no\n";
	}

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}

