#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

ll mergeAndCount(vi &arr, int l, int r) {
    if (l >= r) return 0;
    int mid = l + (r - l) / 2;
    
    ll inv_count = 0;
    inv_count += mergeAndCount(arr, l, mid);
    inv_count += mergeAndCount(arr, mid + 1, r);
    
    vi temp(r - l + 1);
    int i = l, j = mid + 1, k = 0;
    
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1); 
        }
    }
    
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    
    for (int i = l; i <= r; i++) arr[i] = temp[i - l];
    
    return inv_count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        
        vi a = v;
        
        ll inv = mergeAndCount(a, 0, n - 1);
    cout << inv << endl;
        (inv % 2) ? cout << "NO" : cout << "YES";
        cout << endl;
    }
}
