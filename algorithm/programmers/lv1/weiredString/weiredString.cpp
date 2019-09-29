#include <string>
#include <vector>
#include <iostream>

using namespace std;


string solution(string s);

int main(void){
    string test = "try hello world";
    cout << solution(test) << endl;
    
}

string solution(string s) {
    int chCount = 0;
    
    for(int idx = 0 ; idx < s.size() ; idx++){
        s[idx] = chCount&1 ? tolower(s[idx]) : toupper(s[idx]);
        
        if(s[idx] == ' ')
            chCount = 0;
        else
            chCount++; 
    }
    return s;
}

