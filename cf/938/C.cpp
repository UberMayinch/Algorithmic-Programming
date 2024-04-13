#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;

#define pushback PB

void solve(){

}

int main(){
  int t;
  cin >> t;
  while(t--){
    ll n, k;
    cin >> n >> k;
    int i =0;
    int j=n-1;
    int flag = 0;
    vector <ll> v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    int count = 0;
    while(j >= i){
      if(k < 0){
        break;
      }
      if(flag == 0){

      if(v[j] > v[i]){
        k = k - 2*(v[i]) + 1;
        v[j] = v[j]-v[i]+1;
        count++;
        i++;
        flag = 1;
      }
      else if (v[j] <= v[i]) {
       k = k - 2*(v[j]);
       v[i] = v[i] - v[j];
       count++;
       flag = 1;
       j++;
      }

      }
      else if(flag == 1){
        if(v[j] > v[i]){
          i++;

       k = k - 2*(v[i]);
       v[j] = v[j] - v[i];
       count++;
       flag = 0;
        }
        else if(v[j] <= v[i]){
j++;
        k = k - 2*(v[j]) + 1;
        v[i] = v[i]-v[j]+1;
        count++;
        flag = 0;
        }
      }
    }
    cout << count << endl;
  }
}

