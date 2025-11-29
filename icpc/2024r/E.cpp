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
    const int MAXN = 2e6 + 1;
    vector<bool> is_prime(MAXN, true);
    vector<int> primes;

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= MAXN; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= MAXN; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= MAXN; i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }

    int n = primes.size();
    // cout << n << endl;
    ll product = 1;
    ll n0 = 0;

    vi products;
    for (int i = 0; i < n; i++)
    {
        product *= primes[i];
        products.pb(product);
        // cout << product << endl;
        n0++;
        if (product > MAXN)
        {
            break;
        }
    }

    // cout << n0 << endl;

    vi perfect;
    perfect.pb(1);
    ll i=2;
    ll sum = 1;
    while(sum < ll(1e9)){
        sum+=i;
        i++;
        perfect.pb(sum);
    }

    // for(int i=0;i<5;i++){
    //     cout << perfect[i] << " ";
    // }
    
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, q;
        cin >> n >> q;

        vi ans(n);

        ll i;
        for(i=1;i*(i+1)/2 < q;i++){
            ll rem = q - i*(i+1)/2;
            ll rem_n = n - i;
            ll j=0;
            for(j=0;j<i;j++){
                ans[j]=primes[j];
            }
            if(rem >= rem_n * min(n-n0, 0ll) && rem <= rem_n * n){
                ll greedy_reduce = rem_n * n - rem;
                cout << (greedy_reduce) << endl;
                while(greedy_reduce - n0 >= 0){
                    ans[j]= products[n0-1];
                    greedy_reduce -= n0;
                    j++;
                }
                ans[j++]=products[greedy_reduce-1];
                for(;j<n;j++){
                    ans[j]=2;
                }
                break;
            }
        }
        for(auto it: ans){
            cout << it << " ";
        }
        cout << endl;
    }
}