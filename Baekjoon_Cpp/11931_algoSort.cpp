#include <iostream>
using namespace std;

int n, arr[1000000];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i{ 0 }; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i{ n - 1 }; i >= 0; i--) {
		cout << arr[i] << '\n';
	}
