#include <bits/stdc++.h>
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
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> llll;
template<class T> bool ckmin(T& a,const T& b) {return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a,const T& b) {return b>a?a=b,1:0;}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    fastio;
    const int N=2e3+100;
    ll n,m,a[N],b[N],x,mna[N],mnb[N],ans=0;
    cin>>n>>m;
    a[0]=b[0]=mna[0]=mnb[0]=0;
    FE(i,1,n) cin>>a[i], a[i]+=a[i-1];
    FE(i,1,m) cin>>b[i], b[i]+=b[i-1];
    cin>>x;
    memset(mna,inf,sizeof(mna));
    memset(mnb,inf,sizeof(mnb));
    FE(i,1,n) FE(j,i,n) ckmin(mna[j-i+1],a[j]-a[i-1]);
    FE(i,1,m) FE(j,i,m) ckmin(mnb[j-i+1],b[j]-b[i-1]);
    FE(i,1,n) FE(j,1,m) if (mna[i]*mnb[j]<=x) ckmax(ans,ll(i)*ll(j));
    cout<<ans<<'\n';
    return 0;
}


