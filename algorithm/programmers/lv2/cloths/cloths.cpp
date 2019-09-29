//
//  main.cpp
//  cloths
//
//  Created by Kim Seong Jin on 2019. 9. 17..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<string, int> createMap(vector<vector<string>> clothes){
    map<string, int> clothCnt;
    string key = "";
    
    for(int row = 0 ; row < clothes.size() ; row++){
        key = clothes[row][1];
        
        if(!clothCnt.count(key)) clothCnt[key] = 0;
        clothCnt[key]++;
    }
    
    return clothCnt;
}

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> clothMap = createMap(clothes);
    
    for(map<string, int>::iterator it = clothMap.begin() ; it != clothMap.end() ; it++)
        answer *= (it->second)+1;
    return answer-1;
}

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<string>> test = {
                                    {"yellow_hat", "headgear"},
                                    {"blue_sunglasses", "eyewear"},
                                    {"green_turban", "headgear"}
                                    };
    
    cout << solution(test) << endl;
    return 0;
}
