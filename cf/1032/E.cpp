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
    string a, b;
    cin >> a >> b;
    int cnt=0;
    int cr=0;
    for(int i=0;i<a.size();i++){
        if(b[i]-a[i] + cr >= 2){
            break;
        }
        else if(a[i] == b[i]){
            cnt+=2;
        }
        else{
            cnt +=1;
            cr =10;
        }
    }
    cout << cnt << endl;
    
  }
}