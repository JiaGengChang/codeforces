#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "../../debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

#define sz(x) ((int)((x).size()))
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

vll factors(ll n){
    set<ll> ps;
    ll z=2;
    while(z*z <= n){
        if (n%z==0) {
            ps.ins(z);
            n/=z;
        } else ++z;
    }
    if (n>1) ps.ins(n);
    vll v;
    copy(all(ps),bkin(v));
    return v;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    fastio;
    int x;
    ll n;
    cin>>x>>n;
    vll ps=factors(x); //prime factors of x
    debug(ps);
    ll ans = 1;
    for (auto p : ps) {
        ll k=0;
        ll m=n;
        while(m>0){
            k += m/p;
            m /= p;
        }
        debug(k);
        //g(1,p) * g(2,p) * ... * g(n,p)
        ll gp = mod_pow(p,k);
        debug(gp);
        debug(ans);
        ans *= gp;
        debug(ans);
        ans %= mod;
    }
    cout<<ans<<'\n';
    return 0;
}


