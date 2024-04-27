#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector <int> v(n);
    int arr[100];
    for(int i=0;i<100;i++){
      arr[i]=0;
    }
    for(int i=0;i<n;i++){
    cin >> v[i];
    }
    for(int i=0;i<n;i++){
        arr[v[i]-1] += 1;
    }
    int count=0;
    for(int i=0;i<100;i++){
      count +=(arr[i]/3); 
    }
    cout << count << endl;
  }
}
