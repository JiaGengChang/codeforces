#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);   
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    int A = *std::max_element(a.begin(),a.end());
    int c=0;
    for (int i=0; i<A; ++i) {
        
    }

    return 0;
}
