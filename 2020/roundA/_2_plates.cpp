#include <bits/stdc++.h>

using namespace std;

int n, k, p, a[50][30];
int dp[51][1501];
int pre[50][31];

void solve(){
    cin >> n >> k >> p;
    memset(dp, 0, sizeof(dp));
    memset(pre, 0, sizeof(pre));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < k; ++j){
            cin >> a[i][j];
            pre[i][j+1] = pre[i][j] + a[i][j];
        }
    }
    for(int i = 1; i < n+1; ++i){
        for(int j = 1; j < p+1; ++j){
            for(int l = 0; l <= min(k, j); ++l){
                dp[i][j] = max(dp[i][j], dp[i-1][j-l] + pre[i-1][l]);
            }
        }
    }
    cout << dp[n][p] << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t, i = 1;
    cin >> t;
    while(t--){
        cout << "Case #" << i << ": ";
        solve();
        i++;
    }
}
