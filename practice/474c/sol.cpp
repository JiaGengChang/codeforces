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
#include "debug.h"
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
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
bool ckmin(ll& a,ll b){return b<a ? a=b,true:false;}
bool ckmax(ll& a,ll b){return b>a ? a=b,true:false;}

ll x,d,y,z; 
vector<ll> ans;

void solve() {
    debug(y);
    if(ans.size()>9999) {
        cout<<"-1";
        return;
    }
    if(y==0){
        cout<<ans.size()<<'\n';
        printV(ans);
        return;
    }
    int k=(int)(log2(y+1)); //2^k-1 <= X
    F(rep,0,k) ans.push_back(z);
    z += d;
    y -= (1<<k)-1ll;
    solve();
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
    auto start=chrono::high_resolution_clock::now();
#endif

    IOS;
    cin.tie(0); 
    cout.tie(0);
    cin>>x>>d;
    ans.resize(0);
    y=x;
    z=1;
    solve();

#ifndef ONLINE_JUDGE
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(stop-start);
    cerr << duration.count() << "ms\n";
#endif
    return 0;
}


