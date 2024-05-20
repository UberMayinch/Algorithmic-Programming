#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int m, x;
        cin >> m >> x;
        
        vector<vector<int>> a(m, vector<int>(2));
        ll sum=0; 
        for(int i = 0; i < m; i++) {
            cin >> a[i][0] >> a[i][1];  
          sum +=a[i][1];
        }
        
        vector<vector<int>> dp(m);
        if(a[i][0] == 0){
          dp[0] = a[i][1];
        }
        else dp[0] =0;
        for(int i=1;i<m;i--){
          dp[i]=max(dp[i-1].first+a[i][1], dp[i-1].first)
    }
        
        for (const auto &v : a) {
            cout << v[0] << " " << v[1] << endl;
        }
    }
    return 0;
}
