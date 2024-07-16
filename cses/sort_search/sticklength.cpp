//  observation 1: values between two values of the array will have almost similar answer. Answer changes only at array values.
//  observation 2: The optimal value which all  entries should be reduced to is one of the values in the array. 
//  For a given value, the answer is computed in O(n)
//  Binary Search.


#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007 
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

ll solve(vector<ll>& v, ll pivot){
    ll sum = 0;
    for(int i = 0; i < v.size(); i++){
        sum += abs(v[i] - pivot);
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    ll start = 0;
    ll end = n - 1;
    ll pivot = v[(start + end) / 2];
    
    // Binary search to find the optimal pivot
    while(start <= end){
        ll mid = start + (end - start) / 2;
        ll left_cost = (mid > 0) ? solve(v, v[mid - 1]) : LLONG_MAX;
        ll right_cost = (mid < n - 1) ? solve(v, v[mid + 1]) : LLONG_MAX;
        ll mid_cost = solve(v, v[mid]);
        
        if(mid_cost <= left_cost && mid_cost <= right_cost){
            pivot = v[mid];
            break;
        }
        else if(mid_cost > left_cost){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    
    cout << solve(v, pivot) << endl;

    return 0;
}
