#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        vector<int> mna(n);
        vector<int> mxa(n);
        int m = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] > m)
            {
                m = v[i];
            }
            mxa[i] = m;
        }
        m += 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i] < m)
            {
                m = v[i];
            }
            mna[i] = m;
        }

        // for(auto it: mxa){
        //     cout << it << " ";
        // }
        // cout << endl;
        // for(auto it: mna){ cout << it << " ";
        // }
        string s;
        cin >> s;
        bool flag = 1;
        for (int i = 0; i < q; i++)
        {
            int x;
            cin >> x;
            s[x - 1] = (s[x - 1] == 'L') ? 'R' : 'L';
            // cout << s << endl;
            if (s.find("LR") == string::npos) {
                flag = 1;
            }
            if (s[x - 1] == 'L' && s[x] == 'R')
            {
                // cout << s << endl;
                if (mxa[x - 1] > mna[x])
                {
                    flag = 0;
                }
            }
            else if (s[x - 1] == 'R' && s[x - 2] == 'L')
            {
                if (mxa[x - 2] > mna[x - 2])
                {
                    flag = 0;
                }
            }
            if (flag == 1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}