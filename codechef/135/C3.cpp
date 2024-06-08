#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<pii> v(n);

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v[i] = mp(x, i + 1);
        }

        vector<pii> temp;
        temp.pb(v[0]);
        for (int i = 1; i < n - 1; i++) {
            temp.pb(v[i]);
        }
        temp.pb(v[n - 1]);

        sort(temp.begin() + 1, temp.end() - 1);

        for (int i = 1; i < n - 1; i++) {
            v[i] = temp[i];
        }
        // 
        // for(auto it: v){
        //     cout << it.first << " " << it.second  << endl;
        // }
        
        long long cost = 0;
        int idx = 0;

        while (idx < n) {
            if (v[idx+1].first < v[n-1].first){
                cost += abs(v[idx].second - v[idx + 1].second) * max(v[idx].first, v[idx + 1].first);
                idx++;

            } else {
                cost+=(n - v[idx].second) * (v[n - 1].first);
                break;
            }
        }

        cout << cost << endl;
    }
}
