#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

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
    int n, x; cin >> n >> x;
    debug(tc, n, x);
    vector<int> a(n);
    for (auto &u:a) cin >> u;
    sort(a.begin(),a.end());
    debug(a);
    vector<int> used(n,false);
    int ans=0;
    for (int i=0; i<n; ++i){
      if (!used[i]) {
        int target=x*a[i];
        int l=i+1, r=n-1, t=-1;
        //look for target
        while (l < n && r >= l) {
          int m = (l+r)/2;
          if (!used[m] && a[m]==target){
            t=m;
            break;
          }
          if (a[m] < target){
            l = m+1;
          } else {
            r = m-1;
          }
        }
        debug(i, a[i], target, t);
        if (t!=-1 && !used[t]){
          used[i] = true;
          used[t] = true;
        }
      }
    }
    for (auto b:used) {
      if (!b) ++ans;
    }
    cout << ans << '\n';
  }
}


