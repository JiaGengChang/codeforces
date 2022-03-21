#include <bits/stdc++.h>
#include "/home/Jia_Geng/cp/debug.h"

using namespace std;

vector<int> msum(vector<int>& a, int n) {
    int max_so_far = 0, max_ending_here = 0, start =0, end = 0, s=0;
    for (int i=0; i< n; i++ )
    {
        max_ending_here += a[i];
  
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
        if (max_ending_here < 0) {
            max_ending_here = 0;
            s = i + 1;
        }
    }
	debug(max_so_far, start, end, s);
	return {max_so_far, start, end, s};
}

void solve(int tc) {
	int n, x; cin >> n >> x;
	vector<int> a(n);
	for (int& u:a) cin >> u;
	
	int ans=0;
	vector<bool> ok(n, true);
	//find maximum subsequence
	for (int k=0; k <=n; ++k){
		vector<int> res = msum(a, n);
		int ans = res[0];
		cout << ans << ' '; 
		debug(k, ans);
		int start = res[1];
		int end = res[2];
		int vmax=INT_MIN, imax=-1;
		for (int i=max(0,start-1); i<min(n,end+1); ++i){
			if (!ok[i]) continue;
			if (a[i] > vmax) {
				imax = i;
				vmax = a[i];
			}
		}
		debug(imax,vmax);
		if (imax >= 0 && imax < n) {
			a[imax]+=x;
			ok[imax] = false;
		}
		debug(a);
		cerr << "ok: [";
		for (auto b:ok){
			cerr << b << ' ';
		} cerr << ']\n';
	}
	cout << '\n';
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt","w", stderr);
	#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0); 
	cout.tie(0);
    int t = 1;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cerr << "Case #" << tc << '\n';
        solve(tc);
    }
}


