#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if (n == 2)
        {
            cout << 66 << endl;
        }
        else if (n % 2 == 0)
        {
            string result;
            for(int i=0;i<n-2;i++){
                result+='3';
            }
            cout << result + "66" << endl;
        }
        else if(n > 4){
            string result;
            for(int i=0;i<n-4;i++){
                result+='3';
            }
            cout << result + "6366" << endl;

        }
        else
            cout << -1 << endl;
    }
}