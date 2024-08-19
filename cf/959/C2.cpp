#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        int n, g;
        cin >> n >> g;
        vi v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        vi pref(n + 1);
        pref[0] = 0;
        for(int i = 1; i <= n; i++){
            pref[i] = pref[i - 1] + v[i - 1];
        }

        ll total_subarrays = n * (n + 1) / 2;
        int l = 0, r = 1;
        ll result = total_subarrays;
        
        vi nums(n, 1);
        while(l < n){
            if(pref[r] - pref[l] > g){
                result -=nums[l];
              if(r < n)
                nums[r+1]++;
        if( l != r){
                l++;
        }
        else r++;
            } 
            else if(r == n){
        l++;
      }
          else r++;
        }

        cout << result << endl;
    }

    return 0;
}
