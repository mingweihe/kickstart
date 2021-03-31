#include <bits/stdc++.h>

using namespace std;

int r, c, a[1005][1005];
int U[1005][1005], D[1005][1005], LL[1005][1005], R[1005][1005];

int get(int x, int y){
    if(x < 2 || y < 4) return 0;
    int xx = y / 2;
    if(xx < x) x = xx;
    return x - 1;
}

void solve(){
    cin >> r >> c;
    for(int i = 1; i <= r; ++i){
        for(int j = 1; j <= c; ++j){
            cin >> a[i][j];
        }
    }
    
    memset(U, 0, sizeof(U));
    memset(D, 0, sizeof(D));
    memset(LL, 0, sizeof(LL));
    memset(R, 0, sizeof(R));

    for(int i = 1; i <= r; ++i){
        for(int j = 1; j <= c; ++j){
            if(a[i][j] != 0){
                U[i][j] = U[i-1][j] + 1;
                LL[i][j] = LL[i][j-1] + 1;
            }
        }
    }
    for(int i = r; i >= 1; --i){
        for(int j = c; j >= 1; --j){
            if(a[i][j] != 0){
                D[i][j] = D[i+1][j] + 1;
                R[i][j] = R[i][j+1] + 1;
            }
        }
    }
    int ans = 0;
    int u, d, l, rr;
    for(int i = 1; i <= r; ++i){
        for(int j = 1; j <= c; ++j){
            if(!a[i][j]) continue;
            u = U[i][j];
            d = D[i][j];
            l = LL[i][j];
            rr = R[i][j];
            ans += get(u, l) + get(l, d) + get(d, rr) + get(u, rr);
            ans += get(l, u) + get(d, l) + get(rr, d) + get(rr, u);
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
