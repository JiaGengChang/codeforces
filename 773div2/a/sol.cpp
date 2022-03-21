#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

void solve(int tc) {
  int x1,x2,x3,y1,y2,y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  debug(x1, y1);
  debug(x2, y2);
  debug(x3, y3);
  int ans=0;
  if (y1==y2) {
    if (y3 < y1) {
      ans = abs(x2 - x1);
    }
  }
  
  if (y1==y3) {
    if (y2 < y1) {
      ans = abs(x1 - x3);
    }
  }

  if (y2==y3) {
    if (y1 < y2) {
      ans = abs(x2 - x3);
    }
  }
  debug(ans);
  cout << ans << '\n';
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


