#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
	int t;
	cin >> t;
	while (t--){
		int n,m,r,c;
		cin >> n >> m >> r >> c;
		r-=1;
		c-=1;
		char C[n][m];
		int nW=0,nB=0;
		for (int i=0; i<n; ++i){
			for (int j=0; j<m; ++j){
				cin >> C[i][j];
				if (C[i][j]=='W') ++nW;
				else ++nB;
			}
		}
		int ans;
		if (C[r][c]=='B'){
			ans=0;
		} else {
			if (nB==0) {
				ans=-1;
			} else {
				ans=2;
				for (int i=0; i<n; ++i){
					if (C[i][c]=='B'){
						ans=1;
						break;
					}
				}
				for (int j=0; j<m; ++j){
					if (C[r][j]=='B'){
						ans=1;
						break;
					}
				}
			}
		}
		cout << ans << endl;
	}//while
	
	return 0;
}
