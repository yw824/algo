#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N; // n 받기

  // n보다 작으면 인덱스 하나씩 줄여가기
	int i = 1 ;
	while ( N > i ) {
		N -= i ;
		i++ ;
	}

  
	if ( i % 2 )
		cout << i + 1 - N << '/' << N << "\n" ;
	else
		cout << N << '/' << i + 1 - N << "\n" ;
}
