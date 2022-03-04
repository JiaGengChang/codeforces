#include <bits/stdc++.h>

using namespace std;

long long n,x,y;
bool good(long long t){
  long long z=t-min(x,y);
  return z>=0 && z/x+z/y+1>=n;
}
int main(){
  scanf("%d%d%d",&n,&x,&y);
  long long l=0,r=1e9+10;//l=bad,r=good
  while(r>l+1){
    long long m=(l+r)/2;
    if(good(m)) r=m; else l=m;
  }
  printf("%d",r);
  return 0;
}
