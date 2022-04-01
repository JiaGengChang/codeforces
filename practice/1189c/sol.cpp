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
    const int N = 100005;
    int n, s[N]; cin>>n;
    vector<vector<ii>> dp(20);
    F(i,0,n) cin>>s[i], dp[0].pb({s[i],0});
    int cur=1;
    F(deg,1,20) {
        cur*=2;
        if(cur>n) break;
        dp[deg] = vector<ii>(n-cur+1);
        for (int i=0; i+cur<=n; ++i) {
            int sum = dp[deg-1][i].f + dp[deg-1][i+cur/2].f;
            int candies = dp[deg-1][i].s + dp[deg-1][i+cur/2].s;
            if (sum>=10) ++candies;
            dp[deg][i] = {sum%10,candies};
        }
    }
    int q;cin>>q;
    while(q--){
        int l,r; cin>>l>>r;
        int deg = log2(r-l+1);
        cout<<dp[deg][l-1].s<<'\n';
    }
    return 0;
}


