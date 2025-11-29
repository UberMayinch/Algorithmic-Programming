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
  ll t;
  cin >> t;
  while(t--) {
    ll n, s;
    cin >> n >> s;
    vector<pair<int,int>>dir(n);
    vector<pair<int,int>>start(n);
    for(int i=0;i<n;i++){
        cin >> dir[i].first >> dir[i].second;
        cin >> start[i].first >> start[i].second;
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        bool flag=false;
        float a,b;
        a = start[i].first;
        b = start[i].second;
        if(dir[i].first > 0 && dir[i].second > 0){
            a = s - start[i].first;
            b = s - start[i].second;
        }
        else if(dir[i].first > 0 && dir[i].second < 0){
            //4, 0
            a = s - start[i].first;
            b = -start[i].second;
        }
        else if(dir[i].first < 0 && dir[i].second > 0){
            //0,4
            a = -start[i].first;
            b = s - start[i].second;
        }
        else if(dir[i].first < 0 && dir[i].second < 0){
            a = -start[i].first;
            b = -start[i].second;
        }
        if(a / dir[i].first == b / dir[i].second)flag=true;
        if(flag)cnt++;
    }
    cout << cnt << endl;
    
  }
}