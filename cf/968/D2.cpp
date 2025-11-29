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
    ll t;
    cin >> t;
    while(t--) {
        ll n, m;
        cin >> n >> m;
        ll sum = 0;
        ll result=0;
        for(int i = 0; i < n; i++) {
            int len;
            cin >> len;
            vi v(len);
            for(int j = 0; j < len; j++) {
                cin >> v[j];
            }
            set <ll>b (v.begin(), v.end());
            ll idx=0;
            int flag=1;
            while(b.count(idx) || flag) {
            if(!(b.count(idx)) && flag){
              flag=0;
              idx++;
            }
            if(b.count(idx))
            idx++;
            }
            result = max(result, idx);
        }
      
      
        sum += result + min(m, result)*result+ max((ll)0, m*(m+1) - (result)*(result+1))/2;
        cout << sum << endl;
    }
    return 0;
}
