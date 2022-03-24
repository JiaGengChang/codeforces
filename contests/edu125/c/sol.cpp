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
    int t, n; 
    cin>>t;
    while(t--){
        cin>>n;
        string a;
        cin>>a;
        int op=0;//number of operations
        int i=0, j=-1;
        bool flag=false;//found a solitary ')'
        while(i<n){
            if (i==n-1){
                if(!flag){
                    flag=true;
                    j=n-1;
                } else {
                    if (a[i]==')'){
                        flag=false;
                        ++op;
                    }
                }
                break;
            }
            if (!flag) {
                if(a[i]==')' && a[i+1]=='('){
                    // )( is not okay
                    flag=true;
                    j = i;
                    debug(t, j);
                    i += 2;
                } else {
                    // )), (), (( are all okay
                    ++op;
                    i += 2;
                }
            } else {
                if(a[i]==')'){
                    flag=false;
                    ++i;
                    ++op;
                } else {
                    ++i;
                }
            }
        }
        if(flag){
            cout<<op<<" "<<(n-j)<<'\n';
        } else {
            cout<<op<<" 0\n";
        }
    }
    return 0;
}


