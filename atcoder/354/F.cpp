#include <bits/stdc++.h>
using namespace std;
#define MOD 1e9+7
#define push_back pb
typedef vector<long long int>vi;
typedef long long int ll;
vector<array<int, 2>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int lis(int arr[], int n)
{
	int lis[n];

	lis[0] = 1;

	for (int i = 1; i < n; i++) {
		lis[i] = 1;
		for (int j = 0; j < i; j++)
			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
	}

	return *max_element(lis, lis + n);
}

// Driver program to test above function
int main()
{
	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	printf("Length of lis is %d\n", lis(arr, n));
	return 0;
}
