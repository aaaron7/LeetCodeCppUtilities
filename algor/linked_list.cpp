//
//  linked_list.cpp
//  algor
//
//  Created by aaaron7 on 16/4/8.
//  Copyright © 2016年 aaaron7. All rights reserved.
//

#include "linked_list.hpp"
#include <iostream>
#include<string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;





ListNode* constructList(int count,int beginVal){

    ListNode* head = new ListNode(beginVal);

    ListNode* tail = head;
    for (int i = 1; i< count; i ++) {
        ListNode* p = new ListNode(beginVal + i);
        tail->next = p;
        tail = p;
    }

    return head;
}

ListNode* constructVecList(vector<int> src){

    ListNode* head = new ListNode(src[0]);

    ListNode* tail = head;
    for (int i = 1; i< src.size(); i ++) {
        ListNode* p = new ListNode(src[i]);
        tail->next = p;
        tail = p;
    }

    return head;
}

void printList(ListNode* head){
    ListNode* p = head;
    while (p != NULL) {
        cout<<p->val<< " ";
        p = p->next;
    }
    cout<<endl;
}

ListNode* getListTail(ListNode* head){
    ListNode* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    return p;
}


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* resultHead = NULL;
        ListNode* resultTail = NULL;

        while(p != NULL && q != NULL){
            int r;
            r = p->val + q->val + carry;
            carry = r/10;
            r = r % 10;
            if (resultHead == NULL){
                resultHead = new ListNode(r);
                resultTail = resultHead;
            }else{
                ListNode* k = new ListNode(r);
                resultTail -> next = k;
                resultTail = k;
            }

            p = p->next;
            q = q->next;
        }

        while(p!=NULL){
            int val = p->val;
            if (carry != 0){
                val += carry;
                carry = val/10;
                val = val%10;
            }

            ListNode* k = new ListNode(val);
            resultTail ->next = k;
            resultTail = k;
            p = p->next;
        }

        while(q!=NULL){
            int val = q->val;
            if (carry != 0){
                val += carry;
                carry = val/10;
                val = val%10;
            }
            ListNode* k = new ListNode(val);
            resultTail ->next = k;
            resultTail = k;
            q = q->next;
        }

        if (carry>0){
            ListNode* k = new ListNode(carry);
            resultTail -> next = k;
            resultTail = k;
        }
        
        return resultHead;
    }
};

void testCase(){
    Solution a ;
    vector<int> l1;
    vector<int> l2;
    l1.push_back(5);
    l2.push_back(5);

    ListNode* head1 = constructVecList(l1);
    ListNode* head2 = constructVecList(l2);

    ListNode* head3 = a.addTwoNumbers(head1, head2);

    printList(head1);
    printList(head2);
    printList(head3);
}


