#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

ll abso(ll a){
  if(a < 0){
    return -a;
  }
  else return a;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vi a(n);
    for(int i=0;i<n;i++){
      cin >> a[i];
    }
    vi b(n+1);
    for(int i=0;i<n+1;i++){
      cin >> b[i];
    }
    ll count=0;
    ll keep= b[n];
    int flag=0;
    for(int i=0;i<n;i++){
        count+=abso(b[i]-a[i]);
        if(((a[i]>=b[i]) && (keep >=b[i]) && (keep <=a[i]))&&(flag != 1)){
        count+=1;
        flag=1;
        }
        else if((a[i] < b[i]) && (keep <= b[i]) && (keep >= a[i]) && (flag != 1)){
          count +=1;
          flag=1;
        }
    }
  if(flag == 1){
  }
  else{
    b.pop_back();
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
      ll add1,add2;
      add2 =min(abso(keep-b[n-1]), abso(keep-a[n-1]));
      add1= min(abso(keep-b[0]), abso(keep-a[0]));
      count+= min(add1,add2)+1;
    }
    cout << count << endl;
  }

}


