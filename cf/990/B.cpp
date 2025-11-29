#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char,int> m;
    for(int i=0;i<n;i++){
        m[s[i]]++;
    }
    char max_char = s[0], min_char = s[0];
    int max_freq = m[s[0]], min_freq = m[s[0]];
    for(auto &p : m) {
        if(p.second > max_freq) {
            max_char = p.first;
            max_freq = p.second;
        }
        if(p.second < min_freq) {
            min_char = p.first;
            min_freq = p.second;
        }
        else if(p.second == min_freq && p.first != max_char){
            min_char = p.first;
            min_freq = p.second;
        }
    }
    // cout << "Max: " << max_char << " " << max_freq << endl; cout << "Min: " << min_char << " " << min_freq << endl;
    for(int i = 0; i < n; i++) {
        if(s[i] == min_char) {
            s[i] = max_char;
            break;
        }
    }
    cout << s << endl;
    
  }
}