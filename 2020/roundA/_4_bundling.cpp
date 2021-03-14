#include <bits/stdc++.h>

using namespace std;
const int maxn = 2e6+1;

int n, k, ans;
int c[maxn][26], cnt[maxn];

void dfs(int u = 0, int d = 0){
    for(int v = 0; v < 26; ++v){
        if(!c[u][v]) continue;
        dfs(c[u][v], d+1);
        cnt[u] += cnt[c[u][v]];
    }
    while(cnt[u] >= k){
        cnt[u] -= k;
        ans += d;
    }
}

void solve(){
    cin >> n >> k;
    memset(c, 0, sizeof(c));
    memset(cnt, 0, sizeof(cnt));
    int m = 1;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        int u = 0;
        for(char v : s){
            if(!c[u][v-'A']) c[u][v-'A'] = m++;
            u = c[u][v-'A'];
        }
        ++cnt[u];
    }
    ans = 0;
    dfs();
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int i = 1, t;
    cin >> t;
    while(t--){
        cout << "Case #" << i++ << ": ";
        solve();
    }
    return 0;
}
