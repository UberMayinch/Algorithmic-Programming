#include <bits/stdc++.h>

using namespace std;
#define MOD 1e9+7
#define pb push_back 
#define mp make_pair
#define pii pair<int,int>
typedef vector<long long int>vi;
typedef long long int ll;

vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void generate_sequence(int index, int N, int K, const vector<int>& R, vector<int>& current_sequence, int current_sum) {
    if (index == N) {
        if (current_sum % K == 0) {
            for (int x : current_sequence) {
                cout << x << " ";
            }
            cout << endl;
        }
        return;
    }
    
    for (int i = 1; i <= R[index]; ++i) {
        current_sequence.push_back(i);
        generate_sequence(index + 1, N, K, R, current_sequence, current_sum + i);
        current_sequence.pop_back();
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> R(N);
    for (int i = 0; i < N; ++i) {
        cin >> R[i];
    }
    
    vector<int> current_sequence;
    generate_sequence(0, N, K, R, current_sequence, 0);
    
    return 0;
}
