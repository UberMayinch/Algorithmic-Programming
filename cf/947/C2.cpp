#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        if (n == 2) {
            cout << min(v[0], v[1]) << endl;
            continue;
        }

        multiset<int> temp;
        temp.insert(v[0]);
        temp.insert(v[1]);
        int ans=0;

        for (int i = 2; i < n; i++) {
            temp.insert(v[i]);
            auto med = temp.begin();
            advance(med, 1);
            ans = max(ans, *med);
            if (temp.size() > 2) {
                temp.erase(temp.find(v[i - 2]));
            }
        }

        cout << ans << endl;
    }
    return 0;
}
