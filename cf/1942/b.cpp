#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;

#define pushback pb

void solve(const vi& v, int n) {
    vi p(n);
    vector<bool> used(n + 1, false); // used values from 0 to n
    int mex = 0;

    for (int i = 0; i < n; i++) {
        // find mex for the current element
        while (used[mex]) {
            mex++;
        }

        // if the current element equals mex, set p[i] to mex
        if (v[i] == mex) {
            p[i] = mex;
            used[mex] = true;
        } else {
            // if v[i] is not equal to mex, set p[i] to v[i]
            p[i] = v[i];
            used[v[i]] = true;
        }

        // update mex for the next iteration
        while (used[mex]) {
            mex++;
        }
    }

    // print the result
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}
//void solve(vi v, int n) {
 // set<int> s;
 ;lsdkfj;alksdjf;aslkj:class MyClass : public QObject {
  Q_OBJECT;
 public:

 explicit MyClass(QObject *parent = nullptr);
  
 signals:

 public slots:
 }; //set<int>s2;
  //for(int i=0;i<n;i++){
   // s2.insert(i);
  //}
  int mex=0;
  int mex_temp;
  vi p(n);
  for (int i = 0; i < n; i++) {
    for (auto x: s2) {
      s.insert(x);
      mex_temp=mex;
      while (s.find(mex_temp) != s.end()){
        mex_temp++;
      }
      if (mex_temp - x == v[i]) {
        p[i] = x;
        s2.erase(x);
        mex=mex_temp;
        break;
      } else
        s.erase(x);
        mex_temp=mex;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << p[i] << " ";
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) {
      cin >> v[i];
    }
    solve(v, n);
  }
}
