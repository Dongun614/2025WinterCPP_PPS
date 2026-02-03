#include <iostream>
#include <algorithm>
#define MAX_N 10001
#define MAX_K 1001
using namespace std;

int n,k;
int importance[MAX_N], studyTime[MAX_K], dp[MAX_K][MAX_N];

void solution() {
  for (int i=1; i<=k; i++) {
    for (int j=1; j<=n; j++) {
      if (studyTime[i] > j) dp[i][j] = dp[i-1][j];
      else dp[i][j] = max(dp[i-1][j], dp[i-1][j-studyTime[i]] + importance[i]);
    }
  }

  cout << dp[k][n] << "\n";
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> k;
  for(int i=1; i<=k; i++) { 
    cin >> importance[i] >> studyTime[i];
  }

  dp[0][0] = 0;
  solution();
}