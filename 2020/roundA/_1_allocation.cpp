#include <bits/stdc++.h>

using namespace std;

int solve(int n, int b, vector<int>& A){
    int ans = 0;
    sort(A.begin(), A.end());
    for(int i = 0; i < n; ++i){
        if(b - A[i] >= 0){
            b -= A[i];
            ans += 1;
        }
    }
    return ans;
}

int main(){
    int t, n, b, x;
    cin >> t;
    for(int i = 1; i <= t; ++i){
        cin >> n >> b;
        vector<int> A;
        for(int j = 0; j < n; ++j){
            cin >> x;
            A.push_back(x);
        }    
        cout << "Case #" << i << ": " << solve(n, b, A) << endl;
    }
    return 0;
}