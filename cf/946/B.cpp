#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define push_back pb
typedef vector<long long int>vi;
typedef long long int ll;
vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi freq(26, 0);
    for(int i=0;i<n;i++){
      freq[int(s[i]-'a')] = 1;
    }
    int j=25;
    int i=0;
    while(i <= j){
      if((freq[j] == 1) && (freq[i] == 1)){
        freq[j]=i;
        freq[i]=j;
        i++;
        j--;
      } 
      else{
        if(freq[i] == 0){
          i++;
        }
        if(freq[j] == 0){
          j--;
        }
      }
    }
    // for(int i=0;i<26;i++){
    //   cout << freq[i] << " ";;
    // }
    for(int i=0;i<n;i++){
      s[i] = char(freq[s[i]-'a']+'a');
    }
    cout << s << endl;
  }

}


