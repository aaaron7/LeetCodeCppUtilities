//
//  btree.hpp
//  algor
//
//  Created by aaaron7 on 16/4/10.
//  Copyright © 2016年 aaaron7. All rights reserved.
//

#ifndef btree_hpp
#define btree_hpp
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>
#include "linked_list.hpp"
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

void printBTree(TreeNode* root);

class BTreeSolution {
public:
    void connect(TreeLinkNode *root) {
        if (root == NULL){
            return;
        }
        TreeLinkNode* pLeft = root->left;
        TreeLinkNode* pRight = root->right;

        if (pLeft == NULL || pRight == NULL){
            return ;
        }

        pLeft->next = pRight;
        while (true) {
            pLeft = pLeft->right;
            pRight = pRight->left;

            if(pLeft == NULL || pRight == NULL){
                break;
            }

            pLeft->next = pRight;
        }

        connect(root->left);
        connect(root->right);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result = levelOrder(root);
        vector<vector<int>> finalResult;
        for (int i = result.size() - 1; i >= 0; i --) {
            finalResult.push_back(result[i]);
        }
        return finalResult;
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelOrderHelper(root,1,result);
        return result;
    }

    void levelOrderHelper(TreeNode* root,int depth,vector<vector<int>>& result){

        if (root == NULL){
            return;
        }
        cout<<result.size()<<endl;
        if (result.size() < depth){
            vector<int> a;
            result.push_back(a);
        }

        result[depth - 1].push_back(root->val);
        levelOrderHelper(root->left, depth + 1, result);
        levelOrderHelper(root->right, depth+1, result);
    }

    int minDepth(TreeNode* root) {
        return minDepthHelper(root, 1);
    }

    int minDepthHelper(TreeNode* root,int depth){
        if (root == NULL){
            return depth - 1;
        }
        int left = minDepthHelper(root->left, depth + 1);
        int right = minDepthHelper(root->right, depth + 1);
        if (root->left == NULL){
            return right;
        }else if(root->right == NULL){
            return left;
        }else{
            return left>right?right:left;

        }
    }

    int maxDepth(TreeNode* root) {
        return maxDepthHelper(root, 1);
    }

    int maxDepthHelper(TreeNode* root, int depth){
        if (root == NULL){
            return depth - 1;
        }
        int left = maxDepthHelper(root->left, depth + 1);
        int right = maxDepthHelper(root->right, depth + 1);
        return left>right?left:right;
    }

    //construct from preorder and inorder
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* buildTreeHelper(vector<int>& preorder, int preBegin,int preEnd, vector<int>& inorder,int inBegin,int inEnd){
        if (preEnd < preBegin || inEnd < inBegin){
            return NULL;
        }

        TreeNode *root= new TreeNode(preorder[preBegin]);

        if (preBegin == preEnd){
            return root;
        }

        if (inBegin == inEnd){
            root->val = inorder[inBegin];
            return root;
        }

        int rootIdx = -1;
        for (int i =inBegin; i<=inEnd; i++) {
            if(inorder[i] == root->val){
                rootIdx = i;
            }
        }

        if (rootIdx == -1){
            return  NULL;
        }

        int tailLength = inEnd - rootIdx;
        int preLength = preEnd - preBegin + 1;

        TreeNode* left = buildTreeHelper(preorder, preBegin + 1, preBegin + (preLength - tailLength - 1), inorder, inBegin, rootIdx - 1);

        TreeNode* right = buildTreeHelper(preorder,preBegin +  preLength - tailLength, preEnd, inorder, rootIdx + 1, inEnd);
        root->left = left;
        root->right = right;
        return root;
    }

    TreeNode* buildTreeInPost(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeHelperInPost(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() -1);
    }

    TreeNode* buildTreeHelperInPost(vector<int>& inorder, int inBegin,int inEnd, vector<int>& postorder,int poBegin,int poEnd){
        if (inEnd < inBegin || poEnd < poBegin){
            return NULL;
        }

        TreeNode *root= new TreeNode(postorder[poEnd]);

        if (poBegin == poEnd){
            return root;
        }

        if (inBegin == inEnd){
            root->val = inorder[inBegin];
            return root;
        }

        int rootIdx = -1;
        for (int i =inBegin; i<=inEnd; i++) {
            if(inorder[i] == root->val){
                rootIdx = i;
            }
        }

        if (rootIdx == -1){
            return  NULL;
        }

        int tailLength = inEnd - rootIdx;
        int postLength = poEnd - poBegin + 1;

        TreeNode* left = buildTreeHelperInPost(inorder, inBegin, rootIdx -1, postorder, poBegin,poBegin + postLength-1 - tailLength - 1);
        
        TreeNode* right = buildTreeHelperInPost(inorder, rootIdx + 1, inEnd, postorder, poBegin + postLength - 1 - tailLength, poEnd - 1);
        root->left = left;
        root->right = right;
        return root;
    }
};

#endif /* btree_hpp */
