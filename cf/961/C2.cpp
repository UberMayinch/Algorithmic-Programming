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
        int n;
        cin >> n;
        vi v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        bool flag = false;
        ll mx = v[0];
        ll count = 0;

        for(int i = 1; i < n; i++){
            if(mx > 1 && v[i] == 1){
                flag = true;
                break;
            } else {
                if(v[i] < mx){
                    double log_v_i = log2(v[i]);
                    double log_mx = log2(mx);
                    int required_steps=0;
                    while(log_mx - log_v_i > 0.000001){
                      log_v_i*=2;
                      required_steps++;
                    }
                    count+= required_steps;
                    v[i] = pow(v[i], pow(2, required_steps));
                }
                mx = v[i];
            }
        }
        
        if(flag) {
            cout << "-1" << endl;
        } else {
            cout << count << endl;
        }
    }
}
