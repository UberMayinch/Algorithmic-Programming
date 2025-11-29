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
  int n;
  cin >> n;
  map<string,int>freq;
  for(int i=0;i<n;i++){
    string x;
    int a;
    cin >> x >> a;
    freq[x]=a;
  }
  int m;
  cin >> m;
  for(int i=0;i<m;i++){
    string x;
    cin >> x;
    freq[x]--;
  }
  for(auto it:freq){
    if(it.second > 0){
        cout << it.first << endl;
        return 0;
    }
  }
  
  cout << "NO KPOP FOR VADER" << endl;
}