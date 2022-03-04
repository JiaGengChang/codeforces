#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

int t, n, k;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt","w", stderr);
	#endif

  ios_base::sync_with_stdio(0);
  cin.tie(0); 
	cout.tie(0);
  cin >> t;
  while (t--) {
    cerr << "Case #" << t << '\n';
    cin >> n >> k;
    if (n%2==1 && k>1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    int cur=1;
    for (int i=0; i<n; ++i) {
      for (int j=0; j<k; ++j){
        cout << cur << ' '; 
        cur += 2;
      }
      if (i%2==0) {
        cur -= 2*(k-1)+1;
      } else {
        cur -= 1;
      }
      cout << '\n';
    }
  }
}


