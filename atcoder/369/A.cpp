#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if(b == a) cout << 1 << endl;
    else if(abs(b - a) % 2) cout << 2 << endl;
    else cout << 3 << endl;
}