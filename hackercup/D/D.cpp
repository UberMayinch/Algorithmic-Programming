#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    if (!(cin >> t)) return 0;
    for (int tc = 1; tc <= t; ++tc) {
        int n; 
        string s;
        cin >> n >> s;

        vector<int> nextA(n + 2, n + 1), prevB(n + 2, 0);
        for (int i = n; i >= 1; --i) {
            nextA[i] = (s[i - 1] == 'A') ? i : nextA[i + 1];
        }
        for (int i = 1; i <= n; ++i) {
            prevB[i] = (s[i - 1] == 'B') ? i : prevB[i - 1];
        }

        int L = 1, R = n;
        char last = '?';
        bool a = true;

        while (L <= R) {
            if (a) {
                int i = nextA[L];
                if (i > R) {
                    a = false;
                } else {
                    L = i + 1;
                    last = 'A';
                    a = false;
                }
            } else {
                int j = prevB[R];
                if (j < L) {
                    a = true;
                } else {
                    R = j - 1;
                    last = 'B';
                    a = true;
                }
            }
        }

        cout << "Case #" << tc << ": " << (last == 'A' ? "Alice" : "Bob") << endl;
    }
    return 0;
}

