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
    int n;
    cin >> n;
    vi v(n);
    for(int i=0;i<n;i++){
      cin >> v[i];
    }
    int flag =0;
    int i=0;
    int j=n-1;
    if(v[i] != v[j]){
      flag=2;
      cout << "0";
      j=0;
    }
    while((j >= i) && (flag != 2)){
      if(v[i] == v[j]){
        if(v[i+1] == v[i])i++;
        else{
          flag = 1;
          break;
        }
        if(v[j-1] == v[j])j--;
        else{
          flag = 1;
          break;
        }
      }  
      else{
        flag=1;
        break;
      }
    }
    if((flag == 1) && (n > 2)){
      cout << min(i, n-j)+1; 
    }
    else if(n ==1) cout << "-1";
    else if(flag == 0) cout << "-1";
    cout << endl;
  }
}

