#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

void solve(int tc) {
	int n; cin >> n;
  bool flag=false;
  vector<int> perm;
  for (int i=n-1; i>=1; --i){
    perm.push_back(i);
    if (__builtin_popcount(i)==1 && !flag) {
      perm.push_back(0);
      flag=true;
    }
  }
  for (int p:perm) cout << p << ' ';
  debug(perm);
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


