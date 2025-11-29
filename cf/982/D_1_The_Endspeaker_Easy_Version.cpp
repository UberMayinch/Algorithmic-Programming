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
        int n, m;
        cin >> n >> m;
        vi a(n);
        vi b(m);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        auto max_iter = max_element(a.begin(), a.end());
        int max_val = (*max_iter);
        if (max_val > b[0])
        {
            cout << -1 << endl;
        }
        else
        {
            int score[m][n + 1];
            int dp[m][n + 1];
            memset(score, 0, sizeof(int) * m * (n+1));
            for (int i = 0; i < m; i++)
            {
                dp[i][0] = 0;
            }
            for (int i = 0; i < m; i++)
            {
                score[i][0] = b[i];
            }
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (score[i][j] + a[j] <= b[i])
                    {
                        if (i != 0 && j != 0)
                        {
                            dp[i][j + 1] = min(dp[i][j], dp[i - 1][j + 1]);
                            if(dp[i][j+1] == dp[i][j]){
                                score[i][j+1] = score[i][j]+a[j];
                            }
                            else score[i][j+1]=b[i];
                        }
                        else{
                            dp[i][j + 1] = dp[i][j];
                            score[i][j+1]=score[i][j]+a[j];
                        }
                    }
                    else if ((score[i][j] + a[j] > b[i]) && (a[j] <= b[i]))
                    {
                        if (i != 0)
                        {
                            dp[i][j + 1] = min(dp[i-1][j+1], (dp[i][j] + (m - 1 - i)));
                            if(dp[i][j+1] == (dp[i][j] + m-1-i)){
                                score[i][j+1] = a[j];
                            }
                            else score[i][j+1]=b[i];
                        }
                        else
                            dp[i][j + 1] = dp[i][j] + m - 1 - i;
                            score[i][j+1]=a[j];
                    }
                    else{
                        score[i][j+1] = b[i];
                        if (i != 0 && j != 0)
                        {
                            dp[i][j + 1] = dp[i - 1][j + 1];
                        }
                        else
                            dp[i][j + 1] = -1;
                    }
                }
            }
        for(int i=0;i<m;i++){
            for(int j=0;j<n+1;j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n+1;j++){
                cout << score[i][j] << " ";
            }
            cout << endl;
        }
        int mn = INT_MAX;
        for (int i = 0; i < m; i++)
        {
            mn = min(mn, dp[i][n]);
        }
        cout << mn << endl;
        }

    }
}