/*
 Question
    울타리의 나무들을 재활용 하여 만들 수 있는 최대한의 정사각형 넓이를 구하시오

 Approach
    1. 왼쪽에서 오른쪽으로 이동하며 자신보다 왼쪽에 있고 높이가 높은 판자들을 제거한다면 정사각형을 만들 수 있다
    2. 왼쪽을 포함 할 수 있는 판자들 중 가장 높은 판자를 선택하고 넓이와 높이를 곱하면 정사각형의 크기를 구할 수 있다
 
 Solve
    1. 후보로 선택된 판자들을 차례대로 저장하기 위해 stack을 사용한다.
    2. stack의 top 은 가장 오른쪽에 있는 판자이다. top -> begin = 오른쪽 -> 왼쪽
    3. 판자를 추가하고자 할 경우 기존에 추가된 판자들을 오른쪽 -> 왼쪽 (top->begin)으로 탐색을 한다
    4. 만약 기존의 판자가 추가하고자 하는 것 보다 높을 경우 stack에서 삭제 한다

 Point
    1. 높이와 순서번호를 저장하기 위해 index를 사용할 수 있다. h[stack.top()]
    2. 넓이는 각각 1이므로 (i - 마지막 번호) -1 을 계산하여 구할 수 있다
    3. 사각형의 넓이는 height * width 이다.
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> h {7, 1, 5, 9, 6, 7, 3};

int solveStack(){
    stack<int>remaining;
    int ret = 0;
    int width = -1;
    for(int i = 0 ; i < h.size() ; i++){
        while(!remaining.empty() && h[remaining.top()] >= h[i]){ //삽입할 판자가 남은것들보다 낮을 경우
            int j = remaining.top(); //남은 판자 꺼냄
            remaining.pop();
            
            if(remaining.empty()) //만약 아무것도 남아 있지 않다면 두께는 1
                width = i;
            else //그렇지 않다면 두께는 i - 남아있는 판자 번호 -1 (
                width = (i-remaining.top() - 1); //i는 치지 않음
            ret = max(ret, h[j] * width); //가장 최대의 사각형 넓이를 저장
        }
        remaining.push(i); //남아있는 판자로 저장
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<solveStack()<<endl;
    return 0;
}
