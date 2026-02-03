#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	//입력
    int m, n, input;
    cin >> m >> n;

    vector<int> snacks;

    for(int i=0; i<n; i++){
        cin >> input;
        snacks.push_back(input);
    }

    //오름차순 정렬
    sort(snacks.begin(), snacks.end());

    //이분탐색
    int low = 1;
    int high = snacks[n-1];

    int result = 0;

    while(low <= high){
        int mid = (low + high)/2; //low와 high의 평균

        int cnt = 0; //mid 길이로 나눠줄 수 있는 조카의 수
        for(int i=0; i<n; i++){
            cnt += snacks[i]/mid;    
        }

        if(cnt < m){//m명에게 나눠줄 수 없으면
            high = mid - 1;//길이 줄이기
            
        }
        else{//m명에게 나눠줄 수 있으면
            result = mid;//길이 저장
            low = mid + 1;//길이 늘리기
        }
    }

    cout << result;

    return 0;
}