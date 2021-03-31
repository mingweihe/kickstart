#include <bits/stdc++.h>

using namespace std;
#define ll long long

int m, n, a[305][305];
int dirs[] = {-1, 0, 1, 0, -1};

bool valid(int i, int j){
    int ni, nj;
    for(int k = 0; k < 4; ++k){
        ni = i+dirs[k];
        nj = j+dirs[k+1];
        if(ni < 1 || ni > m) continue;
        if(nj < 1 || nj > n) continue;
        if(abs(a[i][j]-a[ni][nj]) > 1) return false;
    }
    return true;
}

void solve(){
    priority_queue<pair<int, pair<int, int>>> pq;
    cin >> m >> n;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(valid(i, j)) continue;
            pq.push(make_pair(a[i][j], make_pair(i, j)));
        }
    }
    int i, j, ni, nj;
    ll ans = 0;
    while(!pq.empty()){
        auto top = pq.top();
        i = top.second.first;
        j = top.second.second;
        pq.pop();
        if(valid(i, j)) continue;
        for(int k = 0; k < 4; ++k){
            ni = i+dirs[k];
            nj = j+dirs[k+1];
            if(ni < 1 || ni > m) continue;
            if(nj < 1 || nj > n) continue;
            if(a[i][j]-a[ni][nj] > 1){
                int more = a[i][j]-a[ni][nj] - 1;
                ans += more;
                a[ni][nj] += more;
                pq.push(make_pair(a[ni][nj], make_pair(ni, nj)));
            }
        }
    }
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
