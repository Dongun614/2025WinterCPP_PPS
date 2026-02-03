#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int A[126][126];
int dp[126][126];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs() {
    queue<pair<int, int>> q;

    dp[1][1] = A[1][1];
    q.push({ 1,1 });

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny<1 || nx<1 || ny>N || nx>N) continue;
            if (dp[y][x] + A[ny][nx] >= dp[ny][nx]) continue;

            dp[ny][nx] = dp[y][x] + A[ny][nx];
            q.push({ ny,nx });
        }
    }
}

void solution(int problem) {
    bfs();
    cout << "Problem " << problem << ": " << dp[N][N] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int i = 1;
    while (1) {
        cin >> N;
        if (!N) break;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> A[i][j];
                dp[i][j] = 987654321;
            }
        }

        solution(i++);
    }

    return 0;
}