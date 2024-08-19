#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void mark_board(vector<vector<char>> &board, int row, int col, char mark) {
    for (int i = 0; i < 8; ++i) {
        board[row][i] = mark; // mark row
        board[i][col] = mark; // mark column
    }
    // mark diagonals
    for (int i = row, j = col; i < 8 && j < 8; ++i, ++j) board[i][j] = mark;
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) board[i][j] = mark;
    for (int i = row, j = col; i < 8 && j >= 0; ++i, --j) board[i][j] = mark;
    for (int i = row, j = col; i >= 0 && j < 8; --i, ++j) board[i][j] = mark;
}

int calc(vector<vector<char>> &board, int row) {
    if (row == 8) {
        return 1;
    }

    int count = 0;
    for (int i = 0; i < 8; ++i) {
        if (board[row][i] == '*') {
            vector<vector<char>> temp = board; // save current state
            mark_board(board, row, i, '&');
            count += calc(board, row + 1);
            board = temp; // restore state
        }
    }
    return count;
}

int main() {
    vector<vector<char>> board(8, vector<char>(8));
    for (int i = 0; i < 8; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; ++j) {
            board[i][j] = s[j];
        }
    }
    cout << calc(board, 0) << endl;
    return 0;
}
