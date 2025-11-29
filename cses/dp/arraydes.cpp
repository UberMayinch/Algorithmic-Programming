#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int solve(int n, int k, int idx, vector<int>& arr, vector<vector<int>>& dp, vector<int>& temp) {
    if(idx >= n) return 1;

    if(arr[idx] != 0) {
        temp[idx] = arr[idx];
        if(idx > 0 && abs(temp[idx]-temp[idx-1]) > 1) return dp[idx][arr[idx]] = 0;
        return dp[idx][arr[idx]] = solve(n, k, idx+1, arr, dp, temp);
    } 
    
    else {
        int ans = 0;
        if(idx > 0) {
            if(temp[idx-1]+1 <= k) {
                temp[idx] = temp[idx-1]+1;
                if(dp[idx+1][temp[idx-1]+1] != -1){
                    ans += dp[idx+1][temp[idx-1]+1];
                }
                else ans = (ans + solve(n,k,idx+1,arr,dp, temp)) % MOD;
            }

            temp[idx] = temp[idx-1];
            if(dp[idx+1][temp[idx-1]] != -1){ 
                ans += dp[idx+1][temp[idx-1]];
            }
            else ans = (ans + solve(n,k,idx+1,arr,dp, temp)) % MOD;

            if(temp[idx-1]-1 >= 1) {
                temp[idx] = temp[idx-1]-1;
            if(dp[idx+1][temp[idx-1]] != -1){ 
                ans += dp[idx+1][temp[idx-1]];
            }
                else ans = (ans + solve(n,k,idx+1,arr,dp, temp)) % MOD;
            }
        } 
        
        else {
            for(int i=1;i<=k;i++) {
                temp[idx] = i;
            if(dp[idx+1][i] != -1){ 
                ans += dp[idx+1][i] % MOD;
            }
                else ans = (ans + solve(n,k,idx+1,arr,dp, temp)) % MOD;
            }
        }
        return dp[idx][temp[idx]] = ans;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    vector<int> dp(n, 0);
    cout << solve(n,k,0,v,dp) % MOD << endl;
}
