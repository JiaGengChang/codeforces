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
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MOD 1000000007
#define PI 3.1415926535897932384626
#define MX 100001
#define printA(a,L,R) F(i,L,R) cout << a[i] << (i==R-1?'\n':' ')
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

struct unit{
    ll d,h;
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    FASTIO;
    int n,m,C;
    cin>>n>>C;
    const int mxC = 1000000;
    vector<vector<unit>> units(mxC+1);
    F(i,0,n) {
        int c,d,h;
        cin>>c>>d>>h;
        units[c].pb({d,h});
    }
    
    //compute max d*h for cost c from 1 to 10^6
    vll maxDH(mxC+1,0);
    F(c,1,mxC+1){
        if (sz(units[c])){
            unit u = *mxel(ALL(units[c]),[C](auto a,auto b){return a.d*a.h < b.d*b.h;});
            for(int n=1; n*c<=mxC; ++n){
                ckmax(maxDH[n*c],ll(n)*u.d*u.h);
            }
        }
    }
    F(i,1,mxC+1) maxDH[i] = max(maxDH[i-1],maxDH[i]);

    cin>>m;
    F(j,0,m){
        ll dj, hj;
        cin >> dj >> hj;
        if(maxDH[C] <= dj*hj){
            cout<<"-1\n";
            continue;
        }
        int l=0; //bad
        int r=C; //good
        while(r-l>1){
            int m=(l+r)/2;
            if (maxDH[m] > dj*hj){
                r=m;
            } else {
                l=m;
            }
        }
        cout<<r<<'\n';
    }
    return 0;
}


