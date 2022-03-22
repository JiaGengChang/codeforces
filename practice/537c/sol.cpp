#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../../debug.h"
#else 
#define debug(x...)
#endif
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
#define MOD 1000000007
#define PI 3.1415926535897932384626
#define MX 100001
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)
#define f first
#define s second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define pb push_back
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
template<class T> bool ckmin(T& a,const T& b) {return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a,const T& b) {return b>a?a=b,1:0;}

int N, K, a, b;

ll calc(int n, map<ll,int> & p, int l, int r){
    if (p.size()==0) {
        return a;
    }
    int na = accumulate(p.begin(),p.end(),0,[](const size_t acc, const auto& elem){return acc + elem.s;});
    ll v2 = 1ll*b*na*(1<<n);//cost to destroy entire array of length 2^n
    if(n==0){
        debug(p.size(),l,r);
        return v2;
    }
    //recurse into each half
    auto mid = p.lb(((ll)l+(ll)r)/2+1ll);
    map<ll,int> p0(p.lb(l),mid);
    map<ll,int> p1(mid,p.ub(r));
    ll v0 = calc(n-1,p0,l,(l+r)/2);
    ll v1 = calc(n-1,p1,(l+r)/2+1,r);
    return min(v0+v1,v2);
}

void solve() {
    map<ll,int> p; //position of the K avengers
    cin>>N>>K>>a>>b; 
    F(rep,0,K){
        ll j; cin>>j;
        p[j]++;
    }
    ll ans = calc(N,p,1,1<<N);
    cout<<ans<<'\n';
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    F(i,0,T){
        cerr << "Case #" << T << '\n';
        solve();
    }
    return 0;
}


