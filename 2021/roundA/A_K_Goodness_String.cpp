#include <bits/stdc++.h>

using namespace std;

int n , k;
string s;

void solve(){
    cin >> n >> k;
    cin >> s;
    int i = 0, j = n-1;
    int score = 0;
    while(i < j){
        if(s[i++] != s[j--]){
            score++;
        }
    }
    int ans = abs(score - k);
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