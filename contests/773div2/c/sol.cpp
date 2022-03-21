#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

void solve(int tc) {
	int n,x; cin >> n >> x;
	multiset<long long> a;
	for (int i=0; i<n; ++i) {
    long long u; 
    cin >> u; 
    a.insert(u);
  }
  int ans=0;
  while (a.size()>0) {
    long long cmin = *(a.begin());
    long long target = cmin * x;
    debug(cmin, x, target);
    auto it = a.find(target);
    if (it != a.end()){
      a.erase(it);
    } else {
      ++ans;
    }
    a.erase(a.begin());
  }
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


