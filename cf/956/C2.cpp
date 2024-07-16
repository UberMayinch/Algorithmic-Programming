#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
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
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        vi b(n);
        map<int, int> check;
        int flag = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            check[a[i]]++;
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
            check[b[i]]--;
            if (check[b[i]] < 0) {
                flag = 1;
            }
        }

        if (flag != 1) {
            vi copied = a;
            int achk = 0;
            int bchk = 0;
            sort(copied.begin(), copied.end());
            for (int i = 0; i < n; i++) {
                if (copied[i] != a[i]) achk++;
                if (copied[i] != b[i]) bchk++;
            }
            cout << achk;
            cout << bchk;
            if (achk % 4 != bchk % 4) {
                flag = 1;
            }
        }
        
        if (flag == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
