#include <iostream>
using namespace std;

int solution(int n) {
	int sum = n;
	while (n) {
		sum = sum + n % 10;
		n /= 10;
	}
	return sum;
}

int main() {
	int N;
	cin >> N;

	for (int i = 1; i < N; i++) {
		int sum = solution(i);
		if (sum == N) {
			cout << i << endl;
			return 0;
		}
	}
	cout << 0 << endl;

}


/*
#include <iostream>
using namespace std;
int main(void)
{
  int num;
  cin>>num;
  int result=0;
  int input=0, temp=0;
  for(int i=0 ; i<num ; i++)
  {
    input=i;
    temp=i;
    while(input!=0)
    {
      temp+=input%10;
      input=input/10;
      if(temp==num)
      {
        result=i;
        goto EXIT;
      }
    }
  }
EXIT:
  cout<<result<<endl;
}
 // 케이스 다 맞는데 ,,
 //1, 2, 4, 8, 15, 21, 27 넣어보기
 */
