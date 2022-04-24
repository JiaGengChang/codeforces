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
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
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
#define eb emplace_back
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

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    fastio;
    int t; cin>>t;
    while (t--) {
        int n; cin>>n;
        vi a(n);
        F(i,0,n) cin>>a[i];
        int cneg=0,lct=0,gct=0,lstart=0,lend=0,gstart=0,gend=0;
        FE(i,0,n) {
            if (i==n || a[i]==0) {
                debug(cneg);
                if (cneg%2==0) {
                    if (ckmax(gct,lct)) {
                        gstart=lstart,gend=lend;
                    }
                } else {
                    //remove one negative number
                    //remove segment with fewer 2s
                    int ctl=0,ctr=0;
                    int lneg=lstart,rneg=lend;
                    while (lneg<=lend) {
                        if (abs(a[lneg])==2) ++ctl;
                        if (a[lneg]<0) break;
                        lneg++;
                    }
                    while (rneg>=lstart) {
                        if (abs(a[rneg])==2) ++ctr;
                        if (a[rneg]<0) break;
                        rneg--;
                    }
                    debug(lstart,lend);
                    debug(lneg,ctl);
                    debug(rneg,ctr);
                    debug(lct, gct);
                    if (ctl<ctr) {
                        if (ckmax(gct,lct-ctl)) {
                            gstart=lneg+1,gend=lend;
                        }
                    } else {
                        if (ckmax(gct,lct-ctr)) {
                            gstart=lstart,gend=rneg-1;
                        }
                    }
                }
                lstart=lend=-1;
                lct=cneg=0;
                continue;
            }
            if (lstart==-1) {
                lstart=lend=i;
            } else {
                lend=i;
            }
            if (abs(a[i])==2) ++lct; 
            if (a[i]<0) ++cneg;
        }
        if (gct) cout<<gstart<<" "<<n-gend-1<<"\n";
        else cout<<"0 "<<n<<"\n";
    }
    return 0;
}


