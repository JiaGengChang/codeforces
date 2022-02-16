#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<pair<int,int>> comp;
	int h; cin >> h;
	int t;
	comp.push_back({h, h});
	for (int i=1; i<n; ++i){
		cin >> t;
		comp.push_back({t,t});
		int j=comp.size()-1;
		while (j>0 && comp[j-1].first > comp[j].second) {
			comp[j-1].first = max(comp[j-1].first, comp[j].first);
			comp[j-1].second = min(comp[j-1].second, comp[j].second);
			comp.pop_back();
			--j;
		}
	}
	int ans = comp.size();
	cout << ans << '\n';
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

