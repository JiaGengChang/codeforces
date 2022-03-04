#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

string t,p;
int tl,pl;
vector<int> u;

bool good(int m){
  ;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt","w", stderr);
  time_t tstart,tend;
  time(&tstart);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  cin>>t>>p;
  tl=t.size();
  pl=p.size();
  u.assign(tl,0);
  for(auto &i:u)cin>>i;

  int l=0; //good
  int r=tl-pl+1;//bad
  while(r-l>1){
    int m=(l+r)/2;
    if (good(m)) l=m; else r=m;
  }
  cout<<l<<' ';
#ifndef ONLINE_JUDGE
  time(&tend);
  double time_taken=double(tend-tstart);
  cerr<<"Time taken: "<<fixed<<time_taken<<setprecision(5);
  cerr<<" sec\n";
#endif
  return 0;
}


