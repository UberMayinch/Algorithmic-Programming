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
    int n, c;
    cin >> n >> c;
    vi v(n);
    map<int,int> s(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
      s[i]=mp(i, v[i]);
    }
    
    // sort the vector
    // for each entry in the original vector store how many entries are greater than it.
   //iterate over each entry in the original vector. keep a prefix sum variable that counts running prefix sum.
    //if this is the greatest element in the original vector and it is greater than c then output 0
    //if it is greatest element but less than c then output n-1
    //if not the greatest element:
    //binary search from the index of this vector in original vector to n-1 to find a k such that:
    //original vector value at index + prefix sum till that index + sum of (k-idx) top elements is greater than k-idx+1th element
    for(int i=0;i<n;i++){
      if(v[n-1] == map.end()-1){
        cout << "0" << endl;
      }

    }
    

  }

}


