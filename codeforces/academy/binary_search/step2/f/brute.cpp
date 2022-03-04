#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

string t,p;
int tl,pl;
vector<int> u,u2;

bool good(int m){
  vector<int> bad(u2.begin(),u2.begin()+m);
  vector<char> s;
  for (int i=0;i<tl;++i){
    if (find(bad.begin(),bad.end(),u[i])==bad.end()){
      s.push_back(t[u[i]-1]);
    }
  }
  //is p a substring of s
  int pi=0,si=0;
  bool is_substring=true;
  while(pi<pl){
    if (si==s.size()){
      is_substring=false; break;
    }
    if (p[pi]==s[si]){
      ++pi;++si;
    } else {
      ++si;
    }
  }
  return is_substring;
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
  u2 = vector<int>(u);
  sort(u.begin(),u.end());

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


