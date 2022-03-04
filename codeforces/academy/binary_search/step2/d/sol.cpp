#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

int m,n,t,z,y;

struct worker{
  int t,z,y;
};

vector<worker> v;
vector<int> b;

bool good(int T){
  int ans=0;
  b.resize(0);
  for (const auto [t,z,y] : v){
    int q=z*(T/(t*z+y));
    int r=min(z,(T%(t*z+y))/t);
    int s=min(m-ans,q+r);
    ans+=s;
    b.push_back(s);
  }
  return ans>=m;
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
  cin>>m>>n;
  for(int i=0;i<n;++i){
    cin>>t>>z>>y;
    v.push_back({t,z,y});
  }
  int l=-1;//bad
  int r=16499000;//good
  while(r-l>1){
    int mid=(l+r)/2;
    debug(l,mid,r,good(mid));
    if(good(mid)) r=mid; else l=mid;
  }
  cout<<r<<'\n';
  good(r);//reset b
  //cout << accumulate
  for(auto bb:b) cout<<bb<<' ';cout<<'\n';
  return 0;
}


