#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define INF (int)1e9
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
    ll n, x;
    cin >> n >> x;
    vector<int> v(n);
    vector<int> c(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    vector<int> dp(x+1, 0);
    for(int i = 0;i<v.size();i++){
        for(int j = x;j>=0;j--){
            if(j + v[i] <= x){
                dp[j + v[i]] = max(dp[j+v[i]], dp[j] + c[i]);
            }
        }
    }
    cout << dp[x] << endl;
}