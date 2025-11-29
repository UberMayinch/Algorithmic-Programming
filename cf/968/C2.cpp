#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        string input;
        cin >> input;

        map<char, int> frequencyMap;
        for (char c : input) {
            frequencyMap[c]++;
        }

        vector<pair<int, char>> freqVec;
        for (const auto& pair : frequencyMap) {
            freqVec.emplace_back(pair.second, pair.first);
        }

        // Sort the vector by frequency in ascending order
        sort(freqVec.begin(), freqVec.end());

        string result;
        for (const auto& pair : freqVec) {
            result.append(pair.first, pair.second);
        }

        cout << result << endl;
    }
    return 0;
}
