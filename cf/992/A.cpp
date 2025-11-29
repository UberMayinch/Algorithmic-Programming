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
    int n, m;
    cin >> n >> m;
    vi v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int flag=-1;
    for(int i=0;i<n;i++){
        int flag1=1;
        for(int j=0;j<n;j++){
            if(j != i){
                if(abs(v[j]-v[i]) % m == 0){
                    flag1=0;
                    break;
                }
            }
        }
        if(flag1 == 1){
            flag=i;
        }
    }
    if(flag == -1){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        cout << flag + 1<< endl;
    }

    
  }
}