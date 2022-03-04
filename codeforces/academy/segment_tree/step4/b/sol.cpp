#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

struct mtx{
  //a, b
  //c, d
  int a,b,c,d;
  mtx(int my_a, int my_b, int my_c, int my_d){
    a = my_a; 
    b = my_b;
    c = my_c;
    d = my_d;
  }
};

void prt(mtx m){
  cout << m.a << ' ' << m.b << '\n';
  cout << m.c << ' ' << m.d << '\n';
  cout << '\n';
  //cerr << "matrix: \n";
  //cerr << m.a << ' ' << m.b << '\n';
  //cerr << m.c << ' ' << m.d << '\n';
}
struct segtree{
  int sz, r;
  vector<mtx> vals;

  segtree(int n, int mr){
    r=mr;
    sz=1;
    while (sz < n) sz*=2;
    vals.assign(2*sz-1, mtx(1,0,0,1));
  }

  mtx merge(mtx A1, mtx A2){
    int a, b, c, d;
    a = (A1.a * A2.a) % r + (A1.b * A2.c) % r;
    b = (A1.a * A2.b) % r + (A1.b * A2.d) % r;
    c = (A1.c * A2.a) % r + (A1.d * A2.c) % r;
    d = (A1.c * A2.b) % r + (A1.d * A2.d) % r;
    return (mtx(a%r, b%r, c%r, d%r));
  }

  void build(vector<mtx>& v, int x, int l, int r){
    if (r-l==1){
      if (l < v.size()){
        vals[x] = v[l];
      }
      return;
    }
    int m = (l+r)/2;
    build(v, 2*x+1, l, m);
    build(v, 2*x+2, m, r);
    vals[x] = merge(vals[2*x+1],vals[2*x+2]);
  }
  void build(vector<mtx>& v){
    build(v, 0, 0, sz);
  }
  mtx get(int l, int r) {
    return get(l, r, 0, 0, sz);
  }
  mtx get(int l, int r, int x, int lx, int rx){
    if (lx >= r || rx <= l) return mtx(1,0,0,1);
    if (lx >= l && rx <= r) return vals[x];
    if (rx - lx == 1){
      return vals[x];
    }
    int m = (lx+rx)/2;
    mtx s1 = get(l, r, 2*x+1, lx, m);
    mtx s2 = get(l, r, 2*x+2, m, rx);
    return merge(s1,s2);
  }
};

void solve() {
	int mr,n, m; cin >> mr >> n >> m;
	vector<mtx> v;
	for (int i=0; i<n; ++i) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    v.push_back(mtx(a, b, c, d));
  }
  segtree st(n,mr); 
  st.build(v);
  //for(auto m:st.vals) prt(m);
  int l, r;
  while(m--) {
    cin >> l >> r;
    --l;
    debug(l,r);
    mtx ans = st.get(l, r);
    prt(ans);
  }
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt","w", stderr);
	#endif

  ios_base::sync_with_stdio(0);
  cin.tie(0); 
	cout.tie(0);
  solve();
}


