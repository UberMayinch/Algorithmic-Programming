#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int calc(vector<vector<char>> board, int count, int row){
  for(int i=0;i<8;i++){
    if(board[row][i] == '*'){
      board[row][i]='&';
      //change rows
      //change columns
      for(int j=row;j<8;j++){
        board[j][i]='&';
      }
      //change diagonals
      int e = i+1;
      for(int j=row+1;j<8;j++){
        e+=1;
        board[row][e]='&';
      }
      if(row == 8){
        for(auto it:board){
          for(auto ia: it){
            cout << ia;
          }
        cout << endl;
        }
        count++;
        return count;
      }
      count += calc(board, count, row+1);
    }
      board[row][i] = '*';
      //change rows
      //change columns
      for(int j=row;j<8;j++){
        board[j][i]='*';
      }
      //change diagonals
      for(int j=row+1;j<8;j++){
        i+=1;
        board[row][i]='*';
      }
  }
  return count;
}

int main(){
  vector<vector<char>> board(8, vector<char>(8));
  for(int i=0;i<8;i++){
    string s;
    cin >> s;
    for(int j=0;j<8;j++){
      board[i][j]=s[j];
    }
  }
  int count=0;
  cout << calc(board, count, 0) << endl;
}


