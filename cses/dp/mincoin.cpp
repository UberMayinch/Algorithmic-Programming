#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calc_coins(int sum, vector<int>&coins, vector<int>&dp){
    if(dp[sum] != -1){
        return dp[sum];
    }
    else{
        ll mn = INT_MAX;
        for(auto coin: coins){
            if(sum - coin >= 0){
                mn = min(1 + calc_coins(sum-coin, coins, dp), mn);
            }
        }
        return dp[sum] = mn;
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<int> dp(k+1, -1);
    dp[0]=0;
    ll ans = calc_coins(k, v, dp);
    if(ans == INT_MAX){
        cout << "-1" << endl;
    }
    else cout << ans << endl;
}