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
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int ans = 0;
    int mx;
    unordered_map<int,vector<int>>m;

    // query to find length of largest path in n-1 component
    for(int i=1;i<=n-1;i++){
        cout << "? "<< i << " " << n-1;
        for(int j=1;j<= n-1;j++){
            cout << " " << j;
        }
        cout << endl;
        cin >> mx;
        ans = max(mx, ans);
        m[mx].push_back(i);
    }

    vector<int>path;
    int temp;
    for(int i=2;i<=mx;i++){
        if(m[i].size() == 1)
            path.push_back(m[i][0]);
            else{
                for(int q = 0;q < m[i].size();q++){
                    // query to check which node is connected to component (check connection
                    // to latest edge)
                    cout << "? " << m[i][q] << " 2 " << m[i][q] << path[path.size()-1];
                    cout << endl;
                    cin >> temp;
                    if(temp == 2){
                        path.push_back(m[i][q]);
                        break;
                    }
                }
            }
    }

    //querying to check whether the remaining node is connected to first or last node in path. 
    cout << "? " << n << " 2 " << path[path.size()-1] << n;
    cin >> temp;
    if(temp == 2){
        path.insert(path.begin(), n);
    }
    cout << "? " << path[0] << " 2 " << path[path.size()-1] << n;
    cin >> temp;
    if(temp == 2){
        path.push_back(n);
    }
    
    cout << "! " << path.size();
    for(auto node: path){
        cout << " " << node;
    }
    cout << endl;
  }
}