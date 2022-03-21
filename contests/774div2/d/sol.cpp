#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

const int maxn=200005;
vector<int> g[maxn];
bool vis[maxn];
int pa[maxn];

pair<int,int>dp[maxn][2];//dp(x,b) stores the (g,s) where g is the maximum size of independent set of good nodes and s is the sum of weights

//parent of node i is pa[i]
void dfs(int v){
    vis[v]=1;
    for(auto i : g[v]){
        if (!vis[i]){
            pa[i]=v;
            dfs(i);
        }
    }
}

//calculates max g, min s where g is the size of the independent set of good vertices and s is the sum of weights of the graph
//x = vertex label
//y = 1 good or 0 bad
pair<int,int> f(int x,int y){
    pair<int,int> & res = dp[x][y];
    if(res.first>=0) return res;
    res = {y, y ? -((int)g[x].size()) : -1};
    for(auto i:g[x]){
        if(i!=pa[x]){
            pair<int,int> maxi = f(i,0);
            //s is negative so minimum turns into maximum
            if(y==0) maxi = max(maxi,f(i,1));
            res.first += maxi.first;
            res.second += maxi.second;
        }
    }
    return res;
}

vector<bool> is_good;

//find is_good for each vertex v
void build(pair<int,int>value,int v){
    if(value==f(v,0)){
        is_good[v]=false;
        for(auto i:g[v]){
            if(i!=pa[v]){
                build(max(f(i,0),f(i,1)),i);
            }
        }
    } else {
        //v is good
        is_good[v]=true;
        for(auto i:g[v]){
            if(i!=pa[v]){
                build(f(i,0),i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
    auto start=chrono::high_resolution_clock::now();
#endif
    int n;cin>>n;
    for(int i=0;i<n-1;++i){
        int u,v;
        cin >> u >> v;--u;--v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n==2){
        cout << "2 2\n1 1\n";
        return 0;
    }

    //find parent of each vertex 
    pa[0]==-1;
    dfs(0);
    
    //initialize g,s for all x,b
    for (int x=0;x<n;++x) dp[x][0]={-1,-1},dp[x][1]={-1,-1};
    
    //top down dp to find max number of good vertices,g, and min sum of weights, s
    pair<int,int>res = max(f(0,0),f(0,1));

    //output g and s
    cout<<res.first<<' '<<-res.second<<'\n';

    //recursively assign good (1) or bad (0) to each vertex
    is_good.resize(n);
    //start from vertex 0 (arbitrarily determined root)
    build(res,0);

    //output weight of each vertex
    for(int i=0;i<n;++i){
        if(is_good[i]) cout<<g[i].size()<<" ";
        else cout<<"1 ";
    }
    cout << '\n';

#ifndef ONLINE_JUDGE
    auto stop=chrono::high_resolution_clock::now();
    auto duration=chrono::duration_cast<chrono::microseconds>(stop-start);
    cerr << duration.count() << "ms\n";
#endif
    return 0;
}


