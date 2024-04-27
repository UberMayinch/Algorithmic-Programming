#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        if (n == 1) {
            cout << k << endl;
            continue;
        } else {
            vector<long long int> v(n, 0);
            long long int ans = (1LL << (int)log2(k)) - 1;
            v[0] = ans;
            long long int b = k - v[0];
            v[1] = b;
            for (int i = 0; i < n; i++) {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
