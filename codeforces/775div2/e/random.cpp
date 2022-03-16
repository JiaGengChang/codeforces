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

    const int mxs=20;//max letters of s 
    const int mxt=20;
    const int mxn=10;//length of s
    const int mxm=10;

    int n = rnum(1,mxn);
    int m = rnum(1,mxm);
    cout<<n<<' '<<m<<'\n';

    vector<int> s = rvec(n,1,mxs);
    vector<int> t = rvec(m,1,mxt);
    for (auto u:s) cout<<u<<' ';
    cout<<'\n';
    for (auto u:t) cout<<u<<' ';
    cout<<'\n';

    return 0;
}



