#include "bits/stdc++.h"
#ifndef ONLINE_JUDGE
#include "../../debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

#define sz(x) ((int)((x).size()))
#define mt(x) ((x).empty())
#define FI(it,x) for (auto it=(x).begin(); it!=(x).end(); ++it)
#define F(i,L,R) for (int i = L; i < R; i++) 
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define all(c) (c).begin(),(c).end() 
#define rall(c) (c).rbegin(),(c).rend() 
#define present(c,x) ((c).find(x) != (c).end())
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define prints(a,L,R) F(i,L,R) cout << a[i] << (i==R-1?'\n':' ')
#define f first
#define s second
#define ins insert
#define fif find_if
#define bkin back_inserter
#define cpif copy_if
#define mxel max_element
#define mnel min_element
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define ppb pop_back
#define inf 1001001001
#define mod 1000000007
#define pi 3.1415926535897932384626
#define mx 100001
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef pair<int,int> ii;
typedef set<pair<int,int>> sii;
typedef vector<pair<int,int>> vii;
typedef vector<bool> vb;
template<class T> bool ckmin(T& a,const T& b) {return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a,const T& b) {return b>a?a=b,1:0;}
template<class T> bool ckval(T& a,const T& b) {return a<0?a=b,1:0;}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    fastio;
    int s, x1, x2, t1, t2, p, d;
    cin>>s>>x1>>x2>>t1>>t2>>p>>d;
    int leg1=-1, leg2=-1;
    if (p<=x1) 
        leg1=(p==x1)?0:x1-d*p; 
    else 
        leg1=(d==1)?2*s-p-x1:p-x1;
    if (d*(p-x1)>0) d*=-1;
    if (d*(x1-x2)<=0) 
        leg2=abs(x1-x2); 
    else 
        leg2=(d==1)?2*s-x1-x2:x1+x2;
    debug(leg1,leg2);
    cout<<min((abs(x1-x2)*t2),(leg1+leg2)*t1);
    return 0;
}


