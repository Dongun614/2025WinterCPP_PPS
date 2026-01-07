#include <iostream>
using namespace std;

int main()
{
	int a, b, c,ans;
	cin >> a >> b >> c; //고정 비용, 가변 비용, 판매 금액 입력

	if (b >= c)
		cout << "-1";   //가변 비용이 판매 비용보다 크거나 같다면 -1을 출력
	else {
		ans = a / (c - b) + 1;
		cout << ans;
	}
	
}