#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    vi v(n);
    map <int, int>m;
    for(int i=0;i<n;i++){
        cin >> v[i];
        m[v[i]]+=1;
    }

    vector<pair<int, int>> sorted_m(m.begin(), m.end());
    sort(sorted_m.begin(), sorted_m.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });
    // for (const auto& p : sorted_m) {
    //     cout << p.first << " " << p.second << "\n";
    // }

    while(k >= 0){
        if (sorted_m.empty()) break;
        if(k >= sorted_m.back().second)
            k -= sorted_m.back().second;
        else break;
        sorted_m.pop_back();
    }

    if(sorted_m.size() == 0){
        cout << 1 << endl;
    }
    else{
    cout << sorted_m.size() << "\n";

    }

  }
}