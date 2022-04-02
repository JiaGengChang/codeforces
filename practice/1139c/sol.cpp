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
typedef vector<pair<int,int>> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> llll;
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

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    fastio;
    ll n,k;
    cin>>n>>k;
    vii root(n,{-1,0});
    F(i,0,n-1){
        int u,v,c;
        cin>>u>>v>>c;
        --u,--v;
        if(c==0) {
            if(root[u].f==-1 && root[v].f==-1) {
                root[u].f=u,root[v].f=u;
                root[u].s=2;
                continue;
            }
            if(root[v].f==-1 && root[u].f>=0) {
                //v into u
                while(root[u].f!=u) u=root[u].f;
                ++root[u].s;
                root[v].f=u;
                continue;
            }
            if(root[u].f==-1 && root[v].f>=0) {
                //u into v
                while(root[v].f!=v) v=root[v].f;
                ++root[v].s;
                root[u].f=v; 
                continue;
            }
            if(root[u].f>=0 && root[v].f>=0) {
                while(root[v].f!=v) v=root[v].f;
                while(root[u].f!=u) u=root[u].f;
                if(root[u].s<root[v].s) {
                    //u into v
                    root[u].f=root[v].f;
                    root[v].s+=root[u].s;
                } else {
                    //v into u
                    root[v].f=root[u].f;
                    root[u].s+=root[v].s;
                }
            }
        }
    }
    int nblack=0;
    vi reds;
    F(i,0,n) {
        if (i==root[i].f) reds.pb(root[i].s);
        if (-1==root[i].f) ++nblack;
    }
    debug(root);
    debug(reds);
    ll ans=mod_pow(n,k)-nblack;
    debug(ans);
    for(int s:reds) ans-=mod_pow(s,k), ans+=mod, ans%=mod;
    cout<<ans;
    return 0;
}


