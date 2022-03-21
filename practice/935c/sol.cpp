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

inline double dist2(double x1, double y1, double x2, double y2){
    return ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void solve() {
    double R,x1,y1,x2,y2;
    cin>>R>>x1>>y1>>x2>>y2;
    if(dist2(x1,y1,x2,y2)>=R*R){
        cout<<x1<<" "<<y1<<" "<<R<<'\n';
        return;
    }
    bool swapped=false;
    if(x1==x2){
        swapped=true;
        swap(x1,y1);
        swap(y2,x2);
    }
    if(x1==x2){
        cout<<(x1+R/2)<<" "<<x1<<" "<<(R/2)<<'\n';
        return;
    }
    double theta = atan((y1-y2)/(x1-x2));
    debug(theta);
    if(theta > PI) theta -= PI;
    if(theta > PI/2) theta -= PI/2;
    if(theta < 0) theta = -theta;
    debug(theta);
    double x3 = x1 + (x2>x1?1.0:-1.0)*R*cos(theta);
    double y3 = y1 + (y2>y1?1.0:-1.0)*R*sin(theta);
    double r = R-sqrt(dist2(x2,y2,x3,y3))/2.0;
    //binary search
    double tdist2 = dist2(x1,y1,x2,y2);
    double lx = x1 + (x1>x2?1.0:-1.0)*R*cos(theta); //good
    double rx = x1; //bad, will include point x2y2
    F(rep,0,100) {
        double mx = (lx+rx)/2.0;
        double my = (x1*y2 - x2*y1 + (y1-y2)*mx)/(x1-x2);
        double xtmp = mx + (x2>x1?1.0:-1.0)*r*cos(theta);
        double ytmp = my + (y2>y1?1.0:-1.0)*r*sin(theta);
        if(dist2(x1,y1,xtmp,ytmp)<tdist2){
            lx=mx;
        } else {
            rx=mx;
        }
    }
    double ly = (x1*y2 - x2*y1 + (y1-y2)*lx)/(x1-x2);
    cout<<setprecision(20);
    if(swapped) swap(lx,ly);
    cout<<lx<<" "<<ly<<" "<<r<<'\n';
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


