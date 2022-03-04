#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;
long long n,m,t,l,r,v,i;
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt","w", stderr);
	#endif

  ios_base::sync_with_stdio(0);
  cin.tie(0); 
	cout.tie(0);
  cin>>n>>m;
  vector<long long> a(n,0);
  while(m--){
    cin>>t;
    if(t==1){
      cin>>l>>r>>v;
      for(long long i=l;i<r;++i) a[i]+=v;
    } else {
      cin>>i;
      cout<<a[i]<<'\n';
    }
  }
  return 0;
}


