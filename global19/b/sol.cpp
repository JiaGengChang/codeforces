#include <bits/stdc++.h>


using namespace std;



int main(){
		
	int tc = 1;
	cin >> tc;
	while (tc--){
		int n; cin >> n;
		vector<int> a(n);
		for (auto& e : a) cin >> e;
	
		int ans =0;
		//pick start
		for (int i=0; i<n; ++i){
			for (int j=i+1; j<=n; ++j){
				ans += j-i;
				for (int k=i; k<j; ++k){
					if (a[k]==0){
						++ans;
					}
				}
			}
		}

		cout << ans << "\n";
	}
	

	return 0;
}

