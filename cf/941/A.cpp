#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    int a[n];
    vector<int> freq(100);
    for(int i=0;i<100;i++){
      freq[i]=0;
    }
    for(int i=0;i<n;i++){
      cin >> a[i];
      freq[a[i]-1]+=1;
    }
    sort(freq.begin(), freq.end());
    if(freq[99] >= k){
      cout << k-1 << endl;;
    }
    else{
      cout << n << endl;
    }
    
  }
}
