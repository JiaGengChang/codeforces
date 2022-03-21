#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

int t, n, k;
string s;

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt","w", stderr);
	#endif

  cin >> t;
  while (t--){
    cin >> n >> k >> s;
    string t=s;
    reverse(t.begin(),t.end());
    if (k==0 || s==t) {
      cout << 1 << '\n';
    } else {
      cout << 2 << '\n';
    }
  }
  return 0;
}
