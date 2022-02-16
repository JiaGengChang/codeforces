#include <bits/stdc++.h>


using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	for (auto& u : a) cin >> u;

	//cases with no solution
	bool f = true;
	for (int i=1; i<n-1; ++i) f = f && a[i]==1;
	if (f || (n==3 && a[1]%2==1)) {
		cout << -1 << "\n"; return;
	}

	//cases with solution
	long long ans=0;
	for (int i=1; i<n-1; ++i){
		if (a[i]%2==1) ++ans;
		ans += a[i]/2;
	}
	cout << ans << "\n";
}

int main(){
		
	int tt; cin >> tt;
	while (tt--){
		solve();
	}
	return 0;
}

