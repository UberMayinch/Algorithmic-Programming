#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n, m;
    cin >> n >> m;
    vector <ll> v1(n);
    vector <ll> v2(m);
    for(int i=0;i<n;i++){
        cin >> v1[i];
    }
    for(int i=0;i<m;i++){
        cin >> v2[i];
    }
    ll sum = 0;
    for(int i=0;i<n-1;i++){
        sum += abs(v1[i]-v1[i+1]);
    }
    for(int i=0;i<m-1;i++){
        sum += abs(v2[i]-v2[i+1]);
    }
    cout << sum << endl;
}