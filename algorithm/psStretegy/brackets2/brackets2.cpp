/*
 Question : 잘못된 괄호가 있는지 여부를 반환하는 함수 작성
 정상적인 괄호 : ({}[(){}]),
 정상적이지 않은 괄호 : ({[}])
 
 Approach
	1. queue에 여는 괄호는 모두 push를 하고 닫는 괄호는 stack의 맨 앞부분과 비교하여 틀리다면 false를 반환한다
	2. 여는 괄호와 닫는 괄호를 각각 문자열로 저장 한 뒤 stack의 top과 닫는 괄호의 순서가 일치하는지 비교한다

 Solve
    simple  : 분기문을 중첩사용하여 닫는 괄호->괄호의 종류를 구분한 뒤 stack의 top과 비교한다
    improve : 여는괄호와 닫는 괄호를 문자열로 선언 하고 닫는 괄호로 판단될 경우 stack의 top, 
              단는 괄호의 index 일치 여부를 비교한다
 
 Point
    1. 싱호 매칭되어야 하는 문자열을 비교할때는 각각의 인덱스를 비교하면 코드의 양을 줄일 수 있다
    2. 매칭검사에는 stack이 활용될 수 있다
 */

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <math.h>

using namespace std;

bool ans(const string& formula){
    const string opening("({["), closing(")}]");;     //여는괄호와 닫는괄호를 문자열로 저장
    stack<char> openStack;
    for(int i = 0 ; i < formula.size() ; i++){
        if(opening.find(formula[i]) != string::npos){ //만약 여는괄호라면
            openStack.push(formula[i]);
        }else{
            if(opening.find(openStack.top())!= closing.find(formula[i])){ //top의 opening 괄호와 일치하지 않다면
                return false;
            }
            openStack.pop(); //*일치하다고 판명되는 건 pop
        }
    }
    
    return openStack.empty();
}

int solution(string brackets){
    stack<int> chars;
    bool res = true;
    for(char c : brackets){
        if(c=='(' || c == '{' || c == '[') //여는 괄호로 판명 된다면
            chars.push(c);
        //닫는괄호의 종류에 따라 top과 매칭되는지 일일이 검사 -> 코드 길어짐
        if(c==')'){
            if(chars.top() == '('){
                res = true;
                chars.pop();
            }else{
                res = false;
            }
        }else if(c=='}'){
            if(chars.top() == '{'){
                res = true;
                chars.pop();
            }else{
                res = false;
            }
        }else if(c==']'){
            if(chars.top() == '['){
                res = true;
                chars.pop();
            }else{
                res = false;
            }
        }
        
    }
    
    if(res)
        cout<<"TRUE"<<endl;
    else
        cout<<"FALSE"<<endl;
    
    return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    string test = ("()");
    solution("()");
    solution("({[}])");
    solution("({}[(){}])");
    
    cout << ans("()")<<endl;
    cout << ans("({[}])")<<endl;
    cout << ans("({}[(){}])")<<endl;
    
    return 0;
}
