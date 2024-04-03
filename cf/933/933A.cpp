#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m, k;
        cin >> n >> m >> k;
        vector<int>v1(n);
        vector<int>v2(m);
        for(int z=0;z<n;z++){
            cin >> v1[z];
        }
        for(int k=0;k<m;k++){
            cin >> v2[k];
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v1[i]+v2[j]<=k){
                    count++;
                }
            }
        }
        cout << count << "\n";
    }
}