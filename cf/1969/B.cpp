#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.size();
    int i = 0;
    long long int sum = 0;
    long long int one_count = 0;
    long long int zero_count = 0;
    while (i < n) {
      if (s[i] == '1') {
        one_count += 1;
        i++;
      } else if (s[i] == '0') {
        if(one_count != 0){

        sum +=(one_count+1);
        }
        i++;
      }
    }
    cout << sum << endl;
  }
}
