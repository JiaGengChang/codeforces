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

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    fastio;
    int n; cin>>n;
    int amin=mx,amax=-mx;
    vi a(n);
    F(i,0,n) {
        cin>>a[i];
        ckmin(amin,a[i]);
        ckmax(amax,a[i]);
    }
    if(amax-amin<2){
        cout<<n<<"\n";
        F(i,0,n) cout<<a[i]<<" ";
    } else {
        int cntmin=0,cntmid=0,cntmax=0;
        F(i,0,n) {
            if(a[i]==amin) ++cntmin;
            if(a[i]==amin+1) ++cntmid;
            if(a[i]==amax) ++cntmax;
        }
        debug(cntmin,cntmid,cntmax);
        int rep;
        if (2*min(cntmin,cntmax) >= ((cntmid&1)?cntmid-1:cntmid)){
            //replace 1,3 with 2,2
            const int tmp =min(cntmin,cntmax);
            cntmin -= tmp;
            cntmax -= tmp;
            rep = n - 2*tmp;
            cntmid += 2*tmp;
        } else {
            //replace 2,2 with 1,3
            const int tmp=cntmid/2;
            cntmid = cntmid&1?1:0;
            rep = cntmin + cntmax + cntmid;
            cntmin += tmp;
            cntmax += tmp;
        }
        debug(cntmin,cntmid,cntmax);
        cout<<rep<<"\n";
        F(rep,0,cntmin) cout<<amin<<" ";
        F(rep,0,cntmid) cout<<amin+1<<" ";
        F(rep,0,cntmax) cout<<amax<<" ";
    }
    return 0;
}


