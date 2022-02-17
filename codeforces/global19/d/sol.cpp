#include <bits/stdc++.h>


using namespace std;


int main(){
	int tt; cin >> tt;
	while (tt--){
		int n; cin >>n;
		vector<int> a(n), b(n);
		for (auto& aa : a) cin >> aa;
		for (auto& bb : b) cin >> bb;

		//make array a minimum
		int sumMin=0, sumMax=0,sumSq = 0;
		for (int i=0; i<n; ++i){
			if (a[i]>b[i]){
				swap(a[i],b[i]);
			}
			sumMin += a[i];
			sumMax += b[i];
			sumSq += a[i]*a[i] + b[i]*b[i];
		}

		bitset<100*100+10> dp;
		dp[0] = 1; //default, no swapping of elements
		for (int i=0; i<n; ++i){
			//dp[i,w] = dp[i-1, w-ai] or dp[i-1,w-bi]
			dp |= dp << (b[i] - a[i]);
		} 

		int ans = sumMin*sumMin + sumMax*sumMax;
		for (int i=0; i<= sumMax - sumMin; ++i)
			if (dp[i])
				ans = min(ans, (sumMin + i)*(sumMin+i) + (sumMax - i)*(sumMax - i));

		cout << sumSq*(n-2) + ans << '\n'; 

	}
	return 0;
}

