#include <bits/stdc++.h>

using namespace std;

int main(){
	int tt; cin >> tt;
	while (tt--){
		int n; cin>>n;
		int k = (int)log2(n);
		int pk = 1 << k;
		for (int i= pk-1; i >= 0; --i){
			cout << i << " ";
		}
		for (int i= pk; i < n; ++i){
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}
