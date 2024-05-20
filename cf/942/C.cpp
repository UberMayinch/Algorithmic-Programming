#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    int min=v[0];
    int i=0;
    int count = 1;
    while(i < n-1){
      while(v[i] == v[i+1]){
          i++;
          count ++;
      }
      i++;
      cout << count << endl;
      if((i < n-1)&&(k / count >= v[i+1]-v[i])){
          k -=count*(v[i+1]-v[i]);
          min = v[i+1];
          i++;
        cout << k <<  endl;
      }
      else if((i < n-1) && (k / count > 0)){
          min += k / count;
          k= k %count;
          break;
      }
      else break;
    }
    cout << k << " " << min;
    return 0;
    if((v[i+1] - v[i] > 1) || ((k > 0) && (((v[i+1]-v[i] == 1) && (k / (n-i+1) > 0)) || ((v[i+1]-v[i] == 0) && (k / (n-i+1) > 1))))){
      cout << n *(min-1)+1+2*(n-i);
    }
    else if((v[i+1]-v[i] == 1) || ((k > 0) && ((v[i+1]-v[i] == 0) && (k / (n-i+1) == 1)))){
      cout << n*(min-1)+1 + n-i;
    }
    else
    cout << n*(min-1)+1 << endl; 
  
  }
}
