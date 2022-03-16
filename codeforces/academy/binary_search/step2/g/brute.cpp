#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(x...)
#endif

using namespace std;
int k,n;
vector<int> a;
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
  debug(a);
  long long ncouncils=0;
  while(true){
      sort(a.rbegin(),a.rend());
      int cnt=k;
      //to form a council:
      //take one student per non-0 group until we get k 
      for (int i=0; cnt>0 && i<n; ++i){
          if(a[i]>0) {
              --a[i];
              --cnt;
          }
      }
      debug(ncouncils,a);
      if (cnt>0) break; else ++ncouncils;
  }
  cout << ncouncils << '\n';
  return 0;
}


