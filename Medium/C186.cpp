#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
 
using namespace std;
 
int n;
vector<vector<int>> vec;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    vec.resize(n, vector<int>(3));
 
    for (vector<int>& ele : vec)
    {
        for (int& e : ele) cin >> e;
    }
 
    int ans = INT_MAX;
    for (int i = 0; i < n ; i++)
    {
        
        int temp = INT_MAX;
        int prev = temp;
 
        for (int j = 0; j < n; j++)
        {
            if (j == i) continue;
 
            int d = abs(vec[i][0] - vec[j][0])
                + abs(vec[i][1] - vec[j][1])
                + abs(vec[i][2] - vec[j][2]);
        
            if (temp > d)
            {
                prev = temp;
                temp = d;
            }
            else if (prev > d)
            {
                prev = d;
            }
        }
 
        ans = min(ans, temp + prev);
    }
 
    cout << ans;
    
    return 0;
}