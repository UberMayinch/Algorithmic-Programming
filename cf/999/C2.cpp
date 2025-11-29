#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define MOD 998244353;
typedef vector<long long int> vi;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }

        int last0_shifted = 0;
        vector<int> last0_vec = {1};
        int sum0 = 1;

        int last1_shifted = 0;
        vector<int> last1_vec;
        int sum1 = 0;

        for (int ai : a)
        {
            int honest = 0;

            if (!last0_vec.empty() && ai >= last0_shifted)
            {
                int key = ai - last0_shifted;
                if (key < last0_vec.size())
                {
                    honest = (honest + last0_vec[key]) % MOD;
                }
            }

            if (!last1_vec.empty() && ai >= last1_shifted)
            {
                int key = ai - last1_shifted;
                if (key < last1_vec.size())
                {
                    honest = (honest + last1_vec[key]) % MOD;
                }
            }

            int new0_shifted = ai;
            vector<int> new0_vec;
            int new_sum0 = honest;
            if (new_sum0 > 0)
            {
                new0_vec.push_back(new_sum0);
            }

            int new1_shifted = last0_shifted + 1;
            vector<int> new1_vec;
            int new_sum1 = 0;

            if (!last0_vec.empty())
            {
                new1_vec = move(last0_vec); 
                new_sum1 = sum0;
            }

            last0_shifted = new0_shifted;
            last0_vec = move(new0_vec);
            sum0 = new_sum0;

            last1_shifted = new1_shifted;
            last1_vec = move(new1_vec);
            sum1 = new_sum1;

            if (sum0 == 0 && sum1 == 0)
            {
                break;
            }
        }

        int total = (sum0 + sum1) % MOD;
        cout << total << '\n';
    }

    return 0;
}