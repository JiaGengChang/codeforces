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
    int n;
    cin>>n;
    vi a(n);
    vector<bool> used(n,false);
    int negcnt=0,zerocnt=0,izero=-1,delcnt=0;
    F(i,0,n) {
        cin>>a[i];
        if(a[i]<0) ++negcnt;
        if(a[i]==0) {
            ++zerocnt; 
            izero=izero==-1?i:izero;
        }
    }
    //multiply odd neg value into the first 0
    if (negcnt&1) { 
        int maxneg=-MOD, imaxneg=-1;
        F(i,0,n) {
            if (a[i]<0){
                if(ckmax(maxneg, a[i])) imaxneg=i;
            }
        }
        if(zerocnt==0){
            cout<<"2 "<<(1+imaxneg)<<'\n';
        } else {
            cout<<"1 "<<(1+imaxneg)<<" "<<(1+izero)<<"\n";
        }
        used[imaxneg]=true;
        ++delcnt;
    }

    //gather all 0s into a single slot
    int i,jlast=-1;
    while (zerocnt>1) {
        i=0; 
        jlast=-1;
        while(i<n-1){
            if(a[i]!=0) {
                ++i;
                continue;
            }
            int j=i+1;
            while(j<n && a[j]!=0)++j;
            if(j>=n) break;
            cout<<"1 "<<(1+i)<<" "<<(1+j)<<'\n';
            used[i]=true;
            jlast=j;
            ++i;
            ++delcnt;
            --zerocnt;
        }
    }
    //delete the last 0
    if (delcnt<n-1 && zerocnt==1){
        if(jlast==-1) {
            jlast = izero;
        }
        cout<<"2 "<<(1+jlast)<<'\n';
        used[jlast]=true;
    }

    //gather remaining numbers
    i=0;
    while(i<n-1) {
        if(used[i]) {
            ++i;
            continue;
        }
        int j=i+1;
        while(j<n && used[j])++j;
        if(j>=n) break;
        cout<<"1 "<<(1+i)<<" "<<(1+j)<<'\n';
        used[i]=true;
        ++i;
    }
    return 0;
}


