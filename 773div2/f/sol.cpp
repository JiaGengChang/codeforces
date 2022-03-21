#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

void solve(int tc) {
	int n, m; cin >> n >> m;
	vector<pair<int, vector<int>>> a(n);
  for (int i=0; i<n; ++i){
    for (int j=0; j<m; ++j) {
      int x; cin >> x;
      a[i].second.push_back(x);
    }
    sort(a[i].second.begin(),a[i].second.end());
    cin >> a[i].first;
  }
  sort(a.begin(),a.end());
  for (auto p:a) {
    debug(p.first, p.second);
  }
  int ans=-1;
  for (int i=0; i<n; ++i){
    for (int j=i+1; j<n; ++j){
      bool flag=false;
      for (int k=0; k<m; ++k){
        for (int l=0; l<m; ++l){
          if (a[i].second[k]==a[j].second[l]){
            flag = true;
            break;
          }
        }
      }
      if (!flag){
        if (ans==-1){
          ans = a[i].first + a[j].first;
        } else {
          ans = min(ans, a[i].first + a[j].first);
        }
      }
    }
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
  for (int tc = 1; tc <= t; ++tc) {
      cerr << "Case #" << tc << '\n';
      solve(tc);
  }
}


