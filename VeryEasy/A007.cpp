#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

//1. 백터로 입력받음
//2. Assending 검사
//3. Descending 검사
//4. 둘다 아니면 mixed

bool isAscend(vector<int> user_input);
bool isDscend(vector<int> user_input);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<int> userInput;
    userInput.reserve(8);
    int temp;
    for(int i=0; i<8; i++){
        cin >> temp;
        userInput.push_back(temp);
    }
    
    if(isAscend(userInput)){
        cout << "ascending" << "\n";
    } else if(isDscend(userInput)){
        cout << "descending" << "\n";
    } else{
        cout << "mixed" << "\n";
    }
    

    return 0;
}

bool isAscend(vector<int> user_input){
    for(int i=1; i<user_input.size(); i++){
        if(user_input[i-1] > user_input[i]){
            return false;
        }
    }
    
    return true;
}

bool isDscend(vector<int> user_input){
    for(int i=1; i<user_input.size(); i++){
        if(user_input[i-1] < user_input[i]){
            return false;
        }
    }
    
    return true;
}