#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007  
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int> vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int main(){
    ll t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> G(n);
        set<pii> edgesSet;  
        int flag = 0;
        int queries = 15 * n;
        int prev_query = n;
        vi edges(n, 0);
        int node = 0;
        int idx = 1;
        
        while(queries && !flag){
            int found = 0;
            int query = prev_query;

            while(!found && queries){
                if (query == idx) {
                    prev_query = query;  
                    query = node;       
                    continue;
                }
                
                cout << "? " << idx << " " << query << endl;
                cout.flush();  
                queries--;
                cin >> node;

                if(node == idx){
                    found = 1;
                    G[idx-1].push_back(query);
                    edges[idx-1] = 1;
                    edgesSet.insert(minmax(idx, query)); 
                    break;
                } else {
                    prev_query = query;
                    query = node;
                }
            }

            if(find(edges.begin(), edges.end(), 0) == edges.end()){
                flag = 1;
            }
            else{
                idx = distance(edges.begin(), find(edges.begin(), edges.end(), 0)) + 1;
            }

        }
        
        cout << "! ";
        cout.flush();  
        for(auto edge : edgesSet){
            cout << edge.first << " " << edge.second << " ";
            cout.flush();  
        }
        cout << endl;
        cout.flush();  
    }
    return 0;
}
