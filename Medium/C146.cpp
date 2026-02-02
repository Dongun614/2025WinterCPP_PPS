#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 트럭의 수, 다리의 길이, 최대하중
int N, W, L;
int Time = 0;
int cL=0; // 현재 하중
vector<int> v;
queue<pair<int,int>> q;
void solve()
{
	int i = 0;
	while(1){

		if (i<N && cL + v[i] <= L)
		{
			q.push(make_pair(W, v[i]));
			cL += v[i];
			i++;
		}

		int s = q.size();

		for (int j = 0; j < s ; j++)
		{
			if (!q.empty())
			{
				int ctime = q.front().first;
				int weight = q.front().second;
				q.pop();

				if (ctime - 1 != 0)
					q.push(make_pair(ctime - 1, weight));
				else
					cL -= weight;

			}
		}

		Time++;

		if (i == N && q.empty())
			break;
	}

	cout << Time+1;
}

int main(void)
{
	cin >> N >> W >> L;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		v.push_back(n);
	}

	solve();
}