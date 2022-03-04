#include <bits/stdc++.h>

using namespace std;

void solve(int tc) {
	string s; cin >> s;
	unsigned int R, G, B, r, g, b;
	for (int i=0; i<s.length(); ++i){
		if (s[i]=='R'){
			R = i;
			continue;
		}
		if (s[i]=='G'){
			G = i;
			continue;
		}
		if (s[i]=='B'){
			B = i;
			continue;
		}
		if (s[i]=='r'){
			r = i;
			continue;
		}
		if (s[i]=='g'){
			g = i;
			continue;
		}
		if (s[i]=='b'){
			b = i;
			continue;
		}
	}
	if (r < R && g < G && b < B){
		cout << "YES" << '\n';
	} else {
		cout << "NO" << '\n';
	}
	
}

int main() {
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


