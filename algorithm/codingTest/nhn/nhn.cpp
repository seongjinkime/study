//
//  main.cpp
//  nhn
//
//  Created by Kim Seong Jin on 29/09/2019.
//  Copyright © 2019 Kim's Inc. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;



int main(int argc, const char * argv[]) {
    map<string, int> cardSet;
    map<string, int>::iterator it;
    vector<string>cards;
    string card;
    int totalCount;
    
    while(getchar() != '\n'){
        cin>>card;
        if(card == "\n") break;
        cards.push_back(card);
    }
    for(string card : cards){
        if(cardSet.count(card)==0) cardSet[card] = 0;
        cardSet[card]++;
    }
    
    for(it = cardSet.begin(); it != cardSet.end(); it++){
        totalCount += it->second;
    }
    cout<<totalCount;
    return 0;
}
/*
 4
 ant bee dragonfly ant
 */
