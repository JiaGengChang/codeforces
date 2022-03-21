#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

const int mxV = 40;

struct node{
  long long c;
  vector<int> freq;
};
struct segtree{
  int sz;
  vector<node> vals;
  segtree(vector<int>& a){
    sz=1; while(sz<a.size()) sz*=2; 
    vals.assign(2*sz-1,{0, vector<int>(mxV,0)});
    build(a, 0, 0, sz);
  }
  void build(vector<int> &a, int x, int lx, int rx){
    if (rx-lx==1) {
      if (lx<a.size()) vals[x].freq[a[lx]]++;
      return;
    }
    int m = (lx+rx)/2;
    build(a, 2*x+1, lx, m);
    build(a, 2*x+2, m, rx);
    vals[x] = merge(vals[2*x+1], vals[2*x+2]);
  }
  node merge(node x, node y){
    long long c = x.c + y.c;
    vector<int> freq(mxV);
    for (int i=0; i<mxV; ++i) {
      for (int j=i+1; j<mxV; ++j)
          c += x.freq[j]*y.freq[i];
    }
    for (int i=0; i<mxV; ++i) freq[i] = x.freq[i] + y.freq[i];
    return {c, freq};
  }
  void set(int i, int v, int x, int lx, int rx){
    if (rx-lx==1) {
      vals[x].freq.assign(mxV,0);
      vals[x].freq[v-1] ++;
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
    if (lx >= r || rx <= l) return {0, vector<int>(mxV, 0)};
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
  segtree st(a);
  //debug(a);
  //for (int i=0; i<2*st.sz-1; ++i){
    //debug(i, st.vals[i].c);
  //}
  int t,x,y;
  while(q--){
    cin >> t >> x >> y;
    --x;
    debug(t,x,y);
    if (t&1){
      node ans = st.get(x,y,0,0,st.sz);
      //debug(ans.c, ans.freq);
      cout << ans.c << '\n';
    } else {
      st.set(x,y,0,0,st.sz);
      //for (int i=0; i<2*st.sz-1; ++i){
        //debug(i, st.vals[i].freq);
      //}
    }
  }
}


