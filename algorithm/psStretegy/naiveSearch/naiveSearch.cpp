//created at 09.25
/*문자열에서 부분문자열이 포함되어 있는지 여부를 확인하는 가장 단순한 알고리즘
 1. 긴 문자열을 순회한다
 2. 각 문자부터 시작하여 부분 문자열의 길이만큼을 차례대로 비교한다.
 3. 만약 문자열의 방문한 숫자 + i 와 부분 문자열의 i 가 같다면 통과 아니면 실패이다
 4. 비교 검사를 통해 모든 부분 문자열이 일치한다고 나오면 시작번호를 배열에 저장한다.
 */


#include <iostream>
#include <vector>

using namespace std;

vector<int> naiveSearch(const string& H, const string& N){
    vector<int> ret;
    for(int begine = 0 ; begine + N.size() <= H.size() ; begine++){
        bool matched = true;
        for(int i = 0 ; i < N.size() ; i++){
            if(H[begine+i] != N[i]){
                matched = false;
                break;
            }
        }
        if(matched) ret.push_back(begine);
    }
    for(int i : ret) cout<<i<<", ";
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    naiveSearch("avadakedavra", "aked");
    return 0;
}
