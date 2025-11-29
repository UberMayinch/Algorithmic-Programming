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
    ll n, m;
    cin >> n >> m;
    if(m > n*(n+1)/2 || (m < n-1)){
        cout << "-1" << endl;
    }
    else{
        vi l;
        int rem = n-1;
        int sum = m-n-1;
        while(sum){
            if(sum > rem){
                l.push_back(rem);
                sum -= rem;
                rem--;
            }
            else{
                l.push_back(rem);
                break;
            }
        }
        vector<bool> v(n, false);
        if(l.size() == 0) cout << "1" << endl;
        else cout << l[0] << endl;
        for(int i=0;i<l.size()-1;i++){
            cout << l[i] << " " << l[i+1] << endl;
            v[l[i]-1] = true;
            v[l[i+1]-1]=true;
        }

    }
    
  }
}