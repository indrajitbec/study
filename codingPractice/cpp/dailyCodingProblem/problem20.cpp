// [Easy]
// This problem was asked by Google.

// Given two singly linked lists that intersect at some point, find the intersecting node. 
// The lists are non-cyclical.

// For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

// In this example, assume nodes with the same value are the exact same node objects.

// Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.

#include<iostream>
#include<climits>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val, ListNode *next=nullptr):val(val), next(next) {}
};

ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;
    while(head != nullptr) {
        ListNode *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

int findIntersection(ListNode *l1, ListNode *l2) {
    if(l1==nullptr && l2==nullptr) {
        return INT_MAX;
    }
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    
    if(l1==nullptr) {
        return l2->val;
    }
    if(l2==nullptr) {
        return l1->val;
    }

    while(l1->next != nullptr && l2->next != nullptr) {
        if(l1->next->val != l2->next->val) {
            return l1->val;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    if(l1->next != nullptr) {
        return l1->val;
    }
    if(l2->next != nullptr) {
        return l2->val;
    }

    return INT_MAX;
}

ListNode *createList(vector<int> arr) {
    ListNode *head = nullptr;
    for(auto it = arr.rbegin(); it != arr.rend(); it++) {
        auto node = new ListNode(*it);
        node->next = head;
        head = node;
    }
    return head;
}
 
int main() {

    cout << findIntersection(createList({3 , 7 , 8 ,10}), createList({99 , 1 , 8 , 10}))<< endl;
    return 0;
}