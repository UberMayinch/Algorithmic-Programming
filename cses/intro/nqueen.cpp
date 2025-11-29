#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void calc(vector<vector<int>>&board, int& count, int row){
  if(row == board.size()-1){
    for(int i=0;i<board[row].size();i++){
      if(board[row][i] == 0){
        count++;
      }
    }
    return;
  }
  else{
    for(int i=0;i<board[row].size();i++){
      if(board[row][i] == 0){
      
        for(int j=row;j<board.size();j++){
          if(board[j][i] != -1){
            board[j][i]+=1;
          }
          for(int j=1;j<(board.size()-row);j++){
            if(j + row < board.size() && i + j < board[row].size()){
              if(board[j+row][i+j] != -1){
                board[j+row][i+j] += 1;
              }
            }
            if(j + row < board.size() && i - j >= 0){
              if(board[j+row][i-j] != -1){
                board[j+row][i-j] += 1;
              }
            }
          }
        }
        calc(board, count, row+1);

        for(int j=row;j<board.size();j++){
          if(board[j][i] != -1){
            board[j][i]-=1;
          }
          for(int j=1;j<(board.size()-row);j++){
            if(j + row < board.size() && i + j < board[row].size()){
              if(board[j+row][i+j] != -1){
                board[j+row][i+j] -= 1;
              }
            }
            if(j + row < board.size() && i - j >= 0){
              if(board[j+row][i-j] != -1){
                board[j+row][i-j] -= 1;
              }
            }
          }
        }
      }
  }
  return;
}
}

int main(){
  vector<vector<char>> board(8, vector<char>(8));
  vector<vector<int>> board_state(8, vector<int>(8));
  for(int i=0;i<8;i++){
    string s;
    cin >> s;
    for(int j=0;j<8;j++){
      board[i][j]=s[j];
    }
  }
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      board_state[i][j]=(board[i][j] == '*'?-1:0);
      // cout << board_state[i][j];
    }
    // cout << endl;
  }
  int count=0;
  calc(board_state, count, 0);
  cout << count << endl;

}


