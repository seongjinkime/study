//  Created by Kim Seong Jin on 2019. 9. 25..
/*
 Question
    점미사 면서 접두사인 문자열의 최대 길이를 구하시오
 
 Approach
    KMP 알고리즘에 사용되는 실패 테이블을 생성 한 뒤 끝에서 부터 0 이상인 인덱스의 길이를 구한다
 
 * 실패테이블 이란
    접두사와 접미사가 일치하는 숫자를 카운트 한다
    간격을 1만큼씩 증가시킨 후 탐색을 진행하며 일치하는 문자의 수를 센다
    if s[idx] == s[begin+idx] => t[begin+idx] = max(s[idx]+1);
 
 Solve
    1. 주어진 문자열 길이 만큼의 1차원 배열을 생성한다
    2. 시작 인텍스를 1만큼 증가 시키며 s[i] == s[시작 인덱스 + i] 의 조건에 부합하는 위치를 찾는다
    3. 조건에 부합하는 인덱스에 i+1 만큼의 숫자를 삽입한다
    4. 실패 테이블을 끝에서 부터 탐색 하며 0보다 큰 숫자가 있는지 탐색하며 counting을 한다.
       만약 table[idx]==0 이라면 일치하는 문자열이 앞에도 없다는 것이다.
    5. counting을 반환한다.
 */


#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int>makeTable(string pattern){
    vector<int> table (pattern.size(), 0);
    for(int begin = 1 ; begin < pattern.size() ; begin++){ //시작 간격을 1씩 증가시킨다
        for(int walker = 0 ; walker < pattern.size() ; walker++){ //처음부터 탐색하며 문자열의 위치에서
                                                                  // 정해진 간격만큼 떨어진 글자가 일치하는지 검사한다.
            if(pattern[begin+walker] != pattern[walker])break;
            table[begin+walker] = max(table[begin+walker], walker+1); //일치한다면 s[시작 인덱스 + i]에 i+1 삽입
        }
    }
    return table;
}

int solution(string s){
    int answer = 0;
    int k = s.size();
    vector<int>table = makeTable(s);
    
    while(k>0){ //table을 끝에서 부터 탐색하며 0 이 나오지 않는 수를 센다
        answer+=1;
        k = table[k-1];
    }
    
    return answer; //counting 반환
}


int main(int argc, const char * argv[]) {
    // insert code here...
    string test = "ababbaba";
    cout<<solution(test)<<endl;
    return 0;
}
