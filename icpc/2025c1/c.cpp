#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
    int a, b;
    cin >> n >> a >> b;
    vector<double>dp(n+1, 0);
    dp[0]=0;
    for(int i=1;i<n+1;i++){
        for(int diff = a;diff <= b;diff++){
            if(i - diff >= 0)
            dp[i] += 1.0/(b - a + 1) * (dp[i-diff] + 1);
        }   
    }
    cout << dp[n] << endl;
}