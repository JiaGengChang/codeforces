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
#define PI 3.1415926535897932384626
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
const int fx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
bool ckmin(ll& a,ll b){return b<a ? a=b,true:false;}
bool ckmax(ll& a,ll b){return b>a ? a=b,true:false;}

const int N = 10000001;

vi lp(N);
vi pr;

void sieve() {
    pr.resize(0);
    F(i,2,N){
        if(lp[i]==0) {
            lp[i]=i;
            pr.push_back(i);
        }
        for(ll j=0;j<pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j){
            lp[i * pr[j]] = pr[j];
        }
    }
}

void solve() {
    int n,m; cin>>n;
    vi cnt(N,0), f(N,0);
    F(i,0,n) {
        int x;
        cin>>x;
        ++cnt[x];
    }
    for(auto p:pr){
        for(int i=1;i*p<=N;++i){
            f[p] += cnt[i*p];
        }
    }
    int pre[N]; 
    pre[0]=0;
    pre[1]=0;
    FE(i,2,N) pre[i] = f[i] + pre[i-1];
    cin>>m;
    while(m--){
        int l,r;
        cin>>l>>r;
        l = min(l,N-1);
        r = min(r,N-1);
        cout<<(pre[r]-pre[l-1])<<'\n';
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
    auto start=chrono::high_resolution_clock::now();
#endif

    cin.tie(0); 
    cout.tie(0);
    sieve();
    solve();
#ifndef ONLINE_JUDGE
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(stop-start);
    cerr << duration.count() << "ms\n";
#endif
    return 0;
}


