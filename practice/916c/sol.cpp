#include <bits/stdc++.h>
 
using namespace std;
 
bool isprime(int n){
    for(int i=2; i*i<=n; ++i){
        if(n%i==0)
            return false;
    }
    return true;
}
 
int nextprime(int n){
    int m=n;
    while(!isprime(m))++m;
    return m;
}
 
int main()
{
    int n,m; 
    cin>>n>>m;
    int p = nextprime(n);
    cout << p << " " << p << '\n';
    for(int u=1; u<=n-2; ++u){
        cout<<u<<" "<<(u+1)<<" 1\n";
    }
    cout<<n-1<<" "<<n<<" "<<(p-n+2)<<'\n';
    int cnt = m-n+1;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n-1; ++j){
            if (cnt==0) break;
            int u = i+1;
            int v = (i+j+2) % n + 1;
            if (u>=v) break;
            //if(u==v || u==v+1) continue;
            cout<<u<<" "<<v<<" "<<p+1<<'\n';
            --cnt;
        }
    }
    
    return 0;
}
