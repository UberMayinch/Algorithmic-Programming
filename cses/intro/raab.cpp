#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main() {
    int n;
    cin >> n;
    int a,b,c;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        if(!(b == 0 && c == 0) || (b + c > a)){
            cout << "NO" << endl;
        }
        else{

        }

    }
}