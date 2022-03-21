#include <bits/stdc++.h>

using namespace std;


void solve() {
   	string s, t, sc;
	cin >> s >> t;
	sc = s; //backup
	sort(s.begin(), s.end());
	if (t=="abc"){
		//if s has a, b, and c
		size_t hasA = s.find('a');
		size_t hasB = s.find('b');
		size_t hasC = s.find('c');
		bool bad =  hasA != string::npos && hasB != string::npos && hasC != string::npos;
		if (bad) {
			//put all c in front of all b's
			size_t endC = hasC;
			while (s[endC]=='c') ++endC;
			int lenB = hasC - hasB;
			int lenC = endC - hasC;
			for (int i=hasB; i<endC; ++i){
				if (i - hasB < lenC) {
					s[i] = 'c';
				} else {
					s[i] = 'b';
				}
			}
		}
	}
	cout << s << '\n';
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
