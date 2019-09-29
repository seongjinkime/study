//  jaehaSafe
//  Created by Kim Seong Jin on 2019. 9. 26..

/*
 Question
    금고를 열기 위해 차례대로 주어진 문자열을 맞추어야 한다. 
    금고의 문은 원형으로 되어 있으며 시계 방향 -> 반시계 방향으로 돌려 문자열을 차례대로 맞추어야 한다.
    주어진 모든 문자열을 맞추기 위해 최소 몇번의 다이얼을 돌려야 하는지 구하여라.
 
 Approach
    1. list를 원렬 리스트로써 활용하여 left shift와 right shift를 구현한다.
    2. 원형 문자열을 일렬로 생각한다. a 문자열과 a 문자열을 합친 뒤, b 문자열과 일치하려면 몇번 움직여야 하는지 구한다.
       반대 방향은 b 문자열과 b 문자열을 합친 뒤 a 문자열과 일치하려면 a를 몇번 움직여야 하는지 구한다.
 
 Solve
    simple
    list를 원형으로 왼쪽으로 움직이거나 오른쪽으로 움직일 수 있는 shift 함수를 구현한다.
    주어진 문자열을 탐색하며 특정 문자열이 다음 문자열과 일치할때까지의 회전 횟수를 세어 반환 한다.
 
    Improvement
    시계 방향이면 a + a 문자열에 b가 일치하는 지점을 찾고, 반시계이면 b + b문자열에 a가 일치하는 지점을 찾는다.
    각 지점의 합계를 구하여 반환 한다.
 */



#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

/*Simple Version*/
bool isMatch(string pw, list<char> dial){
    string dialStr = "";
    for(char ch : dial){
        dialStr += ch;
    }
    
    return pw == dialStr;
}//회전된 문자열이 답과 일치하는지 확인하는 검사

void printDial(list<char>& dial){
    for(char c : dial)cout<<c<<", ";
    cout<<endl;
}//테스트용 print 함수

void rightShift(list<char>& dial){
    dial.push_front(dial.back()); //맨 뒤의 요소를 앞으로 옮긴다
    dial.pop_back();//맨뒤 요소 제거
}//오른쪽 회전

void leftShift(list<char>& dial){
    dial.push_back(dial.front()); //맨 앞의 요소를 뒤로 옮긴다
    dial.pop_front(); //맨앞의 요소 제거
}

int solution(vector<string>passwords){
    bool toRight = true;
    string pw;
    list<char>dial;
    int cnt = 0;
    
    for(char ch : passwords[0]){
        dial.push_back(ch);
    }
    
    for(int idx = 1 ; idx < passwords.size() ; idx++){
        pw = passwords[idx];
        while(!isMatch(pw, dial)){ //일치하지 않을때까지 회전
            if(toRight) //방향을 바꾸어 가며 회전
                rightShift(dial);
            else
                leftShift(dial);
            cnt++;//카운트
        }
        toRight= !toRight; //방향 전환
    }
    return cnt;
}

/*Improve Version*/
vector<int> getPartialMatchNaive(const string& pattern){
    int pSize = pattern.size();
    vector<int>pi(pSize, 0);
    
    for(int begin = 1 ; begin < pSize ; ++begin){
        for(int i = 0 ; i < pSize ; ++i){
            if(pattern[begin+i] != pattern[i])break;
            pi[begin+i] = max(pi[begin+i], i+1);
        }
    }
    return pi;
}//접두사 & 접미사 일치 테이블 생성

vector<int> kmpSearch(const string&src, const string& pattern){
    int pSize= pattern.size();
    int sSize = src.size();
    vector<int>ret;
    vector<int> pi = getPartialMatchNaive(pattern);
    int begin = 0, matched = 0;
    while(begin <= sSize - pSize){
        if(matched< pSize && src[begin+matched] == pattern[matched]){
            ++matched;
            if(matched==pSize)ret.push_back(begin);
        }else{
            if(matched==0)
                begin++;
            else{
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    
    return ret;
}//KMP search를 통해 문자열이 일치하는 시작 위치 반환

int shifts(const string& original, const string& target){
    return kmpSearch(original+original, target)[0];
}//문자열을 더한것에서 가장 맨처음 target일 일치하는 시작 위치를 반환

int solution2(vector<string>passwords){
    int cnt = 0;
    for(int idx = 0 ; idx < passwords.size() -1 ; idx++){
        if(idx&1){
            cnt+=shifts(passwords[idx], passwords[idx+1]); //idx가 홀수라면 반시계 방향
        }else{
            cnt+=shifts(passwords[idx+1], passwords[idx]); //짝수라면 시계 방향
        }
        
    }
    return cnt;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    vector<string>test{"RMDCMRCD","MRCDRMDC", "DCMRCDRM"};
    cout<<solution(test)<<endl;
    cout<<solution2(test)<<endl;
    
    
    return 0;
}
