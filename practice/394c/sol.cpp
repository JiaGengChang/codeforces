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

void solve() {
    int n,m; cin>>n>>m;
    int d[n][3]; 
    F(i,0,n) F(j,0,3) d[i][j]=10000;
    F(i,0,n){
        string s;
        cin>>s;
        F(j,0,m) {
            switch(s[j]){
                case '*': case '#': case '&':
                    ckmin(d[i][0],min(j,m-j));
                    break;
                case '0': case '1': case '2':
                case '3': case '4': case '5': 
                case '6': case '7': case '8': 
                case '9':
                    ckmin(d[i][1],min(j,m-j));
                    break;
                default:
                    ckmin(d[i][2],min(j,m-j));
            }
        }
    }
    int ans=10000;
    F(i,0,n){
        F(j,i+1,n){
            F(k,j+1,n){
                int mn=10000;
                ckmin(mn, d[i][0] + d[j][1] + d[k][2]);
                ckmin(mn, d[i][0] + d[j][2] + d[k][1]);
                ckmin(mn, d[i][1] + d[j][0] + d[k][2]);
                ckmin(mn, d[i][1] + d[j][2] + d[k][0]);
                ckmin(mn, d[i][2] + d[j][0] + d[k][1]);
                ckmin(mn, d[i][2] + d[j][1] + d[k][0]);
                ckmin(ans,mn);
            }
        }
    }
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


