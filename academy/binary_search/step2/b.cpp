#include <bits/stdc++.h>
using namespace std;
int n,k;
vector<int> a;

bool good(double x){
  int j=0;
  for (int i=0;i<n;++i){
    j+=floor(a[i]/x);
  }
  return j>=k;
}
int main(){
  scanf("%d%d",&n,&k);
  a.resize(n);
  for(int i=0;i<n;++i){
    scanf("%d",&a[i]);
  }
  double l=0,r=1e8;
  int niter=60;
  while(niter--){
    double m=(l+r)/2;
    if(good(m)) l=m; else r=m;
  }
  printf("%.7f",l);
  return 0;
}
