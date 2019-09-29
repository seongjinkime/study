//
//  main.cpp
//  traversal
//
//  Created by Kim Seong Jin on 2019. 9. 27..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> slice(const vector<int>&v, int start, int end){
    return vector<int>(v.begin() + start, v.begin() + end);
}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder){
    const int N = preorder.size();
    if(preorder.empty())return;
    
    const int root = preorder[0];
    const int L = find(inorder.begin(), inorder.end(), root)-inorder.begin();
    
    
    const int R = N-L-1;
    
    printPostOrder(slice(preorder, 1, L+1), slice(inorder, 0,   L));
    printPostOrder(slice(preorder, L+1, N), slice(inorder, L+1, N));
    
    cout<<root<<", ";
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector<int>pre  = {27, 16, 9, 12, 54, 36, 72};
    vector<int>in   = {9, 12, 16, 27, 36, 54, 72};
    printPostOrder(pre, in);
    return 0;
}
