#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int maxn = 100*1e5;
int n, a[100001], pos[maxn+1], neg[maxn+1];

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    memset(pos, 0, sizeof(pos));
    memset(neg, 0, sizeof(neg));
    // number of subarray may exceed the range of int32
    ll ans = 0;
    int t = 0;
    pos[0]++;
    for(int i = 0; i < n; ++i){
        t += a[i];
        for(int j = 0; j <= 3162; ++j){
            int target = t - j * j;
            if(target > maxn || target < -maxn) break;
            if(target >= 0) ans += pos[target];
            else ans += neg[-target];
        }
        if(t >= 0) pos[t] += 1;
        else neg[-t] += 1;
    }
    cout << ans << '\n';

}

int main(){
    int t, i = 1;
    cin >> t;
    while(t--){
        cout << "Case #" << i++ << ": ";
        solve();
    }
}
