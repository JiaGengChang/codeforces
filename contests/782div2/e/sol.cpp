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
#define R(i, n) for (int i=0; i<(n); i++)
#define R1(i, n) for (int i=1; i<=(n); i++)
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
typedef vector<char> vb;
template<class T> bool ckmin(T& a,const T& b) {return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a,const T& b) {return b>a?a=b,1:0;}
template<class T> bool ckval(T& a,const T& b) {return a<0?a=b,1:0;}

struct dsu {
    vi d;
    dsu(int n) : d(n, -1) {}
    int find(int x) {return d[x] < 0 ? x : d[x] = find(d[x]);}
    void join(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(d[x] > d[y]) swap(x, y);
        d[x] += d[y]; d[y] = x;
    }
    bool is_joined(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    fastio;
    int n,m; cin>>n>>m;
    vector<tuple<int,int,int>> edges;
    R(i,m) {
        int u,v,w; cin>>u>>v>>w;
        edges.eb(--u,--v,w);
    }
    vector<dsu> zero(30,n);//MEX=0
    vector<dsu> one(30,n); //MEX=1
    R(j,30) {
        for(auto& [u,v,w]:edges) if (w>>j & 1) {
            zero[j].join(u,v);
        }
    }
    vb even(n); //component of the node has even edge
    R1(j,29) {
        for(auto& [u,v,w]:edges) if(w>>j & 1) {
            one[j].join(u,v);
        }
        vb vis(n);
        for(auto& [u,v,w]:edges) if(!(w&1)) {
            vis[one[j].find(u)]=1;
            vis[one[j].find(v)]=1;
        }
        R(i,n) if(vis[one[j].find(i)]) even[i]=1;
    }
    auto check = [&](int u,int v)-> int {
        R(j,30) if (zero[j].is_joined(u,v)) return 0;
        if(even[u]) return 1;
        return 2;
    };
    int q; cin>>q;
    while(q--) {
        int u,v; cin>>u>>v; --u,--v;
        cout << check(u,v) << endl;
    }
    return 0;
}


