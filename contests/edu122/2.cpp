#include <bits/stdc++.h>
using namespace std;


void solve_case();

int main() {
	std::ios::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);
	int tt=1;
	cin >> tt;
	while (tt--) {
		solve_case();
	}
	return 0;
}

void solve_case() {
	string s; cin >> s;
	int n = s.length();
	vector<pair<int,int>> ans(n+1);
	ans.push_back({0,0});
	for (int i = 0; i < n; ++i){
		if (s[i]=='0'){
			ans[i+1] = {ans[i].first + 1, ans[i].second};
		} else {
			ans[i+1] = {ans[i].first, ans[i].second + 1};
		}
	}
	int max_min = -1;
	for (auto pr : ans){
		if (pr.first != pr.second){
			max_min = max(max_min, min(pr.first, pr.second));
		}
	}
	cout << max_min << endl;
}