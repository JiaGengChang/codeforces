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

//fast power with square-and-multiply method
//as a modification, take modulo at each step
ll mod_pow(ll b, ll e, ll mod) {
    ll x=1;//running product
    while(e>0){
        if(e%2==1){
            x = (x*b)%mod;
            --e;
        } else {
            b = (b*b)%mod;//factor we multiply running product with
            e /= 2;
        }
    }
    return x;
}

void solve() {
    int n,q;
    string bits;
    cin>>n>>q>>bits;
    int pref[n];
    pref[0] = bits[0]-'0';
    F(i,1,n) pref[i] = pref[i-1] + (bits[i]-'0');
    while(q--){
        int l,r; cin>>l>>r;
        --l;--r;
        int x = pref[r] - (l==0?0:pref[l-1]);//count of 1s
        int y = r-l+1-x; //count of 0s
        ll px = mod_pow(2, x, MOD);
        ll py = mod_pow(2, y, MOD);
        cout<<((px-1)*(py))%MOD<<'\n';
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    cin.tie(0); 
    cout.tie(0);
    solve();
    return 0;
}


