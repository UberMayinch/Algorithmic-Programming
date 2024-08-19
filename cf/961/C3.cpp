#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        
        bool flag = false;
        int count = 0;
        int power = 1;

        for (int i = 1; i < n; ++i) {
            if (v[i-1] > 1 && v[i] == 1) {
                flag = true;
                break;
            }

            double log_v_i = log2(v[i]);
            double log_mx = power * log2(v[i-1]);

            if (log_mx == 0) {
                count += 0;
            } else {
                if (log_v_i < log_mx) {
                    double required_steps = ceil(log2(log_mx / log_v_i));
                    count += static_cast<int>(required_steps);
                    power = pow(2, static_cast<int>(required_steps));
                } else {
                    power = 1;
                }
            }
        }

        if (flag) {
            cout << "-1" << endl;
        } else {
            cout << count << endl;
        }
    }

    return 0;
}
