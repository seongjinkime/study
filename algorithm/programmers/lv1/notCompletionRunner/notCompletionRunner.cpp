#include <string>
#include <vector>
#include <algorithm>
#include <iostream>



using namespace std;

string solution(vector<string> participant, vector<string> completion);

int main(void){
    vector<string> participant;
    participant.push_back("mislav");
    participant.push_back("stanko");
    participant.push_back("mislav");
    participant.push_back("ana");
    
    vector<string> completion;
    completion.push_back("stanko");
    completion.push_back("ana");
    completion.push_back("mislav");
    
    //solution(participant, completion);
    cout << solution(participant, completion) << endl;
}

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int idx = 0 ; idx < completion.size() ; idx++){
        if(participant[idx] != completion[idx]){
            return participant[idx];
        }
    }
    
    return participant[participant.size()-1];
    
    
    /*
    vector<string>::iterator finder;
    for(vector<string>::iterator cl = completion.begin() ; cl != completion.end() ; cl++){
        finder = find(participant.begin(), participant.end(), *cl);
        if (finder != participant.end()){
            participant.erase(finder);
        }
    }*/
    
    
    return participant[0];
}

