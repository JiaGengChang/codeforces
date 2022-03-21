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
	int n; cin >> n;
	if (n % 7==0){
		cout << n << endl;
	} else {
		int a = n + (7 - n%7);
		int b = n - n%7;
		if (floor(log10(a)) == floor(log10(b))) {
			int na = 0;
			int nb = 0;
			// check first digits
			if (floor(a/100)==floor(n/100)) na+=1;
			if (floor((a%100)/10)==floor((n%100)/10)) na+=1;
			if (floor(a%10)==floor(n%10)) na+=1;

			// check second digits
			if (floor(b/100)==floor(n/100)) nb+=1;
			if (floor((b%100)/10)==floor((n%100)/10)) nb+=1;
			if (floor(b%10)==floor(n%10)) nb+=1;

			if (na > nb) {
				cout << a;
			} else {
				cout << b;
			}

		} else {
			if (floor(log10(a))==floor(log10(n))){
				cout << a;
			} else {
				cout << b;
			}
		}
		cout << endl;
	}
}