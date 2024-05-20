#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Binary search function to find the target value in the vector of pairs
int binarySearch(const vector<pair<int, int>>& v, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid].first == target) {
            return v[mid].second; // Return the original index
        }
        if (v[mid].first < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Return -1 if target is not found
}

int main() {
    int n, x;
    cin >> n;
    cin >> x;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i; // Store the original index
    }

    for (int i = 0; i < n; ++i) {
        sort(v.begin() + i + 1, v.end());

        for (int j = i + 1; j < n; ++j) {
            int target = x - v[i].first + v[j].first;
            int foundIndex = binarySearch(v, j, n , target);
            if (foundIndex != -1) {
                cout << v[i].second+1 << " " << v[j].second+1 << " " << foundIndex+j+1 << endl;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
