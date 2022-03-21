/*
 * Generate random test cases 
 * 
 * */
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

    //tc test cases
    int tc=1;
    cout<<tc<<'\n';

    //random number
    int n = rnum(1,100);
    cout<<n<<'\n';

    //random permutation
    vector<int> p = rperm(n);
    for (auto u:p) cout<<u<<' ';
    cout<<'\n';

    //random vector
    vector<int> v = rvec(n,1,1e3);
    for (auto u:v) cout<<u<<' ';
    cout<<'\n';

    //m random queries, t x y
    int m = rnum(1,10);
    cout<<m<<'\n';
    while(m--){
        vector<int> q = rquery(1,1e2);
        for (auto u:q) cout<<u<<' ';
        cout<<'\n';
    }

    return 0;
}



