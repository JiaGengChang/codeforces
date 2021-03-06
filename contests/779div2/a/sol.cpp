#include <bits/stdc++.h>
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
#define present(c,x) ((c).find(x,0) != string::npos)
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
    fastio;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string s;
        cin>>s;
        if(n==1) {
            cout<<0<<'\n';
            continue;
        }
        if(n==2) {
            cout<<(s=="00"?2:0)<<'\n';
            continue;
        }
        int ans=count(all(s),'1');
        while(true){
            if (present(s,"000")) {
                s.replace(s.find("000",0),3,"0110110");
                continue;
            }
            if (present(s,"001")) {
                s.replace(s.find("001",0),3,"01101");
                continue;
            }
            if (present(s,"010")) {
                s.replace(s.find("010",0),3,"0110");
                continue;
            }
            if (present(s,"100")) {
                s.replace(s.find("100",0),3,"10110");
                continue;
            }
            break;
        }
        cout<<count(all(s),'1')-ans<<'\n';
        //cout<<s<<'\n';
    }
    return 0;
}


