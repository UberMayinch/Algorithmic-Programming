#include <bits/stdc++.h>
using namespace std;

#define MOD 1e9+7
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

bool check(string s, int p) {
  int n = s.size();
  int times = n/p;
  int flag=0;
  for(int i=0;i<times;i++){
    if(flag){
      break;
    }
    for(int j=0;j<p-1;j++){
      if(s[i*p+j] == s[i*p+j+1]){
        continue;
      }
      else flag=1;
      break;
    }
  }
  if(flag) return false;
  else return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int count1 = 0;
        int count0 = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                count1++;
            } else {
                count0++;
            }
        }

        if (count0 % k != 0 && count1 % k != 0) {
            cout << "-1" << endl;
        } else {
      int pos;
            int count = 1;
            string b;
            for (int i = n - 1; i >= 1; i--) {
                if (s[i] == s[i - 1]) {
                    count++;
                } else {
                    break;
                }
            }

            for (int i = 0; i < k - count; i++) {
                b += s[n - 1];
            }
            string a="0";
            if(s[n-1] == '1')a="1"; 
            for(int i=0;i<k-1;i++){
            a+=a[0]; 
      }
            if (b.empty()) {
                if (check(s, k)) {
                    cout << k << endl;
                } else {
                    cout << "-1" << endl;
                }
                continue;
            }

            size_t lastIndex = s.rfind(b, pos);
            // cout << lastIndex << count << k << endl;
            if (lastIndex != string::npos) {
      
                string newStr = s.substr(0,lastIndex+k-count);
                string new2 = s.substr(lastIndex + k-count);
                reverse(newStr.begin(), newStr.end());
                string c = new2 + newStr;
                    // cout << lastIndex << " " << count << " ";
        // cout << c << endl;
                if (check(c, k)) {
                    cout << lastIndex + k - count << endl;
                } else {
                    cout << "-1" << endl;
                }
            } else {
                cout << "-1" << endl;
            }
        }
    }
    return 0;
}
