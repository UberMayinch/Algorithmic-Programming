#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll k, n;
    cin >> k >> n;
    // unordered_map <ll,ll>m;
    // for(int i=0;i<k*k;i++){
    //     m[i]++;
    //     // cout << i << endl;
    // }
    ll idx=0;
    int flag=1;
    while(idx != k*k-1){
        cout << (idx / k) + 1 << " " << (idx % k) + 1<< endl;
        n--;
        // m[idx]++;
        // m[idx]--;
        if(flag){
            idx += k;
            flag = !flag;
        }
        else{
            idx+=1;
            flag =!flag;
        }
        // cout << flag << endl;
    }
    if(idx == k*k-1){
        cout << (idx / k) + 1 << " " << (idx % k) + 1<< endl;
        n--;
        // m[idx]++;
        // m[idx]--;
        cout << 1 << " " << k << endl;
        n--;
        // m[k-1]++;
        // m[k-1]--;
    }
    // cout << n << endl;
    
    // for(int i=0;i<k*k && n;i++){
    //     if(m[i] != 1 && n > 0){
    //         cout << (i / k) + 1 << " " << (i % k) + 1<< endl;
    //         m[idx]++;
    //         n--;
    //     }
    //     if(n <= 0){
    //         break;
    //     }
    // }

    while(n > 0) {
        for(int i=0; i < k && n > 0; i++) {
            for(int j = 0; j < k && n > 0; j++) {
                if(j != i && j != (i-1 + k)%k) {
                    cout<<i+1<<' '<<j+1<<'\n';
                    n--;
                    // cout<<n<<endl;
                }
            }
        }
    }
}