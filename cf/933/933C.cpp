#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string x;
        cin >> x;
        int count = 0;
        size_t pos = 0;
        while ((pos = x.find("mapie", pos)) != string::npos) {
            count++;
            x.replace(pos, 5, "maie");
            pos += 4; }
        pos = 0; 
        while ((pos = x.find("map", pos)) != string::npos) {
            count++;
            pos += 3; 
        }
        pos = 0; 
        while ((pos = x.find("pie", pos)) != string::npos) {
            count++;
            pos += 3; 
        }
        cout << count << endl;
    }
    return 0;
}
