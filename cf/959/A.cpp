#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        if(n == 1 && m == 1){
            cin >> n;
            cout << "-1" << endl;
        }
        else {
            vector<vector<int>> v(n, vector<int>(m));
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cin >> v[i][j]; 
                }
            }
            
            if(m == 1) {
                vector<vector<int>> rotated(n, vector<int>(m));
                for(int i = 0; i < n; i++){
                    rotated[(i + 1) % n][0] = v[i][0];
                }
                for(int i = 0; i < n; i++){
                    cout << rotated[i][0] << endl;
                }
            } else {
                vector<vector<int>> rotated(n, vector<int>(m));
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        rotated[i][(j + 1) % m] = v[i][j];
                    }
                }
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < m; j++){
                        cout << rotated[i][j] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }
    return 0;
}
