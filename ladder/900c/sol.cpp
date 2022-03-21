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
    int n; cin>>n;
    int a[n];
    F(i,0,n){
        cin>>a[i];
    }
    int cnt[n];
    int cmax=-1;
    F(i,0,n){
        if(ckmax(cmax,a[i])){
            cnt[a[i]-1]=-1;
        } else {
            cnt[a[i]-1]=0;
        }
    }
    F(i,0,n) cerr<<cnt[a[i]-1]<<" "; cerr<<'\n';
    int max2[n][2];
    F(i,0,n) max2[i][0]=max2[i][1]=-1;
    max2[1][0] = a[0];
    F(i,2,n) {
        if (a[i-1]>max2[i-1][0]){
            max2[i][0] = a[i-1];
            max2[i][1] = max2[i-1][0];
            continue;
        }
        if (a[i-1]>max2[i-1][1]){
            max2[i][0] = max2[i-1][0];
            max2[i][1] = a[i-1];
            continue;
        }
        max2[i][0] = max2[i-1][0];
        max2[i][1] = max2[i-1][1];
    }
    F(i,0,n){
        debug(max2[i][0],max2[i][1]);
    }
    F(j,1,n) {
        if(max2[j][1]<a[j] && a[j]<max2[j][0]){
            ++cnt[max2[j][0]-1];
        }
    }
    F(i,0,n) cerr<<cnt[a[i]-1]<<" "; cerr<<'\n';
    int x=0;
    F(i,1,n){
        if (cnt[a[i]-1] > cnt[a[x]-1]) {
            x=i;
            continue;
        } 
        if (cnt[a[i]-1] == cnt[a[x]-1]) {
            if (a[i]<a[x]) x=i;
        }
    }
    cout<<a[x]<<'\n';
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    cin.tie(0); 
    cout.tie(0);
    solve();
    return 0;
}


