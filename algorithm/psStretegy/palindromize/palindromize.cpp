//  palindromize
//  Created by Kim Seong Jin on 2019. 9. 25..

/*
 Question
    palindromize(회문) 이란 앞에서 읽었을때와 뒤에서 읽었을때 동일한 글자를 말한다. ex) anona
    하나의 문자열이 주어졌을때 최소 길이의 회문에서 각 문자가 얼만큼 겹치는지 반환 하여라
 
 Approach
    1. 문자열을 하나씩 쪼개어 뒤로 붙여가며 회문 여부를 검사한다. ex)anon + nona, anon + ona ...
    2. 주어진 문자열을 상반되는 방향으로 결합 한 뒤 뒤집어진 숫자와 일치하는 위치에서 겹치는 숫자를 반환 ex) anon, nona => 3
 
 Solve
    1. 거꾸로 뒤집어진 문자열의 접두사, 접미사 일치 테이블을 생성 한다.
    2. 얼마만큼의 문자가 일치 하는지를 저장 하기 위한 matched 변수를 생성 한다.
    3. 시작 위치를 표시하기 위한 begin 변수를 생성 한다.
    4. 만약 문자열과 pattern을 전부 검사한 결과 모든 문자가 일치하다면(begin+match == length) matched 반환
    5. 그렇지 않다면 시작위치를 직전에 일치했던 만큼의 문자를 건너뛰어 검색을 시작한다.
 
 */


#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> makeTable(string s){
    vector<int>table (s.size(), 0);
    for(int begin = 1 ; begin < s.size() ; begin++){
        for(int walker = 0 ; walker<s.size() ; walker++){
            if(s[begin+walker] != s[walker])break;
            table[walker+begin] = max(table[walker+begin], walker+1);
        }
    }
    return table;
}//접두사, 접미사 일치 테이블 생성

//KMP 알고리즘을 활용한 알고리즘
int maxOverlap(string origin, string reverse){
    vector<int>table = makeTable(reverse);
    int oSize = origin.size();
    int rSize = reverse.size();
    int begin = 0, match = 0;
    while(begin < oSize){
        if(match < rSize && origin[begin+match] == reverse[match]){
            match++;
            if(begin + match == oSize)return match; //만약 시작위치 + 일치하는 길이가 문자열 길이와 동일하다면
        }else{
            if(match==0) //만약 아무것도 일치하지 않는다면 1만큼 증가
                begin++;
            else{
                begin += match-table[match-1]; //직전에 일치했던 숫자 만큼을 건너 뜀
                match = table[match-1]; //직전에 매칭 되었던 인덱스로 이동
            }
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<maxOverlap("anon", "nona")<<endl;
    return 0;
}
