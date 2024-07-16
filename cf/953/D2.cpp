#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007 // Corrected MOD definition
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
    while (t--) {
        int n, c;
        cin >> n >> c;
        vi v(n);
        vector<pii> original(n); 

        for (int i = 0; i < n; i++) {
            cin >> v[i];
            original[i] = mp(v[i], i);
        }

        sort(original.begin(), original.end());

        vector<int> greaterCount(n, 0);
        for (int i = 0; i < n; i++) {
            greaterCount[original[i].second] = n - i - 1;
        }

      //create a prefix sum array of the original array
    //create a suffix sum array of the sorted array
       
        // Iterate over each element in the original vector
        for (int i = 0; i < n; i++) {
              if(greaterCount[v[i]] == 0 && v[i] > c){
        cout << "0" << endl;
      }
          else{
        int low=i;
        int high=n-1;
        int k=(low+high)/2;
        while(low <= high){
          if(prefix[i+k]+sufix)
        }
      }
            }
            if (!found) {
                cout << n - 1 << endl;
            }
        }
    }

    return 0;
}
