#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s = "";
        if(n == 1){
            cout << 0 << endl;
        }
        else{
        for(int i=0;i<n;i++){
            if(i  == 1){
                s +="1";
            }
            else s+="0";
        }
            cout << s << endl;
        }
    }
}