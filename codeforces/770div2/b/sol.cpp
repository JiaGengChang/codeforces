#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

void solve(int tc) {
	int n; cin >> n;
	vector<int> a(n);
	for (int& u:a) cin >> u;
  map<int, vector<int>> pos;
  vector<int> sub(n, -1);
  set<int> dup;
  for (int i=0; i<n; ++i){
    if (dup.count(a[i])>0){
      pos[a[i]].push_back(i);
    } else {
      dup.insert(a[i]);
      pos.insert({a[i], {i}});
    }
  }
  cerr << "dup: "; for (auto d:dup) cerr << d << ' ';cerr << '\n';
  cerr << "pos: \n"; 
  for (auto p:pos) {
    cerr << p.first << ": ";
    for (auto k:p.second) {
      cerr << k << ' ';
    }
    cerr << '\n';
  }
  for (auto v:pos) {
    int lmin=n,rmin=n;
    if (v.second.size() > 1) {
      a
    }
  }
  debug(sub);
  cout << *max_element(sub.begin(),sub.end()) << '\n';

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


