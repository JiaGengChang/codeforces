#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

#define F(i,L,R) for (int i = L; i < R; i++) 
#define ALL(c) (c).begin(),(c).end() 
#define ll long long 
#define ins insert
#define pb push_back
#define MOD 1000000007
typedef vector<ll> vll;

ll mod_pow(ll b, ll e, ll mod) {
    ll x=1;
    while(e>0){
        if(e%2==1){
            x = (x*b)%mod;
            --e;
        } else {
            b = (b*b)%mod;
            e /= 2;
        }
    }
    return x;
}

void solve() {
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    F(i,0,n) cin>>a[i];
    ll amax = *max_element(ALL(a));
    if (amax==0){
        cout<<1<<'\n';
        return;
    }
    ll asum = std::accumulate(ALL(a),0ll);
    ll v = asum-amax; //minimum degree
    ll acnt = count(ALL(a),amax);
    if (acnt%x!=0){
        cout<<(mod_pow(x, v, MOD))<<"\n";
        return;
    }
    vll adeg;
    F(i,0,n) adeg.pb(asum-a[i]);
    sort(ALL(adeg));
    while(acnt%x==0){
        ++v;
        acnt /= x;
        acnt += count(ALL(adeg), v);
    }
    cout<<(mod_pow(x, min(asum, v), MOD))<<"\n";
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    solve();
    return 0;
}


