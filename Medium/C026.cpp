#include <iostream>
#include <string>
#include <algorithm> // min, fill 사용
#include <cmath>     // abs 사용

#define PRESET ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

/*
    브루트포스로 구현
    시작 채널(100번) 부터 N까지 +와 -로만 도달 가능한 횟수를 기본값으로 지정 -> abs(n-100)
    0~1,000,000까지 사용 가능한 버튼으로 해당 채널로 이동이 가능한지 확인
    각 채널마다 N까지 + or -로 이동하여 도달한 횟수 계산
    위 방식들중 최소값을 출력
*/

int n, m;
bool isValid[10]; // 유효 버튼

bool isMove(int num){
    if (num == 0) {
        return isValid[0];
    }
    while (num) {
        if (!isValid[num % 10]) return false;
        num /= 10;
    }
    return true;
}

int main(){
    PRESET;

    fill(isValid, isValid + 10, true);    
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int idx;
        cin >> idx;
        isValid[idx] = false;
    }

    // 1. 숫자 버튼 없이 +, -로만 이동하는 경우
    int result = abs(n - 100); 

    // 2. 모든 가능한 채널(i)에 대해 숫자 버튼으로 이동 후 +, -로 조절하는 경우
    // n의 범위가 500,000이므로 1,000,000까지 확인해야 위에서 내려오는 경우까지 체크 가능합니다.
    for(int i = 0; i <= 1000000; i++){
        if(isMove(i)) {
            int move = to_string(i).length(); // 숫자 버튼 누르는 횟수
            move += abs(i - n);               // +, - 누르는 횟수
            result = min(result, move);
        }
    }

    cout << result;

    return 0;
}