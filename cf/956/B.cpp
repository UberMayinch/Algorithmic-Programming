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
    int n,m;
    cin >> n >> m;
    vector<<vector<int>> A(n,(vector<int>(m)));
    vector<<vector<int>> B(n,(vector<int>(m)));
    string S;
    vector<int> rowsA;
    vi rowsB;
    int sum;
    for(int i=0;i<n;i++){
      cin >> S;
      sum=0;
      for(int j=0;j<m;j++){
        A[i][j]=S[j];
        sum+=A[i][j];
        sum = sum%3;
      }
      rowsA.pb(sum);
    }
    for(int i=0;i<n;i++){
      cin >> S;
      sum=0;
      for(int j=0;j<m;j++){
        B[i][j]=S[j];
        sum+=B[i][j];
        sum = sum%3;
      }
      rowsB.pb(sum);
    }
    int flag=0;
    for(int i=0;i<n;i++){
      if(rowsA[i] != rowsB[i]){
        flag=1;
        break;
      }
    }
    if(flag != 1){
      vector<int>colsA;
      vector<int> colsB;
      for(int i=0;i<m;i++){
        sum=0;
        for(int j=0;j<n;j++){
          sum+=A[j][i];
          sum = sum %3;
        }
        colsA.pb(sum);
      }

      for(int i=0;i<m;i++){
        sum=0;
        for(int j=0;j<n;j++){
          sum+=B[j][i];
          sum = sum %3;
        }
        colsB.pb(sum);
      }

      for(int i=0;i<m;i++){
        if(colsA[i] != colsB[i]){
          flag=1;
          break;
        }
      }
    }

    if(flag == 1){
      cout << "NO" << endl;;
    }
    else{
      cout << "YES" << endl;
    }
  }

}


