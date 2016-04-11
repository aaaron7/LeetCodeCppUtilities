//
//  linked_list.hpp
//  algor
//
//  Created by aaaron7 on 16/4/8.
//  Copyright © 2016年 aaaron7. All rights reserved.
//

#ifndef linked_list_hpp
#define linked_list_hpp

#include <stdio.h>

struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right ,*next;
    TreeLinkNode(int x) : val(x),left(NULL),right(NULL),next(NULL){}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};




#endif /* linked_list_hpp */
