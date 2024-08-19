#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
#define vi vector<int>

vector<int> constructNewArray(const vector<int>& input) {
    int n = input.size();
    vector<int> result(n + 1);
    result[0] = input[0];
    
    int MAX_30_BIT = (1U << 30) - 1; 
    result[1] = MAX_30_BIT;
    
    for (int i = 2; i <= n; ++i) {
        int previous = result[i - 1];
        int previous_and = input[i-1] & result[i - 1];
        result[i] = (~previous | previous_and) & MAX_30_BIT; 
        if(~previous && previous_and){
      result = {-1};
      return result;
    }
    }
    
    return result;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi v(n-1);
        for (int i = 0; i < n-1; ++i) {
            cin >> v[i];
        }
            vector<int> result = constructNewArray(v);
            for (int val : result) {
                cout << val << " ";
            }
            cout << endl;
        } 

    return 0;
}
