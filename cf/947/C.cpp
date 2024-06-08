#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long int> v(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        long long int maxmed = 0;
        multiset<int> mySet;

        for (int i = 0; i < n - 1; i++) {
            long long int thi = min(v[i], v[i + 1]);
            mySet.insert(v[i]);

            auto it = mySet.begin();
            advance(it, mySet.size() / 2);  
            long long int med = *it;  // n/2th element of the multiset

            if (thi >= med) {
                multiset<int> emp;
                swap(mySet, emp);  // Clear
                maxmed = max(maxmed, thi);
            } else {
                maxmed = max(maxmed, med);
            }
        }

        cout << maxmed << endl;
    }

    return 0;
}
