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

    // freopen("hard.in", "r", stdin);
    // freopen("hard.out", "w", stdout);
    
    vector<pair<int,int>>intervals;
    string line;
    
    while (getline(cin, line)) {
        pair<int,int>a = {-32768, 32767};
        size_t geq_pos = line.find(">=");
        size_t leq_pos = line.find("<=");


        
        if (geq_pos != string::npos) {
            size_t num_pos = line.find_first_of("-0123456789", geq_pos + 3);
            if (num_pos != string::npos) {
                string rest = line.substr(num_pos);
                stringstream ss(rest);
                ll num;
                if (ss >> num) {
                    a.first=num;
                }
            }
        }
        
        if (leq_pos != string::npos) {
            size_t num_pos = line.find_first_of("-0123456789", leq_pos + 3);
            if (num_pos != string::npos) {
                string rest = line.substr(num_pos);
                stringstream ss(rest);
                ll num;
                if (ss >> num) {
                    a.second = num;
                }
            }
        }
        
        intervals.push_back(a);
    }
    
    sort(intervals.begin(), intervals.end(), [](const pair<int,int>& A, const pair<int,int>& B) {
        return A.first < B.first;
    });


    vector<pair<int,int>> merged;
    if (!intervals.empty()) {
        merged.push_back(intervals[0]);
    }

    for (size_t i = 1; i < intervals.size(); i++) {
        if (intervals[i].first <= merged.back().second + 1) {
            merged.back().second = max(merged.back().second, intervals[i].second);
        } else {
            merged.push_back(intervals[i]);
        }
    }

    intervals = merged;
    bool flag = true;

    for(auto it: merged){

        if(it.first == -32768 && it.second == 32767){
            cout << "true" << endl;
            break;
        }
        else if(it.first > it.second && flag){
            cout << "false" << endl;
        }
        else if(it.first > it.second && !flag){
            continue; }

        else if(it.first == -32768){
            cout << "x <= " << it.second ;
            flag=false;
        }
        else if(it.second == 32767){
            cout << "x >= " << it.first; 
            flag=false;
        }
        else{
        cout << "x >= " << it.first << " && x <= " << it.second;
        flag=false;
        }
        if(it != merged.back()){
            cout << " ||" << endl;
        }
    }
    

    return 0;
}