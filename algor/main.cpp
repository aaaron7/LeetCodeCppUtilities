//
//  main.cpp
//  algor
//
//  Created by aaaron7 on 16/4/5.
//  Copyright © 2016年 aaaron7. All rights reserved.
//

#include <iostream>
#include<string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>
#include "file_op.hpp"
#include "linked_list.hpp"
#include "btree.hpp"

using namespace std;


int main(int argc, const char * argv[]) {
    // insert code here...

    BTreeSolution a;
    
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
    preorder.push_back(1);
    preorder.push_back(2);
    preorder.push_back(4);
    preorder.push_back(5);


    inorder.push_back(9);
    inorder.push_back(3);
    inorder.push_back(15);
    inorder.push_back(20);
    inorder.push_back(7);


    postorder.push_back(9);
    postorder.push_back(15);
    postorder.push_back(7);
    postorder.push_back(20);
    postorder.push_back(3);
    TreeNode* tree = a.buildTreeInPost(inorder, postorder);
    printBTree(tree);
    TreeNode* tree1 = new TreeNode(1);
    TreeNode* tree1left = new TreeNode(2);
    tree1->left = tree1left;
    vector<vector<int>> temp =a.levelOrderBottom(tree);
    std::cout << "Hello, World!\n" << endl;
    return 0;
}
