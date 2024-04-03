#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> solve(int n, int source, int destination, int auxiliary) {
    vector<pair<int, int>> moves;

    if (n == 1) {
        moves.push_back({source, destination});
    } else {
        vector<pair<int, int>> temp = solve(n - 1, source, auxiliary, destination);
        moves.insert(moves.end(), temp.begin(), temp.end());

        moves.push_back({source, destination});

        temp = solve(n - 1, auxiliary, destination, source);
        moves.insert(moves.end(), temp.begin(), temp.end());
    }
    return moves;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> moves = solve(n, 1, 3, 2);
    
    cout << moves.size() << endl;
    for (const auto& move : moves) {
        cout << move.first << " " << move.second << endl;
    }

    return 0;
}
