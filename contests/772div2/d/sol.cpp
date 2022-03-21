#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#endif

using namespace std;

const int mod = (1e9+7);

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt","w", stderr);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n, p; cin >> n >> p;
	vector<int> a(n);
	for (auto &x:a) cin >> x;
	sort(a.begin(),a.end());

	//extract useful numbers
	set<int> useful;
	for (int i=0; i<n; ++i) {
		int x = a[i];
		bool useless=false;
		while (x > 0) {
			if (useful.count(x)) {
				useless = true;
			}
			if (x & 1) {
				x >>= 1;
			} else if (x & 3) {
				//dont understand 
				break;
			} else {
				x >>= 2;
			}
		}
		if (!useless)
			useful.insert(a[i]);
	}
	//cnt[i] is the count of js which 
	//satisfy f(aj)=i
	vector<int> cnt(30,0), dp(p);
	for (int x:useful){
		++cnt[__lg(x)];
	}
	int ans=0;
	//dp[i] is the count of x which are i 
	//bits long
	//dp[i] = dp[i-1] + dp[i-2] + cnt(i)
	for (int i=0; i<p; ++i){
		if (i <30){
			dp[i] = cnt[i];
		}
		if (i >= 1) {
			dp[i] += dp[i-1];
			if (dp[i] >= mod) {
				dp[i] -= mod;
			}
		}
		if (i >= 2) {
			dp[i] += dp[i-2];
			if (dp[i] >= mod) {
				dp[i] -= mod;
			}
		}
		ans += dp[i];
		if (ans >= mod){
			ans -= mod;
		}
	}
	cout << ans << endl;
}

