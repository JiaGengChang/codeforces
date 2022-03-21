#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;
long double c;
long double f(double x) {return x*x+sqrt(x);}
int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt","w", stderr);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  cin >> c;
  double l=0;//less than c
  double r=1e5;//greater than c
  for(int i=0;i<60;++i){
    double m=(l+r)/2;
    if (f(m)<c) l=m; else r=m;
    debug(i,f(l),f(r));
  }
  cout<<setprecision(20);
  cout<<l<<'\n';

  return 0;
}


