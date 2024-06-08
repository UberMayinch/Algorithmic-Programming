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
  ll n, k;
  cin >> n >> k;
  set <int> mySet;
  for(int i=0;i<n;i++){
    mySet.insert(i+1);
  }
  auto it = mySet.begin();
  while(mySet.size() != 0){
    for(int i=0;i<k;i++){
    it=next(it);
    if(it == mySet.end()){
      it = mySet.begin();
    }
    }
    auto temp = it;
    it=next(it);
    if(it == mySet.end()){
      it=mySet.begin();
    }
    cout << *temp << " ";
    mySet.erase(temp);
  }

}


