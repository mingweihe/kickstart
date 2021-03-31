#include <bits/stdc++.h>

using namespace std;

int r, c;
string s[30];
int indegrees[26];

void solve(){
    cin >> r >> c;
    memset(indegrees, 0, sizeof(indegrees));
    unordered_map<int, unordered_set<int>> graph;
    unordered_set<int> t;
    for(int i = 0; i < r; ++i){
        cin >> s[i];
        for(char ch: s[i]) t.insert(ch-'A');
        if(i == 0) continue;
        for(int j = 0; j < c; ++j){
            char p = s[i-1][j]-'A', cur = s[i][j]-'A';
            if(p == cur) continue;
            if(graph[cur].find(p)!= graph[cur].end()) continue;
            graph[cur].insert(p);
            indegrees[p]++;
        }
    }
    string ans = "";
    vector<int> heads;
    for(int u: t)
        if(!indegrees[u]) heads.push_back(u);

    while(!heads.empty()){
        int u = heads.back(); heads.pop_back();
        ans += 'A' + u;
        for(int v: graph[u]){
            indegrees[v]--;
            if(indegrees[v] == 0)
                heads.push_back(v);
        }
    }
    if(ans.size() != t.size()) ans = "-1";
    cout << ans << '\n';
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
