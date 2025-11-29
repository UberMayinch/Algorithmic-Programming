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
    int n;
    cin >> n;
    vi v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int cnt=10001;

    for(int i=0;i<n;i++){
        int curr = 0;
        bool ls=false;
        bool mr=false;
        bool flag=false;
        for(int j=i;j<n;j++){
            if(abs(v[i]-v[j]) <= 1){
                flag=true;
                break;
            }
            else{
                if(v[j] < v[i])ls=true;
                if(v[j] > v[i])mr=true;
            }
            if(ls && mr){
                flag=true;
                break;
            }
            curr++;
        }
        if(flag){
        cnt = min(curr, cnt);
        }
    }

    if(cnt == 10001){
        cout << "-1" << endl;
    }
    else cout << cnt << endl;
    
  }
}