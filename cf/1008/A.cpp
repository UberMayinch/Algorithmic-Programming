#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
typedef vector<long long> vi;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    ostringstream out;
    while (t--)
    {
        int n;
        cin >> n;
        int tot = 2 * n;
        vi b_list(tot);
        unordered_set<ll> b_set;
        for (int i = 0; i < tot; i++)
        {
            cin >> b_list[i];
            b_set.insert(b_list[i]);
        }
        sort(b_list.begin(), b_list.end());
        vi ans;
        {
            vi A(b_list.begin(), b_list.begin() + n), B(b_list.begin() + n, b_list.end());
            ll sumA = 0, sumB = 0;
            for (auto x : A)
                sumA += x;
            for (auto x : B)
                sumB += x;
            ll d = (sumB >= sumA ? sumB - sumA : sumA - sumB);
            if (d && !b_set.count(d))
            {
                vi res;
                if (sumB >= sumA)
                {
                    res.pb(d);
                    for (int i = 0; i < n; i++)
                    {
                        res.pb(B[i]);
                        res.pb(A[i]);
                    }
                }
                else
                {
                    res.pb(d);
                    for (int i = 0; i < n; i++)
                    {
                        res.pb(A[i]);
                        res.pb(B[i]);
                    }
                }
                ans = res;
            }
        }
        if (!ans.empty())
        {
            for (int i = 0; i < ans.size(); i++)
            {
                out << ans[i] << (i + 1 == ans.size() ? "\n" : " ");
            }
            continue;
        }
        {
            vi A_alt, B_alt;
            for (int i = 0; i < tot; i++)
            {
                if (i % 2 == 0)
                    A_alt.pb(b_list[i]);
                else
                    B_alt.pb(b_list[i]);
            }
            ll sumA_alt = 0, sumB_alt = 0;
            for (auto x : A_alt)
                sumA_alt += x;
            for (auto x : B_alt)
                sumB_alt += x;
            ll d = (sumB_alt >= sumA_alt ? sumB_alt - sumA_alt : sumA_alt - sumB_alt);
            if (d && !b_set.count(d))
            {
                vi res;
                if (sumB_alt >= sumA_alt)
                {
                    res.pb(d);
                    int len = A_alt.size();
                    for (int i = 0; i < len; i++)
                    {
                        res.pb(B_alt[i]);
                        res.pb(A_alt[i]);
                    }
                }
                else
                {
                    res.pb(d);
                    int len = A_alt.size();
                    for (int i = 0; i < len; i++)
                    {
                        res.pb(A_alt[i]);
                        res.pb(B_alt[i]);
                    }
                }
                ans = res;
            }
        }
        if (!ans.empty())
        {
            for (int i = 0; i < ans.size(); i++)
            {
                out << ans[i] << (i + 1 == ans.size() ? "\n" : " ");
            }
            continue;
        }
        {
            vi A(b_list.begin(), b_list.begin() + n), B(b_list.begin() + n, b_list.end());
            ll sumA = 0, sumB = 0;
            for (auto x : A)
                sumA += x;
            for (auto x : B)
                sumB += x;
            ll d = sumB - sumA;
            bool found = false;
            for (int i = 0; i < n && !found; i++)
            {
                ll x = A[i];
                double target = x + (double)d / 2.0;
                auto it = lower_bound(B.begin(), B.end(), (ll)ceil(target));
                for (int k = -1; k <= 0; k++)
                {
                    int idx = (int)((it - B.begin()) + k);
                    if (idx < 0 || idx >= n)
                        continue;
                    ll y = B[idx];
                    ll new_d = llabs(d - 2LL * (y - x));
                    if (new_d == 0 || b_set.count(new_d))
                        continue;
                    ll new_sumA = sumA - x + y, new_sumB = sumB - y + x;
                    vi A_new = A, B_new = B;
                    A_new[i] = y;
                    B_new[idx] = x;
                    vi candidate;
                    if (new_sumB >= new_sumA)
                    {
                        candidate.pb(new_sumB - new_sumA);
                        for (int j = 0; j < n; j++)
                        {
                            candidate.pb(B_new[j]);
                            candidate.pb(A_new[j]);
                        }
                    }
                    else
                    {
                        candidate.pb(new_sumA - new_sumB);
                        for (int j = 0; j < n; j++)
                        {
                            candidate.pb(A_new[j]);
                            candidate.pb(B_new[j]);
                        }
                    }
                    if (candidate[0] && !b_set.count(candidate[0]))
                    {
                        ans = candidate;
                        found = true;
                        break;
                    }
                }
            }
        }
        if (!ans.empty())
        {
            for (int i = 0; i < ans.size(); i++)
            {
                out << ans[i] << (i + 1 == ans.size() ? "\n" : " ");
            }
            continue;
        }
        out << "No solution found" << "\n";
    }
    cout << out.str();
    return 0;
}
