#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x)
#endif

using namespace std;

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  //subsum[i] = max sum of subarray of length i
  vector<long long> subsum(n + 1, LLONG_MIN);
  subsum[0] = 0;
  for (int l = 0; l < n; ++l) {
    long long s = 0;
    for (int r = l; r < n; ++r) {
      s += a[r];
      subsum[r - l + 1] = max(subsum[r - l + 1], s);
    }
  }
  debug(subsum);
  //max sum of subarray of length >= i
  vector<long long> suffmax(n + 1);
  suffmax[n] = subsum[n];
  for (int i = n - 1; i >= 0; --i) suffmax[i] = max(subsum[i], suffmax[i + 1]);
  debug(suffmax);
  long long cur = 0;
  for (int i = 0; i <= n; ++i) {
    //max sum of subarray with len >= k 
    cout << max(cur, suffmax[i] + i * x) << ' ';
    //alternative: max sum of subarray with len <= k
    cur = max(cur, subsum[i] + i * x);
	debug(cur);
  }
  cout << '\n';
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt","w", stderr);
	#endif

  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}

