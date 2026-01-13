#include <iostream>
using namespace std;

int main() {
	int N, M, sum(-1), max(-1);
	int arr[101];
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				sum = arr[i] + arr[j] + arr[k];
				if (max < sum && sum <= M) {
					max = sum;
				}
			}
		}
	}

	cout << max;
	return 0;
}