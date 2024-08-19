#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    for(int i=0;i<n;i++){
      cin >> b[i];
    }
    int astart=0;
    int aend=n-1;
    int flag=0;
    int bstart=0;
    int bend=n-1;

    for(int i=0;i<n-1;i++){
      if(((a[astart] == b[bend]) || (a[astart] == b[bstart])) && ((a[aend] == b[bstart]) || (a[aend] == b[bend]))){
        if(a[astart] == b[bend]){
          astart++;
          bend--;
        }
        else if(a[astart] == b[bstart]){
          astart++;
          bstart++;
        }
        else if(a[aend] == b[bstart]){
          aend--;
          bstart++;
        }
        else if(a[aend] == b[bend]){
          aend--;
          bend--;
        }
      }
      else {
        flag=1;
        break;
      }
    }
    if(flag){
      cout << "Alice" << endl;
    }
    else cout << "Bob" << endl;
  }

}


