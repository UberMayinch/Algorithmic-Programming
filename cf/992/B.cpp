#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    vi nums;
    for (int i = 1; 2 * i + 2 < ll(1e6); i = 2 * i + 2)
    {
        nums.pb(i);
    }
    //   for(int i=0;i<nums.size();i++){
    //     cout << nums[i] << endl;
    //   }
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (nums[i] >= n)
                {
                    cout << i + 1<< endl;
                    break;
                }
            }
        }
    }
}