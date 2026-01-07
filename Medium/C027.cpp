#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int E, S, M, cnt = 1;
	cin >> E >> S >> M;
	int a, b, c;
	a = b = c = 1;
	while (1) {
		if (a == E && b == S && c == M) {
			cout << cnt;
			break;
		}
		a++; b++; c++;
		if (a > 15) a = 1;
		if (b > 28) b = 1;
		if (c > 19) c = 1;
		cnt++;
	}
}