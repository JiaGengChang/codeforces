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

const int N=51;
int n,r1,c1,r2,c2,v[2][N][N],ans=inf;
char g[N][N];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue<ii> q[2];

/*
 *void dfs(int t, int r, int c) {
 *    if (r<0 || c<0 || r==n || c==n || v[t][r][c] || g[r][c]=='1') return;
 *    if(!v[t][r][c]) {
 *        v[t][r][c]=1;
 *        f(d,0,4) dfs(t, r+dx[d], c+dy[d]);
 *    }
 *}
 */

void bfs(int t, int r, int c) {
    q[t].push({r,c});
    while(!q[t].empty()) {
        auto [r,c] = q[t].front();
        if (r>=0 && c>=0 && r<n && c<n && !v[t][r][c] && g[r][c]=='0') {
            v[t][r][c]=1;
            F(d,0,4) q[t].push({r+dx[d],c+dy[d]});
        }
        q[t].pop();
    }
}
int main() {
    cin>>n>>r1>>c1>>r2>>c2;
    F(i,0,n) cin>>g[i];
    memset(v,0,sizeof(v));
    bfs(0,r1-1,c1-1); bfs(1,r2-1,c2-1);
    /*
     *F(i,0,n) F(j,0,n) cout<<(g[i][j])<<" \n"[j==n-1];
     *F(i,0,n) F(j,0,n) cout<<(v[0][i][j])<<" \n"[j==n-1];
     *F(i,0,n) F(j,0,n) cout<<(v[1][i][j])<<" \n"[j==n-1];
     */
    F(i,0,n) 
        F(i2,0,n) 
            F(j,0,n) 
                F(j2,0,n) {
                    if (v[0][i][j] && v[1][i2][j2]) 
                        ckmin(ans,(i2-i)*(i2-i)+(j2-j)*(j2-j));
                }
    cout<<ans;
    return 0;
}


