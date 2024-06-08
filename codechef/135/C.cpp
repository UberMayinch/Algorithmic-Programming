#include <bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
#define mp make_pair

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n;
        vi v(n);
        for(int i=0;i<n;i++){
            cin >> v[i];
        }
        int dist = (n-1)*(max(v[0], v[n-1]));
        priority_queue<pair<int,int>> myQ;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(j*(max(v[i], v[j])) < dist){
                    myQ.insert(mp(j*max(v[i], v[j]), j+1));
                }
            }
        }
        pair<int, int> ele;
        while(ele.second != n){
            ele = priority_queue.pop();    
        }
        
        
    }
}
