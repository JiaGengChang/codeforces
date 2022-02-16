#include <bits/stdc++.h>

using namespace std;

/*number of triangles in an undirected graph solved using bitsets as adjacency lists*/

void solve(){
	vector<bitset<2000>> g(2000);
	int n,m; cin>>n>>m;
	for (int i=0; i<m; ++i){
		int u, v;
		cin>>u>>v;
		--u;--v;
		g[u][v] = g[v][u] = 1;
	}
	int ans=0;
	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			//if i & j are adjacent
			//compute the number of nodes that are adjacent to i&j
			if (g[i][j] && i!=j){
				bitset<2000> third = g[i] & g[j];
				ans += third.count();
			}
		}
	}
	ans/=6;
	cout << ans << '\n';
}

int main(){
		
	//code goes here
	cout << "hello world\n";
	solve();

	return 0;
}

