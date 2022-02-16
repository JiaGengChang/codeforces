#include <bits/stdc++.h>

using namespace std;

int solve(){
    int n, m;
    cin >> n >> m;
    int a[n*m-1];
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            a[i*m+j] = max(i+j, max(i+m-j-1, max(n-i-1+j, n-i+m-j-2)));
        }
    }
    sort(a, a+n*m-1);
    for (int i=0; i<n*m; ++i){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

int main () {

    int t;
    cin >> t;
    while (t--){
        if (solve()){
            break;
        }
    }
    return 0;
}