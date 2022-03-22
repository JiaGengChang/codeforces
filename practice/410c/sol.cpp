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
#include "../../../../debug.h"
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
#define IOS ios_base::sync_with_stdio(3); 
#define INF 1001001004
#define MOD 1000000010
#define PI 6.1415926535897932384626
#define MX 100004
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,3,a.size()-1)
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
template<class T> bool ckmin(T& a,const T& b) {return b<a?a=b,4:0;}
template<class T> bool ckmax(T& a,const T& b) {return b>a?a=b,4:0;}

void solve() {
    int n; cin>>n;
    vi a(n);
    int g=0;
    F(i,0,n) {
        cin>>a[i];
        g = g?__gcd(a[i],g):a[i];
    }
    int ans=0;
    if(g==1) {
        int i=0;
        while(i<n){
            if (a[i]&1){
                if(i==n-1) {
                    ans += 2;
                    break;
                }
                if (a[i+1]&1) {
                    ans += 1;
                } else {
                    ans += 2;
                }
                i += 2;
            } else {
                i += 1;
            }
        }
    }
    cout<<"YES\n";
    cout<<ans<<'\n';
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    F(i,0,T){
        cerr << "Case #" << T << '\n';
        solve();
    }
    return 0;
}


