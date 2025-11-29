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

        // Sort the vector by frequency in descending order
        sort(freqVec.begin(), freqVec.end(), greater<pair<int, char>>());

        string result;
        // Append one instance of each character in sorted order until all are processed
        while (!freqVec.empty()) {
            vector<pair<int, char>> newFreqVec;
            for (auto& pair : freqVec) {
                result += pair.second;
                if (--pair.first > 0) {
                    newFreqVec.push_back(pair);
                }
            }
            freqVec = newFreqVec;
        }

        cout << result << endl;
    }
    return 0;
}
