//
//  main.cpp
//  fortress
//
//  Created by Kim Seong Jin on 2019. 9. 27..
//  Copyright © 2019년 Kim Seong Jin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct TreeNode{
    string label;
    TreeNode* parent;
    vector<TreeNode> childs;
};

int longest = 0;

TreeNode makeNode(string label){
    TreeNode newNode;
    newNode.label = label;
    return newNode;
}

void addChilds(TreeNode& p, vector<string> childs){
    for(string s : childs){
        TreeNode node = makeNode(s);
        node.parent = &p;
        p.childs.push_back(node);
    }
}
int n, y[100], x[100], radius[100];

int sqr(int x){
    return x * x;
}
int sqrdist(int a, int b){
    return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}

bool encloses(int a, int b){
    return radius[a] < radius[b] && sqrdist(radius[a], radius[b]);
}

bool isChild(int parent, int child){
    if(!encloses(parent, child)) return false;
    for(int i = 0 ; i < n ; i++){
        if(i!=parent && i != child && encloses(parent, i) && encloses(child, i)){
            return false;
        }
    }
    return true;
}

TreeNode* getTee(int root){
    TreeNode* ret = new TreeNode();
    for(int ch = 0 ; ch < n ; ch++){
        
    }
}

TreeNode makeTree(){
    TreeNode root;
    root.label = "root";
    addChilds(root, {"a0", "b0", "c0"});
    addChilds(root.childs[0], {"a1", "a2"});
    addChilds(root.childs[1], {"b1", "b2"});
    addChilds(root.childs[2], {"c1"});
    addChilds(root.childs[0].childs[0], {"a3"});
    addChilds(root.childs[0].childs[1], {"a4"});
    addChilds(root.childs[1].childs[0], {"b3", "b4"});
    addChilds(root.childs[1].childs[0].childs[0], {"b5"});
    
    
    return root;
}

/*
int height(TreeNode* root){
    int h = 0 ;
    for(int  i = 0 ; i < root->childs.size() ; i++){
        h = max(h, 1 + height(&root->childs[i]));
    }
    return h;
}*/

void printLabels(TreeNode* root){
    cout<<root->label<<endl;
    for(int i = 0 ; i < root->childs.size() ; i++){
        printLabels(&root->childs[i]);
    }
    
}

int height(TreeNode* root){
    vector<int> heights;
    for(int i = 0 ; i < root->childs.size() ; i++){
        heights.push_back(height(&root->childs[i]));
    }
    if(heights.empty())return 0;
    sort(heights.begin(), heights.end());
    if(heights.size()>2){
        longest = max(longest, heights[heights.size()-1] + heights[heights.size()-2] + 2);
    }
    return heights.back() + 1;
    
}

int solve(TreeNode* root){
    longest = 0;
    int h = height(root);
    return max(h, longest);
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    TreeNode r = makeTree();
    cout<<height(&r)<<endl;
    //printLabels(&r);
    return 0;
}
