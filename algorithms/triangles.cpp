#include <bits/stdc++.h>

//number of triangles in an undirected graph

using namespace std;

void solve(){
	/*num vertices <= 2000*/

	//A, A^2 and A^3
	int A[2000][2000];
	int B[2000][2000];
	int C[2000][2000];

	int n, m; cin >> n >> m;

	// initialize
	for (int i=0; i<2000; ++i){
		for (int j=0; j<2000; ++j){
			A[i][j] = B[i][j] = C[i][j] = 0;
		}
	}

	//build adjacency matrix
	for (int i=0; i<m; ++i){
		int u, v; 
		cin >> u >> v;
		--u; --v;
		A[u][v] = A[v][u] = 1;
	}

	//compute A^2 and A^3
	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			for (int k=0; k<n; ++k){
				B[i][j] += A[i][k] * A[k][j];
			}
		}
	}
	for (int i=0; i<n; ++i){
		for (int j=0; j<n; ++j){
			for (int k=0; k<n; ++k){
				C[i][j] += B[i][k] * B[k][j];
			}
		}
	}

	//ans = trace of A^3 divided by 6
	int ans=0;
	for (int i=0; i<n; ++i)
		ans += C[i][i];
	
	ans/=6;
	cout << ans << '\n';
}

int main(){
		
	return 0;
}

