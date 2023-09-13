#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 벡터를 배열처럼 사용 가능
bool next_permutation(int *a, int n) {
	int i = n - 1;
	while ( i > 0 && a[i] <= a[i - 1]) i -= 1;
	if (i <= 0) return false;
	int j = n - 1;
	while (a[i-1] >= a[j]) j -= 1;
	swap(a[i - 1], a[j]);
	j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i += 1; j -= 1;
	}
	return true;
}

int main()
{
	vector<int> p;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		p.push_back(i+1);
	} /* end of input */

	do {
		for (int i = 0; i < n; i++)
			cout << p[i] << ' ';
		cout << '\n'; // print per next_permutaion
	} while (next_permutation(p.begin(), p.end()));

	return 0;
}
