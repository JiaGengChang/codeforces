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
    v.push_back((char)rnum(97,122));//97-122
  }
  return string(v.begin(),v.end());
}

int main(int argc, char* argv[]) {
  srand(atoi(argv[1]));
  
  //random number
  int t = rnum(2,10000);
  //int t = 10000;
  int p = rnum(1,t-1);
  
  //random string
  string st=rstring(t);
  cout<<st<<'\n';

  //permutation to obtain p
  vector<int> v = rperm(t);

  //delete down to p letters
  vector<char> vp;
  sort(v.begin()+t-p,v.end());
  for (int i=t-p;i<t;++i) vp.push_back(st[v[i]-1]);
  string sp (vp.begin(),vp.end());
  cout<<sp<<'\n';

  //random permutation
  vector<int> u = rperm(t);
  for (auto i:u) cout<<i<<' ';cout<<'\n';

  return 0;
}



