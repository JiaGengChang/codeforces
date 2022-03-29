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
typedef pair<int,int> ii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> llll;
template<class T> bool ckmin(T& a,const T& b) {return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a,const T& b) {return b>a?a=b,1:0;}

bool issuf(string suf, string s) {
    return (suf==s.substr(sz(s)-sz(suf),sz(suf)));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    fastio;
    int n; cin>>n;
    map<string,set<string>> friends;
    F(i,0,n) {
        string name; int k; 
        cin>>name>>k;
        F(rep,0,k) {
            string number;
            cin>>number; 
            if(friends[name].count(number)==0) friends[name].ins(number);
        }
    }
    cout<<sz(friends)<<'\n';
    FI(person,friends) {
        vector<string> numbers; 
        copy(all(person->s),bkin(numbers));
        vector<bool> isrepeated(sz(numbers),false);
        F(i,0,sz(numbers)) 
            F(j,0,sz(numbers)) 
                if (sz(numbers[i])<sz(numbers[j]) && issuf(numbers[i],numbers[j])) isrepeated[i]=true;
        cout<<person->f<<" "<<count(all(isrepeated),false)<<" ";
        F(i,0,sz(numbers)) if(!isrepeated[i]) cout<<numbers[i]<<" ";
        cout<<'\n';
    }
    return 0;
}


