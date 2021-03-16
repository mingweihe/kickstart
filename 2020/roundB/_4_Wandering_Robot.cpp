#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+1;
double logfact[maxn], xw[maxn], yh[maxn];
int w, h, l, u, r, d;

double p(int x, int y){
    return exp(logfact[x+y-2] - logfact[x-1] - logfact[y-1] - (x+y-2)*log(2));
}

void solve(){
    cin >> w >> h >> l >> u >> r >> d;
    yh[1] = pow(0.5, h-1);
    xw[1] = pow(0.5, w-1);
    for(int i = 2; i <= w; ++i) yh[i] = yh[i-1] + 0.5 * p(i, h-1);
    for(int i = 2; i <= h; ++i) xw[i] = xw[i-1] + 0.5 * p(w-1, i);
    int x = r+1, y = u-1;
    double ans = 0;
    while(x <= w && y >= 1){
        if(x == w) ans += xw[y];
        else if(y == 1) ans += pow(0.5, x-1);
        else ans += p(x, y);
        x++, y--;
    }
    x = l-1, y = d+1;
    while(x >= 1 && y <= h){
        if(y == h) ans += yh[x];
        else if(x == 1) ans += pow(0.5, y-1);
        else ans += p(x, y);
        x--, y++;
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    logfact[0] = 0;
    for(int i = 1; i < maxn; ++i)
        logfact[i] = logfact[i-1] + log(i);
    int t, i = 1;
    cin >> t;
    while(t--){
        cout << "Case #" << i++ << ": ";
        solve();
    }
}
