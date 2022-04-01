#include <iostream>

using namespace std;

#define F(i,L,R) for (int i = L; i < R; i++) 

int main() {
    const int N=3001,inf=(int)1e9;
    int n, s[N], c[N]; scanf("%d",&n); 
    F(i,0,n) scanf("%d",&s[i]);
    F(i,0,n) scanf("%d",&c[i]);
    int ans=inf;
    F(j,1,n-1) {
        int ci=inf,ck=inf;
        F(i,0,j) { if (s[i]<s[j]) ci=min(ci,c[i]); }
        if(ci==inf) continue;
        F(k,j+1,n) { if (s[j]<s[k]) ck=min(ck,c[k]); }
        if(ck==inf) continue;
        ans=min(ans,ci+c[j]+ck);
    }
    cout<<(ans==inf?-1:ans); 
    return 0;
}
