#include <bits/stdc++.h>

using namespace std;

void solve() {
   int n; cin >> n;
   vector<int> a(n);
   for (auto& aa:a) cin >> aa;
   int ans=0;
   for (auto aa:a) ans |= aa;
   cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}

