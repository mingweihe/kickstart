#include <bits/stdc++.h>

using namespace std;

const int maxn = 30;
int r, c;
string s[maxn], ans;
unordered_set<int> adj[26];
bool bad;
bool vis[26], act[26];

void dfs(int u){
    vis[u] = act[u] = true;
    for(int v: adj[u]){
        if(act[v] && u ^ v){
            bad = true;
        }else{
            if(!vis[v]) dfs(v); 
        }
    }
    act[u] = false;
    ans += (char) ('A' + u);
}

void solve(){
    cin >> r >> c;
    unordered_set<char> t;
    for(int i = 0; i < r; ++i){
        cin >> s[i];
        for(char ch: s[i])
            t.insert(ch);
        if(i == 0) continue;
        for(int j = 0; j < c; ++j)
            adj[s[i-1][j]-'A'].insert(s[i][j]-'A');
    }
    memset(vis, 0, 26);
    memset(act, 0, 26);
    ans = "", bad = false;
    for(char ch: t){
        int u = ch - 'A';
        if(vis[u]) continue;
        dfs(u);
    }
    if(bad) ans = "-1";
    cout << ans << '\n';
    for(int i = 0; i < 26; ++i)
        adj[i].clear();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, i = 1;
    cin >> t;
    while(t--){
        cout << "Case #" << i++ << ": ";
        solve();
    }
}
