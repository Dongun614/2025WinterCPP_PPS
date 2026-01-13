#include <string>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
// 고득점
int main() {
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		int answer = 0, move = INT32_MAX, size = s.size();
		for (int i = 0; i < size; i++) {// 각 자리별로 단어 몇개 돌려야 하는지 계산
			answer += min(s[i] - 'A', 'Z' - s[i] + 1);
			if (s[i] != 'A') s[i] = 'B';
		}

		for (int i = 0, j; i < size; i++) {// 포인트 둘을 잡고 왔다 갔다 최소 계산
			j = find(s.begin() + i + 1, s.end(), 'B') - s.begin();
			int right = i * 2 + size - j;
			int left = i + (size - j) * 2;
            // cout << i << " " << j << ": " << right << " " << left << "\n";// 흐름이 잘 안보일때 추가해서 보면 이해하기 쉽다.
			move = min(move, min(left, right));
		}
		cout << answer + move << "\n";
	}
}