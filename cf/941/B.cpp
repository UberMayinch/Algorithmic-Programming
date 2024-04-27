#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n, m;
    cin >> n >> m;
    char board[n][m];
    for(int i=0;i<n;i++){
      cin >> board[i];
    }
    if(board[0][0] == board[n-1][m-1]){
      cout << "YES" << endl;
      continue;
    }
    else{
      int first_col=0;
      int first_row=0;
      int last_col=0;
      int last_row=0;
    for(int i=0;i<n-1;i++){
      if(board[i][0] != board[i+1][0]){
        first_col = 1;
        break;
      }
    }
        for(int j=0;j<m-1;j++){
          if(board[0][j] != board[j+1][0]){
            first_row=1;
            break;
          }
      }

    for(int i=0;i<n-1;i++){
      if(board[i][m-1] != board[i+1][m-1]){
        last_col = 1;
          break;
      }
    }

    for(int i=0;i<m-1;i++){
      if(board[n-1][i] != board[n-1][i]){
        last_row = 1;
          break;
      }
    }

    if((last_row && last_col) || (first_row && first_col) || (first_row && last_col) || (last_row && first_col))
      cout << "YES" << endl;
    else cout << "NO" << endl;;
    }
    // for(int i=0;i<n;i++){
    //   for(int j=0;j<m;j++){
    //     cout << board[i][j];
    //   }
    //   cout << endl;
    // }
  }
}
