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
        int q;
        int n;
        cin >> n >> q;
        vi par(n);
        par[0] = 1;  
        for(int i = 1; i < n; i++){
            cin >> par[i];
        }
        vi p(n);
        for(int i = 0; i < n; i++){
            cin >> p[i];
        }
        int flag = 0;

        if(p[0] != 1){
            flag = 1;
        } else {
            stack<int> S;
            S.push(1);
            for(int i = 1; i < n; i++){
                while(!S.empty() && par[p[i] - 1] != S.top()){
                    S.pop();
                }
                if(S.empty()){
                    flag = 1;
                    break;
                }
                S.push(p[i]);
            }
        }

        for(int i = 0; i < q; i++){
            int l, r;
            cin >> l >> r;
            l--;  
            r--; 

            swap(p[l], p[r]);
            

                flag = 0;
                if(p[0] != 1){
                    flag = 1;
                } else {
                    stack<int> S;
                    S.push(1);
                    for(int i = 1; i < n; i++){
                        while(!S.empty() && par[p[i] - 1] != S.top()){
                            S.pop();
                        }
                        if(S.empty()){
                            flag = 1;
                            break;
                        }
                        S.push(p[i]);
                    }
                }

            if(flag){
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}
