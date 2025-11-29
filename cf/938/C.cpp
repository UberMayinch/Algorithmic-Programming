#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;

#define pushback PB


int main(){
  int t;
  cin >> t;
  while(t--){
    ll n, k;
    cin >> n >> k;
    vi v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    int i =0;
    int j=n-1;
    ll sum=0;
    vi check;
    bool start=true;
    while(i < j){
      if(start && v[i] <= v[j]){
        sum += 2*v[i]-1;
        v[j] -= v[i]-1;
        start = false;
        i++;  
      }
      else if(start && v[j] < v[i]){
        sum += 2*v[j];
        v[i] -= v[j];
        j--;
      }
      else if(!start && v[i] < v[j]){
        sum += 2*v[i];
        v[j] -= v[i];
        i++;
      }
      else if(!start && v[j] <= v[i]){
        sum += 2*v[j]-1;
        v[i] -= v[j];
        j--;
        start=true;
      }
      check.push_back(sum);
    }
    check.push_back(sum + v[i]);
    for(auto it: check){
      cout << it << " ";
    }
    int count = upper_bound(check.begin(), check.end(), k) - check.begin();
    cout << count << endl;
  }
}

