#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "../../debug.h"
#else 
#define debug(x...)
#endif

using namespace std;

#define sz(x) ((int)((x).size()))
#define mt(x) ((x).empty())
#define FI(it,x) for (auto it=(x).begin(); it!=(x).end(); ++it)
#define F(i,L,R) for (int i = L; i < R; i++) 
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define pb push_back
#define ppb pop_back
#define f first
#define s second

inline bool isvowel(char c){
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt","w", stderr);
#endif
    fastio;

    int n;
    cin>>n;
    vector<string> keys(n);
    map<int,map<char,vector<int>>> maps;
    F(i,0,n){
        string word;
        cin>>word;
        keys[i]=word;
        int vowelcnt = 0;
        char lastvowel = '$';
        FFE(i,sz(word)-1,0){
            if (isvowel(word[i])){
                ++vowelcnt;
                if(lastvowel=='$') lastvowel=word[i];
            }
        }
        maps[vowelcnt][lastvowel].pb(i);
    }
    vector<pair<int,int>> duos[2];
    FI(samecnt, maps){
        FI(samevowel,samecnt->s){
            char vowel = samevowel->f;
            if (vowel=='$') continue;
            auto& words = samevowel->s;
            while(sz(words)>1){
                int n=sz(words);
                duos[0].pb({words[n-1],words[n-2]});
                words.ppb();
                words.ppb();
            }
            if(sz(words)) (samecnt->s)['$'].pb(words[0]);
        }
        auto& words = (samecnt->s)['$'];
        while(sz(words)>1){
            int n=sz(words);
            duos[1].pb({words[n-1],words[n-2]});
            words.ppb();
            words.ppb();
        }
    }
    int nc = sz(duos[0]);
    int ns = sz(duos[1]);
    vector<vector<string>> lyrics;
    while(ns>0 && nc>0){
        lyrics.pb({keys[duos[1][ns-1].f],keys[duos[0][nc-1].f],keys[duos[1][ns-1].s],keys[duos[0][nc-1].s]});
        ns--; nc--;
    }
    while(nc>1){
        lyrics.pb({keys[duos[0][nc-1].f],keys[duos[0][nc-2].f],keys[duos[0][nc-1].s],keys[duos[0][nc-2].s]});
        nc -= 2;
    }
    cout<<sz(lyrics)<<'\n';
    for(auto lyric : lyrics) {
        cout<<lyric[0]<<" "<<lyric[1]<<'\n';
        cout<<lyric[2]<<" "<<lyric[3]<<'\n';
    }
    return 0;
}


