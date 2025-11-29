#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<ll> mergeSortDriver(vector<ll>& arr, ll start, ll end) {
    if (start == end) {
        return {arr[start]};
    }

    ll mid = start + (end - start) / 2;
    vector<ll> a = mergeSortDriver(arr, start, mid);
    vector<ll> b = mergeSortDriver(arr, mid + 1, end);

    ll ida = 0;
    ll idb = 0;
    ll idn = 0;
    vector<ll> n(end - start + 1);

    while (ida < a.size() || idb < b.size()) {
        if (idb == b.size()) {
            n[idn++] = a[ida++];
        } else if (ida == a.size()) {
            n[idn++] = b[idb++];
        } else if (a[ida] < b[idb]) {
            n[idn++] = a[ida++];
        } else {
            n[idn++] = b[idb++];
        }
    }
    return n;
}

vector<ll> mergeSort(vector<ll>& arr) {
    int n = arr.size();
    return mergeSortDriver(arr, 0, n - 1);
}

int main() {
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    v = mergeSort(v);
    for (auto it : v) {
        cout << it << " ";
    }
    return 0;
}
