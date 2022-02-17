#include <bits/stdc++.h>

using namespace std;


void solve() {
   int n; cin >> n;
   vector<int> a(n); 
   vector<vector<int>> g(n);
   for (auto& u:a) cin >> u;
   for (int i=0; i<n; ++i){
	   for (int j=i; j<n; ++j){
		   if (a[i] > a[j]){
			   g[i].push_back(j);
			   g[j].push_back(i);
		   }
	   }
   }
   vector<bool> vis(n, false);
   queue<int> que;
   int ans = 0;
   for (int i = 0; i<n; ++i){
	   if (!vis[i]){
		   int p = -1;
		   que.push(i); 
		   vis[i] = true;   
		   while (size(que) != 0){
			   int v = que.front();
			   que.pop();
			   vis[v] = true;
			   p = v;
			   for (auto u:g[v]) if (u != p) {
				   if (!vis[u]){
					   que.push(u);
				   }
			   }
		   }
		   ++ans;
	   }
   }
   cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}

