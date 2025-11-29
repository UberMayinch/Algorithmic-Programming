#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        if (m > n * (n + 1) / 2 || m < n)
        {
            cout << "-1" << endl;
        }
        else
        {

            ll extra = m - n;

            vi l;
            for (ll cur = n-1; cur > 0 && extra > 0; --cur)
            {
                if (extra >= cur)
                {
                    l.pb(cur+1);
                    extra -= cur;
                }
            }
            l.pb(1);
            vector<bool> used(n + 1, false);

            if (l.size() != 0)
            {
                int root = l[0];
                cout << root << endl;
                used[root] = true;

                for (int i = 0; i + 1 < (int)l.size(); ++i)
                {
                    int u = l[i];
                    int v = l[i + 1];
                    cout << u << " " << v << endl;
                    used[v] = true;
                }
            }
            else
                cout << "1" << endl;

            for (int v = 1; v <= n; ++v)
            {
                if (!used[v])
                {
                    cout << 1 << " " << v << endl;
                }
            }
        }
    }
    return 0;
}
