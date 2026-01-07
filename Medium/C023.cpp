#include <iostream>
#include <vector>
using namespace std;
 
int main(void){
    int floor;
    int numOfWind;
    int wind[5] = {0,};
    
    string tmp;
    cin >> floor;
    cin >> numOfWind;
    
    int *count = new int[numOfWind](); //동적할당 0으로 초기화하는코드 
 
    vector<string> str;
    for(int i = 0 ; i < (5*floor)+1 ; i++){
        cin >> tmp;
        str.push_back(tmp);
    }
    
    for(int i = 1 ; i < (5*floor) ; i++){
 
        for(int j = 0 ; j < numOfWind ; j++){
 
            if(str[i][(5*j)+1] == '.'){
                continue;
            }
            else if(str[i][(5*j)+1] == '*'){
                count[j] = count[j]+1;
            }
        }
 
        if(i%5 == 4){
            for(int k = 0 ; k < numOfWind ; k++){
                wind[count[k]]++;
                count[k] = 0;
            }
            i++;
        }
    }
 
    for(int i = 0 ; i < 5 ; i ++){
        cout << wind[i] << " ";
    }
    cout << endl;
 
 
}