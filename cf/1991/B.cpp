#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

vector<uint32_t> constructNewArray(const vector<uint32_t>& input) {
    int n = input.size();
    vector<uint32_t> result(n + 1);
    result[0] = input[0];
    
    result[1] = ((1U << 30)-1);  
    
    for (int i = 2; i <= n; ++i) {
        uint32_t previous = result[i - 1];
        uint32_t previous_and = input[i-1] & result[i - 1];
        result[i] = ~previous | previous_and;
    }

    for(int i=2;i<n+1;i++){
      result[i]=result[i] & result[1];
  }
    
    return result;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<uint32_t> v(n-1);
        for(int i = 0; i < n-1; i++){
            cin >> v[i];
        }
        int flag = 0;
        for(int i = 1; i < n-2; i++){
            if(v[i] < v[i+1]){
                flag = 1;
                break;
            }
        }
        if(flag != 1){
            vector<uint32_t> result = constructNewArray(v);
            for (uint32_t val : result) {
                cout << val << " ";
            }
            cout << endl;
        } else {
            cout << "-1" << endl;
        }
    }
    return 0;
}
