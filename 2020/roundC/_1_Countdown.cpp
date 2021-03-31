#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[200001];

void solve(){
    cin >> n >> k;
    int ans = 0, rem = k;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i){
        if(a[i] == rem) rem--;
        else if(a[i] == k) rem = k-1;
        else rem = k;
        if(rem == 0){
            ans++;
            rem = k;
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