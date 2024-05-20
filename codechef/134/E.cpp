#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vi v(n);
        vi qu(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        for(int i=0;i<q;i++){
            cin >> qu[i];
        }
        vi v2 = v;
        for(int i=0;i<q;i++){
            v = v2;
            sort(v.begin(), v.begin()+qu[i]);
           long long int sum=0;
            for(int j=0;j<qu[i]/2;j++){
                sum -=v[j];
            }
            for(int j=qu[i]/2;j<qu[i];j++){
                sum += v[j];
            }
            cout << sum << " ";
        }
        cout << endl;
    }
}
