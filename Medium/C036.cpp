#include <iostream>
using namespace std;
int main()
{   //배열 선언 및 입력
    int n[9], sum = 0;
    //입력
    for (int i = 0; i < 9; i++)
    {
        cin >> n[i];
        sum += n[i];
    }
//난쟁이 선택 조건
    int x, y, answer = 0;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
//if문에서 i와 j가 같은 경우( 동일한 난쟁이를 선택한 경우)이거나 
//전체에서 두 난쟁이를 뺐을때 100이 아닌 경우는 계속 진행
            if (i == j || (sum - n[i] - n[j] != 100))
                continue;
            answer = 1;// 합이 100이 되는 난쟁이 조합을 찾으면 answer=1
            x = i;//x와 y에 해당 인덱스 저장(뺄 난쟁이들)
            y = j;
            break;
        }
        if (answer == 1) //조합을 찾으면 반복문 break
            break;
    }

    // 출력
    for (int i = 0; i < 9; i++)
    {
        if (i != x && i != y)//해당하지 않는 인덱스 출력
            cout << n[i] <<endl;
    }
    return 0;
}