//
//  main.cpp
//  kNum
//
//  Created by Kim Seong Jin on 2019. 9. 10..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>

#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int getKnum(vector<int> array, int start, int last, int idx);
vector<int> mySolution(vector<int> array, vector<vector<int>> commands);
vector<int> bestSolution(vector<int> array, vector<vector<int>> commands);

int main(int argc, const char * argv[]) {
    // insert code here...
    int nums[] = {1, 5, 2, 6, 3, 7, 4};
    vector<int> array;
    vector<vector<int>> commands;
    vector<int> ans;
    
    array.insert(array.begin(), begin(nums), end(nums));
    commands.push_back({2, 5, 3});
    commands.push_back({4, 4, 1});
    commands.push_back({1, 7, 3});
    
    ans = mySolution(array, commands);
    cout << ans[0] <<ans[1] << ans[2] << endl;
    
    ans = bestSolution(array, commands);
    cout << ans[0] <<ans[1] << ans[2] << endl;
    
}

vector<int> mySolution(vector<int> array, vector<vector<int>> commands){
    vector<int> answer;
    vector<vector<int>>::iterator cmd = commands.begin();
    vector<int> elements;
    
    while(cmd != commands.end()){
        elements = *cmd;
        answer.push_back(getKnum(array, elements[0], elements[1], elements[2]));
        cmd++;
    }
    return answer;
}
                    

int getKnum(vector<int> array, int start, int last, int idx){
    start -= 1;
    vector<int> sub(array.begin()+start, array.begin()+last);
    sort(sub.begin(), sub.end());
    return sub[idx-1];
}


vector<int> bestSolution(vector<int> array, vector<vector<int>> commands){
    vector<int> answer;
    vector<int> tmp;
    int start, end, kIdx;
    
    for(int idx = 0 ; idx < commands.size() ; idx++){
        start = commands[idx][0] - 1;
        end = commands[idx][1];
        kIdx = commands[idx][2] - 1;
        tmp = array;
        
        sort(tmp.begin()+start, tmp.begin() + end);
        answer.push_back(tmp[start+ kIdx]);
    }
    return answer;
}



