#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

//solution with bitset not working 

const int mxV = 40;
typedef bitset<mxV> node;
node empty_b;

struct segtree{
  int sz;
  vector<node> vals;
  segtree(vector<int>& a){
    sz=1; while(sz<a.size()) sz*=2; 
    vals.assign(2*sz-1,empty_b);
    build(a, 0, 0, sz);
  }
  node merge(node x, node y){
    return x|y;
  }
  void build(vector<int> &a, int x, int lx, int rx){
    if (rx-lx==1) {
      if (lx<a.size()) vals[x] |= (1<<a[lx]);
      return;
    }
    int m = (lx+rx)/2;
    build(a, 2*x+1, lx, m);
    build(a, 2*x+2, m, rx);
    vals[x] = merge(vals[2*x+1], vals[2*x+2]);
  }
  void set(int i, int v, int x, int lx, int rx){
    if (rx-lx==1) {
      vals[x] = empty_b;
      vals[x] |= (1<<(v-1));
      return;
    }
    int m = (lx+rx)/2;
    if (i<m)
      set(i, v, 2*x+1, lx, m);
    else
      set(i, v, 2*x+2, m, rx);
    vals[x] = merge(vals[2*x+1], vals[2*x+2]);
  }
  node get(int l, int r, int x, int lx, int rx){
    if (lx >= l && rx <= r) return vals[x];
    if (lx >= r || rx <= l) return empty_b;
    int m = (lx+rx)/2;
    node a = get(l, r, 2*x+1, lx, m);
    node b = get(l, r, 2*x+2, m, rx);
    return merge(a, b);
  }
};

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt","w", stderr);
#endif

  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n,q; cin >> n >> q;
  vector<int> a(n);	for (int& u:a) {cin >> u; --u;}
  debug(a);
  segtree st(a);
  int t,x,y;
  while(q--){
    cin >> t >> x >> y;
    --x;
    debug(t,x,y);
    if (t&1){
      node z = st.get(x,y,0,0,st.sz);
      for (int i=0; i<mxV; ++i){
        int bit=z[i]?1:0;
        cerr << bit << ' ';
      } cerr << endl;
      cout << z.count() << '\n';
    } else {
      st.set(x,y,0,0,st.sz);
      node z = st.get(0,n,0,0,st.sz);
      for (int i=0; i<mxV; ++i){
        int bit=z[i]?1:0;
        cerr << bit << ' ';
      } cerr << endl;
    }
  }
}


