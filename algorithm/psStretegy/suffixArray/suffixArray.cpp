//  suffixArray
//  Created by Kim Seong Jin on 2019. 9. 26..
/*
 접미사 배열을 생성 알고리즘
 
 접미사 배열이란?
 접미사를 차례대로 나누고 오름차순으로 정렬한 다음 각 접미사의 시작위치를 배열로 정리한 것
 ex) banana => [banana, anana, nana, ana, na, a] => [a, ana, anana. banana, na, nana] => [5,3,1,0,4,2]
 
 1. 가장 간단한 방법
 - 문자열을 차례대로 slice 한 배열을 생성 한 뒤 정렬. 
 - slice 배열을 순회하며 문자열 길이-slice된 문자열 길이 저장
 - 시작위치 + slice 길이 = 문자열 길이 -> 문자열 길이 - slice 길이 = 시작위치
 
 2. 개선된 방법
 - 1~문자열 길이 만큼의 번호가 들어있는 배열 생성
 - 시작~a, 시작~b 를 각각 비교 할 수 있는 comparator 생성
 - 배열을 comparator를 기준으로 정렬
 
 3. 멘버 마이어스의 알고리즘
 - 비교 대상 크기를 1~n까지 2씩 늘려가며 문자열 정렬
 - 정렬된 문자열을 그룹핑함 (비교 대상 문자열을 기준으로)
 - 만약 그룹이 동일 할 경우 group[a+t] 와 group[b+t]를 기준으로 정렬함 
 - 문자가 다른것끼리 그룹이 지어져 있으므로 t는 곧 글자를 건너띄게 되는 것임
*/


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct SuffixComparator{
    const string& s;
    SuffixComparator(const string& s) : s(s){};
    bool operator()(int a, int b){
        return strcmp(s.c_str() + a, s.c_str()+b) < 0; //c_str string의 첫번째 포인터를 반환 해 줌,
                                                       //c_str +a = a부터 시작하는 문자열
    };
};

struct Comparator{
    const vector<int>& group;
    int t;
    
    Comparator(const vector<int>& _group, int _t) : group(_group) , t(_t){};
    bool operator()(int a, int b){
        if(group[a] != group[b])return group[a] < group[b];
        return group[a+t] < group[b+t];
    }
};


void printGroup(vector<int>grp){
    for(int j : grp) cout<<j<<", ";
    cout<<endl;
}

vector<int> getSuffixArray(const string& s){
    int n = s.size();
    int t = 1;
    
    vector<int>group(n+1);
    for(int i = 0 ; i < n ; i++)group[i] = s[i];
    group[n] = -1;
    vector<int>suffix(n);
    for(int i = 0 ; i < n ; i++)suffix[i] = i;
    
    while(t<n){
        Comparator comp(group, t);
        sort(suffix.begin(), suffix.end(), comp);
        t*=2;
        if(t>=n)break;
        vector<int>newGroup(n+1);
        newGroup[suffix[0]] = 0;
        for(int idx = 1 ; idx < n ; idx++){
            if(comp(suffix[idx-1], suffix[idx]))
                newGroup[idx] = newGroup[suffix[idx-1]]+1;
            else
                newGroup[idx] = newGroup[suffix[idx-1]];
        }
    }
    
    return suffix;
    
}

vector<int> getSuffixArrayNaive(const string& s){
    vector<int> suffix;
    for(int i = 0 ; i < s.size() ; i++) suffix.push_back(i);
    sort(suffix.begin(), suffix.end(), SuffixComparator(s));
    return suffix;
}

vector<int> firstSuffix(string s){
    vector<string>postfixes;
    vector<int>suffix;
    for(int i = 0 ; i<s.size() ; i++){
        postfixes.push_back(s.substr(i, s.size()-i));
    }
    
    sort(postfixes.begin(), postfixes.end());
    
    for(int i = 0 ; i<s.size() ; i++){
        suffix.push_back(s.size() - postfixes[i].size());
    }
    return suffix;
}
vector<int>g {2,1,3,1,3,1};

int t=1;
bool comp(int a, int b){
    if(g[a] == g[b])
        return g[a+t] < g[b+t];
    return g[a] < g[b];
}

int commonPrefix(const string& s, int i, int j){
    int k = 0;
    while(i<s.size() && j < s.size() && s[i] == s[j]){
        i++;
        j++;
        k++;
    }
    return k;
}

int countSubString(const string& s){
    vector<int> a = getSuffixArrayNaive(s);
    printGroup(a);
    int ret = 0;
    for(int i = 0 ; i < s.size() ; i++){
        int cp = 0;
        if(i>0)cp = commonPrefix(s, a[i-1], a[i]);
        ret += s.size() - a[i] - cp;
    }
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    string test = "alohomora";
    cout<<test.c_str()+1<<endl;
    //vector<int> suffix = firstSuffix(test);
    vector<int> suffix = getSuffixArrayNaive(test);
    for(int i : suffix){
        cout<<i;
    }
    cout<<endl;
    vector<int> suffix2 = getSuffixArray(test);
    for(int i : suffix2){
        cout<<i;
    }
    string ban = "banana";
    cout<<endl<<"res: "<<countSubString(ban);
    cout<<endl;
    
    //string sTest = "banana";
    //getSuffixArray(sTest);
    //vector<int>test{0,1,2,3,4,5};
    //sort(test.begin(), test.end(), comp);
    //for(int i : test)cout<<i<<", ";
    
    return 0;
}
