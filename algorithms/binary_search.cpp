#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

bool good(int m){
    ;
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
  cin >> k >> n;
  a.resize(n);
  for (int i=0;i<n;++i) cin >> a[i];
  int l=0; //good
  int r=accumulate(a.begin(),a.end(),0)/2;//bad
  while(r-l>1){
      int m=(l+r)/2;
      if(good(m)) l=m; else r=m;
  }
  cout << l << '\n';
  return 0;
}


