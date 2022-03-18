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
    //partition fountains into coin and diamond classes
    int n,c,d; cin>>n>>c>>d;
    vector<ii> C,D;
    F(rep,0,n) {
        int b,p;
        unsigned char t;
        cin>>b>>p>>t;
        if(t=='C') {
            C.pb({p,b});
        } else {
            D.pb({p,b});
        }
    }
    sort(ALL(C));//sort by ascending cost
    sort(ALL(D));
    int nc = C.size(), nd = D.size();
    int cmaxB[nc], dmaxB[nd];//prefix max
    cmaxB[0] = C[0].s;
    dmaxB[0] = D[0].s;
    F(i,1,nc) cmaxB[i] = max(cmaxB[i-1],C[i].s);
    F(i,1,nd) dmaxB[i] = max(dmaxB[i-1],D[i].s);
    int ans=0;
    //two coin or two diamond fountains
    vi mixB(2,-1);
    F(i,0,nc) if(C[i].f<=c) ckmax(mixB[0],C[i].s);
    F(i,0,nd) if(D[i].f<=d) ckmax(mixB[1],D[i].s);
    if(mixB[0]>-1&&mixB[1]>-1) ans = mixB[0]+mixB[1];
    
    //one coin fountain, one diamond fountain
    //p1=p2
    int sepB(2,-1);
    F(i,0,nc-1) {
        if(C[i].f*2>c) break;
        if(C[i].f==C[i+1].f) {
            ckmax(sepB[0],C[i].s+C[i+1].s);
        }
    }
    //p2>p1. fix p2
    FFE(i,nc-1,0){
        if(C[0].f+C[i].f>c) continue;
        int l=0;
        int r=i;
        while(r-l>1){
            int m=(l+r)/2;
            if(C[m].f+C[i].f<=c){
                l=m;
            } else {
                r=m;
            }
        }
        ckmax(sepB[0],C[i].s+cmaxB[l]);
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
    int T = 1;
    F(i,0,T){
        cerr << "Case #" << T << '\n';
        solve();
    }
    return 0;
}


