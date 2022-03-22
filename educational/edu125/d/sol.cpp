#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "../../debug.h"
#else 
#define debug(x...)
#endif
#define sz(x) ((int)((x).size()))
#define F(i,L,R) for (int i = L; i < R; i++) 
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define ALL(c) (c).begin(),(c).end() 
#define RALL(c) (c).rbegin(),(c).rend() 
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define IOS ios_base::sync_with_stdio(0)
#define MOD 1000000007
#define PI 3.1415926535897932384626
#define MX 100001
#define printA(a,L,R) F(i,L,R) cout << a[i] << (i==R-1?'\n':' ')
#define f first
#define s second
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define pb push_back
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

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    IOS;
    cin.tie(0); 
    cout.tie(0);
    //solve
    int n,m;
    ll C;
    cin>>n>>C;
    vector<vector<double>> units(n, vector<double>(4));
    F(i,0,n) {
        cin>>units[i][0]>>units[i][1]>>units[i][2];
        // ci / (di*hi)
        units[i][3] = units[i][0]/(units[i][1]*units[i][2]);
    }
    sort(ALL(units), [](auto u1, auto u2){return u1[3] < u2[3];});

    F(i,0,n) {
        debug(units[i]);
    }
    cin>>m;
    F(j,0,m){
        double dj, hj;
        cin >> dj >> hj;
        ll cmin=1e18;
        F(i,0,n) {
            ll ci = ceil(hj*dj*units[i][3]);
            ckmin(cmin,ci);
        }
        if (cmin > C) {
            cout<<"-1\n";
        } else {
            cout<<cmin<<'\n';
        }
    }
    return 0;
}


