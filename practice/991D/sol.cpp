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
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
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
#define eb emplace_back
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
    string top,bot;
    cin>>top>>bot;
    int i=0,cnt=0;
    while(i<sz(top)-1){
        string cur;
        cur+=top[i];
        cur+=top[i+1];
        cur+=bot[i];
        cur+=bot[i+1];
        debug(i,cur,cnt);
        if(cur=="0000") {
            ++cnt; 
            top[i+1]=bot[i+1]='Y';
            ++i;
            continue;
        }
        if (cur=="Y0Y0"||
            cur=="0X00"||
            cur=="000X"||
            cur=="00X0"||
            cur=="X000"){
            ++cnt;
            i+=2;
            continue;
        }
        if (cur=="0X0X"||
            cur=="XXXX"||
            cur=="XX0X"||
            cur=="0XXX"||
            cur=="YXYX") {
            i+=2;
            continue;
        }
        if (cur=="XX00"||
            cur=="00XX"||
            cur=="0XX0"||
            cur=="X00X"||
            cur=="XXX0"||
            cur=="X0XX"||
            cur=="Y0YX"||
            cur=="YXY0"){
            ++i;
            continue;
        }
        ++i;
    }
    cout<<cnt;

    return 0;
}


