#include <bits/stdc++.h>
using namespace std;

void solve(long long int n){
 if (n*(n+1) % 4 == 0){
  cout << "YES" << "\n";
  long long int sum = (n*(n+1) / 4);
  vector<long long int>a ={};
  for(long long int i=1;i<n+1;i++){
    a.push_back(i);
  }
  long long int count=0;
  set<long long int>new_set(a.begin(), a.end());
  vector<long long int>b={};
  for(long long int i=n;i>0;i--){ 
    if(sum - i >= 0){
      sum -=i;
      new_set.erase(i);
      b.push_back(i);
      count+=1;
    }
  }
  cout << count << endl;
  for(auto c: b){
    cout << c << " ";
  }
  cout << endl << n-count << endl;
  for(auto item: new_set){
    cout << item << " ";
  }
  }
else{
 printf("NO");
  
  }
}

int main(){
  long long int n;
  cin >> n;
  solve(n);
}
