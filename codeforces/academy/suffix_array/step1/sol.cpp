#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

#define REMAX(a,b) (a)=max((a),(b)) 
#define REMIN(a,b) (a)=min((a),(b));
#define SZ(x) ((int)((x).size()))
#define F(i,L,R) for (int i = L; i < R; i++) 
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++) 
#define ALL(c) (c).begin(),(c).end() 
#define RALL(c) (c).rbegin(),(c).rend() 
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define CPRESENT(c,x) (find(ALL(c),x) != (c).end()) 
#define ll long long 
#define ull unsigned long long
#define ui unsigned int
#define us unsigned short
#define IOS ios_base::sync_with_stdio(0); 
#define INF 1001001001
#define PI 3.1415926535897932384626
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
bool ckmin(ll& a,ll b){return b<a ? a=b,true:false;}
bool ckmax(ll& a,ll b){return b>a ? a=b,true:false;}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif

    //build suffix array in n(logn)(logn) time
    string s;
    cin>>s;
    s += "$";
    int n = s.size();
    vi p(n), c(n);
    //phase k=0
    vector<pair<char,int>> a(n);
    F(i,0,n) a[i] = {s[i],i};
    sort(ALL(a));
    F(i,0,n) p[i]=a[i].second;
    c[p[0]]=0;
    F(i,1,n) c[p[i]] = (a[i].first==a[i-1].first)?c[p[i-1]]:c[p[i-1]]+1;

    //phase k to k+1
    int k=0;
    while((1<<k)<n){
        vector<pair<pair<int,int>,int>> a(n);
        F(i,0,n) a[i] = {{c[i],c[(i+(1<<k))%n]}, i};
        sort(ALL(a));
        F(i,0,n) p[i]=a[i].second;
        c[p[0]]=0;
        F(i,1,n) c[p[i]] = (a[i].first==a[i-1].first)?c[p[i-1]]:c[p[i-1]]+1;
        ++k;
    }

    //final suffix array
    F(i,0,n) {
        cout<<p[i]<<' ';
    }

    return 0;
}



