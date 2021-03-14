#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+1;
int n, k, a[maxn];

bool valid(int x){
    int cnt = 0;
    for(int i = 1; i < n; ++i){
        int diff = a[i] - a[i-1];
        if(diff <= x) continue;
        cnt += (diff - 1) / x;
    }
    return cnt <= k;
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int l = 1, r = a[n-1], mid;
    while(l <= r){
        mid = l + (r-l) / 2;
        if(valid(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << '\n';
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
