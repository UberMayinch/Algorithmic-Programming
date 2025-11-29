#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


ll calcPower(ll x, ll y) {
    ll ans = 1;
    while(y) {
        if(y%2) ans = ans*x%MOD;
        x = x*x%MOD;
        y /= 2;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, n;
        cin >> a >> n;
        int pow = n / 2 ;
        ll check = 1;
        if (a < 0)
            cout << 1 << endl;
        else
        {
            check = calcPower(a, pow);
            cout << check << endl;
        }
    }
}