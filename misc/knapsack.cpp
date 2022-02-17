#include <bits/stdc++.h>
using namespace std;

void tooSlow(){
	int n, W; cin >> n >>W;
	bool can[1000000+10];
	can[0] = true;
	for (int i=0; i<n; ++i){
		int x;
		cin >> x;
		for (int i = W; i >= x; --i){
			can[i] = can[i-x];
		}
	}
	puts(can[W] ? "YES" : "NO");
}

void faster(){
	int n, W; cin >> n >>W;

	bitset<1000*1000 + 10> dp;
	dp[0] = 1;

	for (int i=0; i<n; ++i){
		int x; cin >> x;
		dp |= dp << x;
	}
	
	puts(dp[W] ? "YES" : "NO");
}

int main(){
	faster();
	cout <<"done\n";
	return 0;
}

