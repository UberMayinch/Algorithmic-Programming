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
    int n;
    cin >> n;
    vi v(n+1, INT_MAX);
    v[n]=0;
    for(int i=n;i>=0;i--){
        if(v[i] != -1){
        int cp_n = i;
        vi dig;
        while(cp_n){
            dig.pb(cp_n % 10);
            cp_n /= 10;
        }
        for(auto it: dig){
            v[i-it] = min(v[i]+1, v[i-it]);
        }
        }
    }
    // for(auto it: v){
    //     cout << it << " ";
    // }
    // cout << endl;
    cout << v[0] << endl;

}