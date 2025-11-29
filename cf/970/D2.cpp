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
    vi p(n);
    for (int i = 0; i < n; i++)
    {
      cin >> p[i];
    }
    string str;
    cin >> str;
    vi s(n); 
    for (int i = 0; i < n; i++)
    {
      s[i] = str[i] - '0';
    }
    vi a(n, -1);

    for (int i = 0; i < n; i++)
    {
      if (a[i] == -1)
      {
        if ((p[i] == i + 1) && s[i] == 0)
        {
          a[i] = 1;
        }
        else if ((p[i] == i + 1) && s[i] == 1)
        {
          a[i] = 0;
        }
        else
        {
          int count = 0;
          map<int, bool> parents;  
          int cur = i;  
          while (parents[cur] == false)
          {
            parents[cur] = true;
            cur = p[cur] - 1;
            if(s[cur] == 0){
              count++;
            }
          }
          for (auto &entry : parents)
          {
            a[entry.first] = count;
          }
        }
      }
    }

    for (auto it : a)
    {
      cout << it << " ";
    }
    cout << endl;
  }
}
