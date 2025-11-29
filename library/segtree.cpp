#include <bits/stdc++.h>
using namespace std;


vector<int> init(vector<int>& arr){
    int two_pac = (int)ceil(log2(arr.size()));
    int sz = (int)pow(2, two_pac);
    vector<int> tree(sz, -1);
    for(int i = sz / 2;i<sz/2;i++){
        if(i < arr.size()){
            tree[i] = arr[i];
        }
        else tree[i]=0;
    }
    return tree;

}

void build_drive(vector<pair<int,pair<int,int>>>& tree, int idx){
    if(tree[idx].first == -1){
        build_drive(tree, 2*idx);
        build_drive(tree, 2*idx+ 1);
        tree[idx].first = tree[2*idx].first + tree[2*idx+1].first;
        tree[idx].second = {tree[2*idx].second.first, tree[2*idx+1].second.second};
    }
    else return;
}
void build(vector<int>& arr, vector<pair<int,pair<int,int>>>& tree){
    if(tree.size() == 0){
        auto tree = init(arr);
    }
    else{
        build_drive(tree, 1);
    }
    return;
}

int query(int idx, int l, int r, vector<pair<int,pair<int,int>>>& tree){
    if(tree[idx].second.first == l)

}

int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    vector<pair<int,pair<int,int>>> tree;
    build(v, tree);

}