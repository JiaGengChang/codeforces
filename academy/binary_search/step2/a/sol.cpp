#include <cstdio>
using namespace std;

long long w,h,n;
bool good(long long x){
  return ((x/w)*(x/h)>=n);
}
int main() {
  scanf("%d%d%d",&w,&h,&n);
  long long l=0,r=1;
  while(!good(r)) r*=2;
  while(r>l+1){
    long long m=(l+r)/2;
    if (good(m)) {
      r=m;
    } else {
      l=m;
    }
  }
  printf("%lld",r);
  return 0;
}


