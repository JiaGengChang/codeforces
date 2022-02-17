#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<pair<vector<int>,int>> p(n);
        for (int i=0; i<n; ++i) p[i] = {times[i],i};
        sort(p.begin(), p.end(), [&](auto a, auto b){
            return a.first[0] < b.first[0];
        });
        vector<int> s(n), e(n), o(n), ans(n);
        for (int i=0; i<n; ++i) {
            s[i] = (p[i].first)[0];
            e[i] = (p[i].first)[1];
            o[i] = p[i].second;
        }

		for (int i=0; i<n; ++i){
			cout << o[i] << ' ' << s[i] << ' ' << e[i] << '\n';
		}
        
        vector<pair<int,int>> tev; //taken
		ans[0] = 0;
		tev.push_back({e[0], ans[0]});
        for (int i=1; i<n; ++i){
			sort(tev.begin(), tev.end(), [&](auto a, auto b){return a.second < b.second;});
            auto j = find_if(tev.begin(), tev.end(), [&](auto p){return s[i] >= p.first;});
            if (j != tev.end()){
                ans[i] = (*j).second;
				auto it = remove_if(tev.begin(), tev.end(), [&](auto p){return s[i] >= p.first;});
				tev.erase(it, tev.end());
            } else {
				vector<int> av;
				for (auto& u:tev){
					av.push_back(u.second);	
				}
				sort(av.begin(), av.end());
				int mex=0;
				for (auto u:av) if (u==mex) ++mex;
				ans[i] = mex;
			}
			tev.push_back({e[i], ans[i]});
        }

		for (auto u:ans) cout << u << ' '; cout << '\n';
		
		return ans[find(o.begin(), o.end(), targetFriend) - o.begin()];
		        
    }
};

void solve() {
	int n; cin >> n;
	vector<vector<int>> times(n, vector<int>(2));
	for (int i=0; i<n; ++i){
		int a, b;
		cin >> a >> b;
		times[i][0] = a;
		times[i][1] = b;
	}
	int targetFriend;
	cin >> targetFriend;
   	Solution s;
	int ans = s.smallestChair(times, targetFriend);
	cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        //cout << "Case #" << t << ": ";
        solve();
    }
}

