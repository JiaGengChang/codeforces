#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	int a = 0;
	int b; 
	string ans = "NO";
	for (int i=0; i<n; ++i){
		cin >> b;
		if (b < a){
			ans="YES";
		} 
		a = b;
	}
	cout << ans << "\n";
}

int main() {
    int tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}

