#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

void solve(int tc) {
  int a,b; cin >> a >> b;
  debug(a,b);
  int m=b-a;
  for (int a1=a; a1<b; ++a1) {
    int b1=0;
    for (int i=20; i>=0; --i){
      if ((b >> i) & 1) {
        b1^=(1<<i);
      } else if ((a1 >> i)&1) {
        b1^=(1<<i);
        break;
      }
    }
    m = min(m, a1-a-b+(a1|b1)+1);
  }
  cout << m << '\n';
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


