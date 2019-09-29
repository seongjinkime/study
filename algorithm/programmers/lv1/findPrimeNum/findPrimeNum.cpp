//
//  main.cpp
//  findPrimeNum
//
//  Created by Kim Seong Jin on 2019. 9. 11..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

using namespace std;
int mySolution(int n);
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << mySolution(5) << endl;
    return 0;
}

int mySolution(int n){
    int cnt = 0;
    //int* arr = (int*) malloc(sizeof(int) * n);
    int arr[n+1];
    arr[0] = 0;
    for (int i = 1 ; i <= n ; i++){
        arr[i] = i;
    }
    
    for (int i = 2 ; i <= n ; i++){
        if(arr[i] == 0)
            continue;
        for(int j = i+i ; j <= n ; j += i){
            arr[j] = 0;
        }
    }
    
    for (int i = 2 ; i <= n ; i++){
        if(arr[i] != 0){
            cnt++;
        }
    }
    
    return cnt;
}
