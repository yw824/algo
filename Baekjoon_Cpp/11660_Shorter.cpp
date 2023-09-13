/*
Baekjoon Online Judge
11660) 구간 합 구하기 5 (https://www.acmicpc.net/problem/11660)
*/
#include <iostream>
#include <vector>

using intP = unsigned int;
const char endl = '\n';

class Table
{
	using Array = std::vector<intP>;
	using Matrix = std::vector<Array>;

private:
	const intP N;
	Matrix prefix;

public:
	Table(intP N) : N(N), prefix(N + 1, Array(N + 1, 0)) {}
	void init(std::istream& input) {
		intP accum, temp;
		for (intP x = 1; x <= N; ++x) {
			accum = 0;
			for (intP y = 1; y <= N; ++y) {
				input >> temp;
				accum += temp;
				prefix[x][y] = accum;
			}
		}
		for (intP y = 1; y <= N; ++y) {
			for (intP x = 1; x <= N; ++x) {
				prefix[x][y] += prefix[x - 1][y];
			}
		}
	}
	intP query(intP x1, intP y1, intP x2, intP y2) {
		return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1 - 1] + prefix[x1 - 1][y1 - 1];
	}
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	intP N, M, x1, y1, x2, y2;
	std::cin >> N >> M;
	Table table(N);
	table.init(std::cin);
	for (intP m = 0; m < M; ++m) {
		std::cin >> x1 >> y1 >> x2 >> y2;
		std::cout << table.query(x1, y1, x2, y2);
		if (m != M - 1) std::cout << endl;
	}

	return 0;
}
