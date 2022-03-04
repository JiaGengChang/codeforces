#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for (auto& u:a) {cin >> u; --u;}
	sort(a.begin(), a.end());

	vector<bool> in(n,false);
	vector<bool> used(n,false);
	int ans=0;
	for (int i=0; i<n; ++i){
		if (a[i]<n && !in[a[i]]){
			in[a[i]] = true;
			used[i] = true;
		} else {
			//find smallest number not in
			int l=0, r=n-1;
			while (r >= l){
				int m = (l+r)/2;
				if (in[m]){
					l = m+1;
				} else {
					r = m-1;
				}
			}
			//cout << "in: ";
			//for (auto u:in) cout << u << ' ';cout << '\n';
			//cout << "l: " << l << ", r: " << r << '\n';
			//cout << "a[i]: " << a[i] << '\n';
			if ((a[i]+1)/2 >= (l+1)){
				++ans;
				in[l]=true;
				used[i]=true;
			} else {
				cout << -1 << '\n';
				return;
			}
		}

	}
	cout << ans << '\n';
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

