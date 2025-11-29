#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll rem = 0;
		for(int i=0;i*(i+1)<n;i++){
			cout << i << " " << 0 << endl;
			rem = n - i*(i+1);
		}
	
	}

}
