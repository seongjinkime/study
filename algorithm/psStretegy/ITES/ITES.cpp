//  Created by Kim Seong Jin on 2019. 9. 24..
/*
 Question
 무작위의 숫자 신호가 발생 했을 때 신호 중 합이 K인 부분이 몇개 있는지 찾아내시오
 
 Approach
 1. 신호를 모두 배열로 저장 한 뒤 부분 합이 k가 되는 지점을 찾음
 2. 신호 발생기를 생성하고 연산에 필요한 만큼만 수를 저장
 
 
 
 Solve
 
 Simple
    총 합이 k 보다 작을 동안 stack에 숫자를 저장 한 뒤 합이 k 와 일이 하는 지 검사. 이후엔 다시 모든 요소들을 리스트의 앞으로 복귀 시킴
 
 Improve
 신호에 따라 더해지는 수를 vector로 저장 함. 앞의 숫자와 k 를 더한 숫자보다 작을 때까지 tail 포인터를 이동. 이후 일치하는지 검사
 
 Optimization
 신호 발생기 생성, 신호의 합들을 저장 함. 만약 front + k 가 k보다 작을 동안 pop, front +k 가 back과 일치하는지 검사
 key q[back] - q[start] = k, q[back] = k + q[start] => q[start] + k = q[end]
 
 */



#include <iostream>
#include <stack>
#include <vector>
#include <list>
#include <queue>

using namespace std;


struct RNG{
    unsigned seed;
    RNG() : seed(1983) {} //seed 초기화
    unsigned next(){ //next 함수, 다음 신호 생성
        unsigned res = seed;
        seed = ((seed * 214013u) + 2531011u);
        return res % 10000 + 1;
    }
};

struct SUB{
    stack<unsigned> sub;
    unsigned total;
    int count=0;
    
    unsigned pop() {
        unsigned elem;
        elem = sub.top();
        total -= elem;
        count--;
        sub.pop();
        return elem;
    }
    void push(unsigned elem){
        sub.push(elem);
        total += elem;
        count++;
    }
    
    void clear(){
        total = 0;
        count = 0;
        sub = {};
    }
    
}; //부분 합을 구하기 위한 stack 자료구조 구현, count와 total 기능 추가



int solution(int k, int n){
    RNG rng = RNG();
    SUB sub = SUB();
    list<unsigned>signals;
    
    for(int i = 0 ; i < n ; i++){
        unsigned n = rng.next();
        signals.push_back(n);
        
    } //신호를 모두 배열에 저장
    
    
    
    int idx = 0;
    int cnt = 0;
    while(!signals.empty()){
        sub.clear();
        
        while(sub.total<k && !signals.empty()){
            
            sub.push(signals.front());
            signals.pop_front();
            
        }//신호의 합이 k 보다 작을동안 부분합으로 더함
       
        if(sub.total == k){ //만약 k 와 부분합이 일치한다면 counting
            cout<<idx+1 << " - " << idx+sub.count<<endl;
            cnt++;
            
        }
        while(sub.count>1){ //부분합에 저장된 신호를 다시 리스트의 처음으로 복귀
            unsigned t = sub.pop();
            //cout<<t<<endl;
            signals.push_front(t);
        }
        idx++;
    }
    return cnt;
    
}

int offline(const vector<int>& signals, int k){
    vector<long long>pSum(signals.size()); //부분합 배멸 생성
    pSum[0] = signals[0];
    for(int i = 1 ; i < signals.size() ; i++)
        pSum[i] = signals[i] + pSum[i-1]; //이전의 수를 더해가며 배열 값 지정
    int ret = 0, tail = 0;
    for(int head = 0 ; head < pSum.size() ; head++){
        while(tail+1 < pSum.size() && pSum[head]+k > pSum[tail]){
            tail++;
        } //만약 head + k > tail => tail 한칸 이동
        if(pSum[head]+k == pSum[tail]){
            ret++; //만약 head + k == tail과 일치 하다면, 즉 head-tail 이 k 라면
        }
    }
    cout<<ret<<endl;
    return ret;
}




int countPartialSums(int k, int n){
    RNG rng;
    int ret = 0;
    queue<long long>psums;
    long long psum=0;
    
    for(int i = 0 ; i < n ; i++){
        psum += rng.next();
        psums.push(psum); //신호의 합을 저장
        while (psums.front()+k < psum) {
            psums.pop(); //만약 head + k 가 합보다 크다면 pop (tail 이동과 동일)
        }
        if(psums.front() +k == psum){
            ret++; //만약 head+k == psum => tail - head == k 라면
        }
    }
    return ret;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int>test {1, 4, 2, 1, 3, 1, 6};
    offline(test, 7);
    //cout << solution(3578452, 5000000)<<endl;
    //cout << countPartialSums(3578452, 5000000)<<endl;
    //cout << offline(3578452, 5000000)<<endl;
    return 0;
}
