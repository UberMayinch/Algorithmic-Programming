#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    set<int> mySet;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        mySet.insert(i + 1);
    }
    auto it = mySet.begin();
    while(!mySet.empty()) {
        // Advance the iterator by 1
        it = next(it);
        // If we have reached the end, wrap around to the beginning
        if (it == mySet.end()) {
            it = mySet.begin();
        }
        // Print the element to be erased
        cout << *it << " ";
        // Store the next position before erasing
        auto toErase = it;
        // Move to the next element
        it = next(it);
        // Erase the current element
        mySet.erase(toErase);
        // If we reached the end, wrap around to the beginning
        if (it == mySet.end()) {
            it = mySet.begin();
        }
    }
    return 0;
}
