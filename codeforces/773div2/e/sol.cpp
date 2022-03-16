#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "/home/Jia_Geng/cp/debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

#define INF (2e9)
 
const int sz = (1 << 18);
 
struct st {
    vector<int> data;
    
    st() {
        data.resize(sz * 2, INF);
    }
    
    void set(int id, int val) {
        data[id + sz] = val;
        for (int i = (id + sz) / 2; i > 0; i /= 2) data[i] = min(data[i * 2], data[i * 2 + 1]);
    }
    
    int get(int l, int r, int ld = 0, int rd = sz, int id = 1) {
        if (l >= rd || r <= ld) return INF;
        if (l <= ld && rd <= r) return data[id];
        return min(get(l, r, ld, (ld + rd) / 2, id * 2), get(l, r, (ld + rd) / 2, rd, id * 2 + 1));
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif

    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,t; cin >> n >> q;
    st kk;
    set<int> ods;
    for(int i=0;i<n;++i) ods.insert(i);
    while(q--){
        cin>>t;
        if(t==0){
            int l,r,x;
            cin>>l>>r>>x;
            --l;
            if (x==0){
                for(auto cur = ods.lower_bound(l); cur != ods.end() && *cur < r;){
                    int curval=*cur;
                    ods.erase(curval);
                    cur = ods.upper_bound(curval);
                }
            } else kk.set(l, min(kk.data[l+sz],r));
        } else {
            int id;
            cin>>id;
            --id;
            if(!ods.count(id)) {cout << "NO\n";continue;}
            int l=0,r=n;
            if(ods.size()){
                auto it = ods.lower_bound(id);
                if (it != ods.begin()) l = *prev(it)+1;
                ++it;
                if (it != ods.end()) r = *it;
            }
            cout << (kk.get(l,n) <= r ? "YES" : "N/A") << "\n";
        }
    }
    return 0;
}
