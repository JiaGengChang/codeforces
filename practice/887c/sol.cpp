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

bool eql(vi& v, int a1, int a2, int a3, int a4){
    return (v[a1]==v[a2]) && (v[a2]==v[a3]) && (v[a3]==v[a4]);
}
bool same_front(vi& v){ return eql(v,9,10,11,12); }
bool same_back(vi& v){ return eql(v,1,2,3,4); }
bool same_top(vi& v){ return eql(v,5,6,7,8); }
bool same_down(vi& v){ return eql(v,21,22,23,24); }
bool same_left(vi& v){ return eql(v,13,14,15,16); }
bool same_right(vi& v){ return eql(v,17,18,19,20); }
bool same_all(vi& v){ 
    return same_front(v) && same_back(v) && same_top(v) && same_down(v) && same_left(v) && same_right(v);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    fastio;
    vi v(24,-1);
    F(i,1,25) cin>>v[i];
    //check if already solved
    /*
     *if (same_all(v)){
     *    cout<<"YES\n";
     *    return 0;
     *}
     */
    bool found=false;
    //check U clockwise
    if (same_top(v) && same_down(v)){
        if ((eql(v,1,2,17,19) && eql(v,3,4,13,15) && eql(v,9,10,18,20) && eql(v,11,12,14,16)) || 
            (eql(v,1,2,14,16) && eql(v,3,4,18,20) && eql(v,11,12,17,19) && eql(v,9,10,13,15))) {
            found=true;
        }
    }
    if (same_left(v) && same_right(v)){
        if ((eql(v,1,3,6,8) && eql(v,2,4,22,24) && eql(v,5,7,10,12) && eql(v,9,11,21,23)) || 
            (eql(v,2,4,5,7) && eql(v,1,3,21,23) && eql(v,6,8,9,11) && eql(v,10,12,22,24))) {
            found=true;
        }
    }
    if (same_front(v) && same_back(v)) {
        if ((eql(v,13,14,7,8) && eql(v,15,16,21,22) && eql(v,17,18,23,24) && eql(v,5,6,19,20)) || 
            (eql(v,13,14,23,24) && eql(v,5,6,15,16) && eql(v,17,18,7,8) && eql(v,21,22,19,20))) {
            found=true;
        }
    }
    debug(same_top(v));
    debug(same_back(v));
    debug(same_front(v));
    debug(same_back(v));
    debug(same_left(v));
    debug(same_right(v));
    if (found) cout<<"YES\n"; else cout<<"NO\n";

    return 0;
}


