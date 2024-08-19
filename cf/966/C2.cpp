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
        int m;
        cin >> m;
        for(int i = 0; i < m; i++){
            string s;
            cin >> s;
            if(s.size() != n){
                cout << "NO" << endl;
                continue;
            }
            else{
                int flag = 0;
                map<char, ll> S;  
                map<ll, char> Sa;
                for(int i = 0; i < n; i++){
                    if(S.find(s[i]) != S.end() && S[s[i]] != v[i]){
                        cout << "NO" << endl; 
                        flag = 1;
                        break;
                    }
                    else {
                        S[s[i]] = v[i]; 
                    }
                    if(Sa.find(v[i]) != Sa.end() && Sa[v[i]] != s[i]){
                        cout << "NO" << endl; 
                        flag = 1;
                        break;
                    }
                    else {
                        Sa[v[i]] = s[i]; 
                    }
                }
                if(!flag){
                    cout << "YES" << endl;
                }
            }
        }
    }
}
