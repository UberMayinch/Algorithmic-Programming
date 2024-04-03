#include <bits/stdc++.h>
using namespace std;

int solve(int** board){
  int count = 0;
  for (int i = 0; i < 8; i++) {
    if (board[0][i] == '*') {
      board[0][i] = '+';
      for(int i=0;i<8;i++){
        if(board[0][i] != '*'){
          board[0][i]='+';
        }
      }
      for (int j = 0; j < 8; j++) {
      
      }
    }
    cout << "\n";
  }
  return count;
}

int main() {
  char board[8][8];
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cin >> board[i][j];
    }
  }
  cout << solve(board);
  return 0;
}
