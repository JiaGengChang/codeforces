#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
	unsigned int n, k; cin >> n >> k;

	auto c = [&] (unsigned int x) {
		return x ^ (n-1);
	};

	if (k==n-1){
		if (n==4){
			cout << -1 << '\n';
			return;
		}
		//n >= 8
		cout << 0 << " " << 2 << '\n';
		cout << 1 << " " << n-3 << '\n';
		cout << n-1 << " " << n-2 << '\n';
		for (unsigned int x=3; x<n-3; ++x){
			if (x < n/2)
				cout << x << " " << c(x) << '\n';
		}
		return;
	}
	if (k==0){
		for (unsigned int x=0; x<n/2; ++x) 
			cout << x << " " << c(x) << '\n';
		return;
	}
	if (0<k && k<n-1){
		cout << k << " " << n-1 << '\n';
		cout << 0 << " " << c(k) << '\n';
		for (unsigned int x=1; x<n-1; ++x){
			if (x != k && x!=c(k) && x < n/2)
				cout << x << " " << c(x) << '\n';
		}
		return;
	} else {
		return;
	}
	
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

