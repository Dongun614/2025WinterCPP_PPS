#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool answer = true;

    int pCount = 0;
    int yCount = 0;

    string S = "pPoooyY";

    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'p' || S[i] == 'P') pCount++;
        if(S[i] == 'y' || S[i] == 'Y') yCount++;
    }

    if(pCount != yCount) answer = false;

    return answer;
}