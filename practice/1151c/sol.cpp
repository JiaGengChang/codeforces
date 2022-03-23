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
#define ALL(c) (c).begin(),(c).end() 
#define RALL(c) (c).rbegin(),(c).rend() 
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define printA(a,L,R) F(i,L,R) cout << a[i] << (i==R-1?'\n':' ')
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
#define INF 1001001001
#define MOD 1000000007
#define PI 3.1415926535897932384626
#define MX 100001
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

ull mod_mul(ull a, ull b, ull mod) {
    return ((a%mod)*(b%mod))%mod;
}

ull psum(ll i) {
    if (i<=0) return 0;
    int k = log2(i+1);
    ull cntOdd=0, cntEven=0;
    F(p,0,k) {
        if (p%2==0) {
            cntOdd = cntOdd*4+1;
        } else {
            cntEven = cntEven*4+2;
        }
    }
    if (k&1) {
        cntEven += i-(1ULL<<k)+2;
    } else {
        cntOdd += i-(1ULL<<k)+2;
    }
    ull sumOdd = mod_mul(cntOdd,cntOdd,MOD);
    ull sumEven = mod_mul(cntEven,cntEven+1,MOD);
    return (sumOdd+sumEven)%MOD;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    FASTIO;
    ull l,r; cin>>l>>r;
    if(r==1) {
        cout<<"1\n";
    } else {
        ull sumL = psum(l-2);
        ull sumR = psum(r-1);
        cout<<((sumR - sumL + MOD)%MOD);
    }
    return 0;
}


