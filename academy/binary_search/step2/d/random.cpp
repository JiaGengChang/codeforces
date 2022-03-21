#include <bits/stdc++.h>

using namespace std;

random_device rd;
mt19937 g(rd());

int rnum(int a,int b){
  if(a>b) swap(a,b);
  return a + rand()%(b-a+1);
}

vector<int> rvec(int n,int a,int b){
  vector<int> v(n);
  for (int i=0;i<n;++i) v[i]=rnum(a,b);
  return v;
}

int main(int argc, char* argv[]) {
  srand(atoi(argv[1]));
  
  //random number
  int m = rnum(0,10);
  cout<<m<<' ';
  int n = rnum(1,1000);
  cout<<n<<'\n';

  while(n--){
    int t,z,y;
    t = rnum(1,100);
    y = rnum(1,100);
    z = rnum(1,1000);
    cout<<t<<' '<<z<<' '<<y<<'\n';
  }

  return 0;
}



