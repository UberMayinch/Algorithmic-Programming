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
        vector<int> div;
        int count = 0;
        for(int i = 0; i < n - 1; i++){
            div.pb(__gcd(v[i], v[i + 1]));
        }

        int lst = -1;
        for(int i = 0; i < n - 2; i++){
            if(div[i + 1] < div[i]){
                count++;
                lst = i;
            }
        }
        // cout << lst << endl;        
        if(count > 2) {
            cout << "NO" << endl;
        }
        else {
            if((lst == 0) || (lst == n - 2)){
                cout << "YES" << endl;
            }
            else if(lst == -1) {
                cout << "YES" << endl;
            }
            else {
                if( 
                   (lst - 2 >= 0 && lst + 2 <= n - 1 && div[lst - 2] <= div[lst + 1]) || 
                   (lst - 1 >= 0 && lst + 2 < n - 1 && div[lst - 1] <= div[lst + 2]) || (lst -1 >= 0 && lst + 2 == n-1 && div[lst-1] <= div[lst])
        ) {
                    cout << "YES" << endl;
                }
                else {
                    cout << "NO" << endl;
                }
            }
        }
    }
}
