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
  b.assign(0,0);
  for (const auto [t,z,y] : v){
    int Ti=T;
    int mi=0;//number of balloons worker i will make
    int flag=true;//enough time to make one balloon
    while(Ti>0 && flag){
      int zi=z;
      //make z balloons
      while(zi--){
        //no excess ballons 
        if (Ti<t || ans+mi==m) {flag=false;break;}
        ++mi;
        Ti-=t;
      }
      //rest y minutes if z balloons are made
      if(flag) Ti-=y;
    }
    ans+=mi;
    b.push_back(mi);
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
  int i=0;
  while(i<=2e7){
    if (good(i)) break;
    ++i;
  }
  cout<<i<<'\n';
  for(auto bb:b) cout<<bb<<' ';cout<<'\n';
  return 0;
}


