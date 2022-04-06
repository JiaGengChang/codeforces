#include "bits/stdc++.h"
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
typedef set<int> si;
typedef pair<int,int> ii;
typedef set<pair<int,int>> sii;
typedef vector<pair<int,int>> vii;
typedef vector<bool> vb;
template<class T> bool ckmin(T& a,const T& b) {return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a,const T& b) {return b>a?a=b,1:0;}
template<class T> bool ckval(T& a,const T& b) {return a<0?a=b,1:0;}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    fastio;
    int n; cin>>n;
    string s,t; cin>>s>>t;
    vii ops;
    int prev_ab=-1,prev_ba=-1;
    //fix aabb and bbaa
    F(i,0,n){
        if (s[i]!=t[i]){
            if (s[i]=='a') {
                if (prev_ab==-1) prev_ab=i;
                else {
                    swap(s[prev_ab],t[i]);
                    ops.pb({prev_ab+1,i+1});
                    prev_ab=-1;
                }
            } else {
                if (prev_ba==-1) prev_ba=i;
                else {
                    swap(s[prev_ba],t[i]);
                    ops.pb({prev_ba+1,i+1});
                    prev_ba=-1;
                }
            }
        }
    }
    //fix abba and baab
    if ((prev_ab==-1&&prev_ba>=0) || (prev_ab>=0&&prev_ba==-1)) {
        cout<<"-1\n";
    } else {
        if (!(prev_ab==-1 && prev_ba==-1)) {
            ops.pb({prev_ab+1,prev_ab+1});
            ops.pb({prev_ab+1,prev_ba+1});
        }
        cout<<sz(ops)<<"\n";
        for (ii e:ops) cout<<e.f<<" "<<e.s<<"\n";
    }
    return 0;
}

