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
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        vi suffix_min(n);
        ll min_element = v[n - 1];
        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i] <= min_element)
            {
                min_element = v[i];
            }
            suffix_min[i] = min_element;
        }

        multiset<ll> rem;
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == suffix_min[i])
            {
                if (i != n - 1)
                {
                    cout << v[i] + flag << " ";
                    flag = 0;
                    if (!rem.empty())
                    {
                        auto it = rem.begin();
                        while (it != rem.end())
                        {
                            if (*it <= suffix_min[i + 1])
                            {
                                cout << *it << " ";
                                flag = 1;
                                auto jt = it;
                                it++;
                                rem.erase(jt);
                            }
                            else
                                break;
                        }
                    }
                }
                else
                {
                    if (!rem.empty())
                    {
                        auto it = rem.begin();
                        while (it != rem.end())
                        {
                            if (*it < v[i] && flag == 0)
                            {
                                cout << *it << " ";
                                flag = 1;
                            }
                            if (flag == 1 && *it <= v[i])
                            {
                                cout << *it << " ";
                            }
                        }
                    }
                    cout << v[i] + flag << " ";
                    if (!rem.empty())
                    {
                        for (auto it : rem)
                        {
                            cout << it << " ";
                        }
                    }
                }
            }
            else
            {
                rem.insert(v[i] + 1);
            }
        }
        cout << endl;
    }
}