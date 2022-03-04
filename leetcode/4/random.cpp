#include <bits/stdc++.h>

using namespace std;

random_device rd;
mt19937 g(rd());

int rnum(int a,int b){
  if(a>b) swap(a,b);
  return a + rand()%(b-a+1);
}

vector<int> rperm(int n){
  vector<int> v(n);
  for (int i=0;i<n;++i) v[i]=i+1;
  shuffle(v.begin(), v.end(), g);
  return v;
}

vector<int> rvec(int n,int a,int b){
  vector<int> v(n);
  for (int i=0;i<n;++i) v[i]=rnum(a,b);
  return v;
}

vector<int> rquery(int a,int b){
  int t=rnum(1,2);
  int x=rnum(a,b);
  int y=rnum(a,b);
  //if (x>y) swap(x,y);
  return {t,x,y};
}

string rstring(int nchar){
  vector<char> v;
  for (int i=0;i<nchar;++i){
    v.push_back((char)rnum(97,122));
  }
  return string(v.begin(),v.end());
}

int main(int argc, char* argv[]) {
  srand(atoi(argv[1]));
  
  int n = rnum(0,10);
  int m = rnum(0,10);
  cout<<n<<' ';
  cout<<m<<'\n';

  vector<int> v1 = rvec(n,0,9);
  sort(v1.begin(),v1.end());
  for (auto u:v1) cout<<u<<' ';
  cout<<'\n';

  vector<int> v2 = rvec(m,0,9);
  sort(v2.begin(),v2.end());
  for (auto u:v2) cout<<u<<' ';
  cout<<'\n';

  return 0;
}



