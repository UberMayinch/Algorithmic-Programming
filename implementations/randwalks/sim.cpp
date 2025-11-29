#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate_swn(int n, int k, int p, ofstream& file)
{
    vector<set<int>> G(n);
    for (int i = 0; i < n - k + 1; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int chk = rand() % 1000;
            if (chk < p)
            {
                int tgt = rand() % n;
                G[i].insert(tgt);
                G[tgt].insert(i);
                file << i << " " << tgt << endl;
            }
            else
            {
                G[i].insert((i + j) % n);
                G[i].insert(((i - j)+n) % n);
                G[((i - j) + n)% n].insert(i);
                G[(i + j) % n].insert(i);
            }
        }
    }

    vector<vector<int>> ans;
    for (auto& it : G) {
        ans.push_back(vector<int>(it.begin(), it.end()));
    }

    return ans;
}

int random_walk_start(vector<vector<int>> G, int tgt, int cutoff)
{
    int curr = 0;
    int time = 0;
    int transitions;
    while (time < cutoff && curr != tgt)
    {
        transitions = G[curr].size();
        curr = G[curr][rand() % transitions];
        time++;
    }
    return time;
}

int main()
{

    srand(time(0));
    ofstream file;
    file.open("results.csv");

    int n, k, p;
    cin >> n >> k >> p;
    for (int ensemble = 0; ensemble < 1; ensemble++)
    {
        vector<vector<int>> G = generate_swn(n, k, p, file);
        int tgt = 50;
        vector<int> ans;
        for (int i = 0; i < 100000; i++)
        {
            ans.push_back(random_walk_start(G, tgt, 5000));
        }

        for (auto it : ans)
        {
            file << it << ", ";
        }
        file << endl;
    }
    file.close();
}