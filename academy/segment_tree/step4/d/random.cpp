#include <bits/stdc++.h>

using namespace std;
int n,m,l,r,v,i;

int rnum(int a,int b){
  if(a>b) swap(a,b);
  return a + rand()%(b-a+1);
}

vector<int> rquery(int a,int b){
  int t=rnum(1,2);
  if(t==1){
    l=rnum(0,n-1);
    r=rnum(l+1,n);
    v=rnum(a,b);
    return {t,l,r,v};
  } else {
    i=rnum(0,n-1);
    return {t,i};
  }
}

int main(int argc, char* argv[]) {
  srand(atoi(argv[1]));
  
  //random number
  n = rnum(1,100000);
  cout<<n<<' ';

  //m random queries, t x y
  m = rnum(1,100000);
  cout<<m<<'\n';
  while(m--){
    int vmax=1e9;
    vector<int> q = rquery(0,vmax);
    for (auto u:q) cout<<u<<' ';
    cout<<'\n';
  }

  return 0;
}



