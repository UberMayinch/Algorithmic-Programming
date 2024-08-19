#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
    ll n, k;
    cin >> n >> k;
    vector<pair<ll,ll>> a(n);  // Resize the vector
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    int flag = 0;
    for(int i = 0; i < n; i++){
        if(flag) break;
        for(int j = i + 1; j < n; j++){  // Changed j = i to j = i + 1 to avoid double counting
            ll fid = k - a[i].first - a[j].first;
            
            auto it = find_if(a.begin() + j + 1, a.end(), [&](const pair<ll, ll>& p) {
                return p.first == fid;
            });
            if(fid > 0 && it != a.end()){
                cout << i + 1 << " " << j + 1 << " " << it->second + 1;
                flag = 1;
                break;
            }
            else if(a[i].first + a[j].first > k){
                cout << "IMPOSSIBLE";
                flag = 1;
                break;
            }
        }
    }
    return 0;
}
