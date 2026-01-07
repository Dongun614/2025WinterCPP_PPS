#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

vector<int> solution(vector<int> arr, int divisor);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {5,9,7,10};
    int div = 5;

    solution(arr, div);

    return 0;
}

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(auto i=arr.begin(); i!=arr.end(); i++){
        if(*i % divisor == 0){
            answer.push_back(*i);
        }
    }
    
    if(answer.size() == 0){
        answer.push_back(-1);
    } else{
        sort(answer.begin(), answer.end());
    }
    
    return answer;
}