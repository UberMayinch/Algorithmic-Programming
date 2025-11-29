#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int z=0;
        int o=0;
        if(s[0] == '1' || s[n-1] == '1' || s.find("11") != string::npos){
            o = 1;
        }
    
        if(o){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}