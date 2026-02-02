#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAX = 101;
int n;
vector<pair<int, int>> v;
int dp[MAX] = { 1, }; //부분수열의 길이를 저장하는 배열
int maxValue; //가장 긴 부분수열의 길이
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int first, second;
        cin >> first >> second;
        v.push_back({ first,second });
    }
    //first기준으로 오름차순 정렬
    sort(v.begin(), v.end()); 
 
    //가장 긴 부분수열의 길이(maxValue) 구하기
    for (int i = 0; i < n; i++) {
        int value = 0;
        for (int j = 0; j < i; j++) {
            if (v[i].second > v[j].second) {
                value = max(value, dp[j]);
            }
        }
        dp[i] = value + 1;
    }
 
    for (int i = 0; i < n; i++) {
        maxValue = max(maxValue, dp[i]);
    }
    
    cout << n - maxValue;
}