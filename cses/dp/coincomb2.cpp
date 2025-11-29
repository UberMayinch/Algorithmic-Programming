#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for (int coin : v) {
    for (int sum = coin; sum <= x; sum++) {
        dp[sum] = (dp[sum] + dp[sum - coin]) % MOD;
    }
    }
    cout << dp[x] << endl;
}