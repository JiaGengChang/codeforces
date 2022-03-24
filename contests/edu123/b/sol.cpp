#include <bits/stdc++.h>
#include "/home/Jia_Geng/cp/debug.h"

using namespace std;

void solve(int tc) {
	int n; cin >> n;
	if (n==3) {
		cout << "1 3 2\n2 3 1\n3 1 2\n";
		return;
	}

	vector<int> a(n);
	for (int i=0; i<n; ++i) {
		a[i] = i+1;
	}
	cerr << "original: " << endl;
	debug(a);
	swap(a[2],a[3]);
	cerr << "before: " << endl;
	debug(a);
	for (int i=0; i<n; ++i) {
		for (auto u:a) cout << u << ' '; cout << '\n';
		//rotate
		rotate(a.begin(), a.begin()+1, a.end());
		cerr << "after: " << endl;
		debug(a);
	}
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt","w", stderr);
	#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); 
	cout.tie(0);
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cerr << "Case #" << tc << '\n';
        solve(tc);
    }
}


