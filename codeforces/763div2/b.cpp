#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
	if (n%2==0){
		cout << n-3 << ' ' << 2 << ' ' << 1 << '\n';
		return;
	} 
	if (n%4==1){
		cout << n/2 -1 << ' ' << n/2 + 1 << ' ' << 1 << '\n';
		return;
	} 
	if (n%4==3){
		cout << n/2 - 2 << ' ' << n/2 + 2 << ' ' << 1 << '\n';
		return; 
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t << ": ";
        solve();
    }
}

