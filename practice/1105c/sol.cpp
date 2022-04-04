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

ll mod_pow(ll b, ll e) {
    ll x=1;
    while(e>0){
        if(e&1){
            x = (x*b)%mod; --e;
        } else {
            b = (b*b)%mod; e/=2;
        }
    }
    return x;
}

tuple<int,int,int> cntModsOf3(int n) {
    if (n<=0) return {0,0,0};
    int c0 = n/3;
    int c1 = n/3 + ((n%3>0) ? 1: 0);
    int c2 = n/3 + ((n%3>1) ? 1: 0);
    return {c0,c1,c2};
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    fastio;
    int n,l,r; cin>>n>>l>>r;
    auto [r0,r1,r2] = cntModsOf3(r);
    auto [l0,l1,l2] = cntModsOf3(l-1);
    ll m0=r0-l0;
    ll m1=r1-l1;
    ll m2=r2-l2;
    debug(m0,m1,m2);
    ll dp[n][3];
    dp[0][0] = m0, dp[0][1]=m1, dp[0][2]=m2;
    F(i,1,n) {
        dp[i][0] = dp[i-1][0]*m0 + dp[i-1][1]*m2 + dp[i-1][2]*m1;
        dp[i][1] = dp[i-1][0]*m1 + dp[i-1][1]*m0 + dp[i-1][2]*m2;
        dp[i][2] = dp[i-1][0]*m2 + dp[i-1][1]*m1 + dp[i-1][2]*m0;
        dp[i][0] %= mod;
        dp[i][1] %= mod;
        dp[i][2] %= mod;
    }
    cout<<dp[n-1][0];
    return 0;
}


