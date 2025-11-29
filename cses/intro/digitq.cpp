#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

long long pow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main(){
    int i=1;
    ll sum=0;
    vector<pair<ll,int>>pre;
    pre.push_back({0, 1});
    while(i < 18){
        sum += i * (pow(10, i) - pow(10, i-1));
        i+=1;
        pre.push_back({sum, i});
    }

    int q;
    ll k;
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> k;
        auto it = upper_bound(pre.begin(), pre.end(), pair<ll,int>{k, 0}, [](pair<ll,int>a, pair<ll,int>b){return a.first < b.first;});
        --it;
        k = k - it->first-1;

        ll nums = k / it->second;

        ll curr = ((it->second != 1)?pow(10, it->second-1):0) + nums;
        // cout << curr << endl;
        auto ans = to_string(curr)[k % it->second];
        cout << ans << endl;
    }

}