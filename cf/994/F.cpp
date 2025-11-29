#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
typedef long long ll;
typedef vector<ll> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, q;
    cin >> n >> m >> q;


    vi a(n), b(m);
    ll suma = 0, sumb = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        suma += a[i];
    }

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        sumb += b[i];
    }

    vi sumsa;
    vi sumsb;
    // cout << suma << endl << sumb << endl;

    for (int i = 0; i < m; ++i) {
        sumsb.pb(sumb-b[i]);
    }

    for (int i = 0; i < n; ++i) {
        sumsa.pb(suma-a[i]);
    }

    sort(sumsa.begin(), sumsa.end());

    sort(sumsb.begin(), sumsb.end());

    // for(auto it: sumsa){
    //     cout << it << " ";
    // }
    // cout << endl;
    // for(auto it: sumsb){
    //     cout << it << " ";
    // }
    // cout << endl;

    while (q--) {
        ll query;
        cin >> query;
        int minus = (query < 0)?1:0;
        int flag=0;
        query = abs(query);
        for(int i=1;i*i<=query;i++){
            if(query % i == 0){
                if(minus){
                    if (binary_search(sumsa.begin(), sumsa.end(), -(query / i)) && binary_search(sumsb.begin(), sumsb.end(), i)){
                        flag = 1;
                        break;
                    }
                    else if (binary_search(sumsa.begin(), sumsa.end(), (query / i)) && binary_search(sumsb.begin(), sumsb.end(), -i)){
                        flag = 1;
                        break;
                    }
                    if (binary_search(sumsb.begin(), sumsb.end(), -(query / i)) && binary_search(sumsa.begin(), sumsa.end(), i)){
                        flag = 1;
                        break;
                    }
                    else if (binary_search(sumsb.begin(), sumsb.end(), (query / i)) && binary_search(sumsa.begin(), sumsa.end(), -i)){
                        flag = 1;
                        break;
                    }
                }
                else{
                    // cout << "LOL\n";
                    if (binary_search(sumsa.begin(), sumsa.end(), query / i) && binary_search(sumsb.begin(), sumsb.end(), i)){
                        flag = 1;
                        break;
                    }
                    else if (binary_search(sumsa.begin(), sumsa.end(), -(query / i)) && binary_search(sumsb.begin(), sumsb.end(), -i)){
                        flag = 1;
                        break;
                    }
                    if (binary_search(sumsb.begin(), sumsb.end(), (query / i)) && binary_search(sumsa.begin(), sumsa.end(), i)){
                        flag = 1;
                        break;
                    }
                    else if (binary_search(sumsb.begin(), sumsb.end(), -(query / i)) && binary_search(sumsa.begin(), sumsa.end(), -i)){
                        flag = 1;
                        break;
                    }
                }
            }
        }
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
