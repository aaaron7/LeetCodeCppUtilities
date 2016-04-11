//
//  btree.cpp
//  algor
//
//  Created by aaaron7 on 16/4/10.
//  Copyright © 2016年 aaaron7. All rights reserved.
//

#include "btree.hpp"
#include "linked_list.hpp"
using namespace std;



TreeLinkNode* createPerfectTree(int n){
    TreeLinkNode* r1 = new TreeLinkNode(1);
    TreeLinkNode* r2 = new TreeLinkNode(2);
    TreeLinkNode* r3 = new TreeLinkNode(3);
    TreeLinkNode* r4 = new TreeLinkNode(4);
    TreeLinkNode* r5 = new TreeLinkNode(5);
    TreeLinkNode* r6 = new TreeLinkNode(6);
    TreeLinkNode* r7 = new TreeLinkNode(7);

    r1->left = r2;
    r1->right = r3;
    r2->left = r4;
    r2->right = r5;
    r3->left = r6;
    r3->right = r7;

    return r1;
}

void printBTree(TreeNode* root){
    if(root == NULL){
        return ;
    }
    cout<<root->val<<" ";
    printBTree(root->left);
    printBTree(root->right);
}

void printList(TreeLinkNode* p){
    while (p!= NULL) {
        cout<<p->val;
        p = p->next;
    }
    
    cout<<endl;
}
