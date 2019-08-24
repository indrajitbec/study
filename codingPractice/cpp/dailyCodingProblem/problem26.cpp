// [Medium]

// This problem was asked by Google.

// Given a singly linked list and an integer k, 
// remove the kth last element from the list. k is guaranteed to be smaller than the length of the list.

// The list is very long, so making more than one pass is prohibitively expensive.

// Do this in constant space and in one pass.

#include<iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val):val(val),next(nullptr) {}
};

class ListUtil {
public :

    static void DeleteLastKth(ListNode *head , int k) {
            ListNode *second = head;
            int  i = 0;
            for(; i < k+1 && second; i++, second = second->next);

            if(i<k-1) {
                return;
            }

            while(second) {
                head = head->next;
                second = second->next;
            }

            second = head->next;
            head->next = second->next;

            delete second;
    }
};

int main() {
    ListNode *head = new ListNode(6);

    ListNode *t = new ListNode(5);
    t->next = head;
    head = t;
    t = new ListNode(4);
    t->next = head;
    head = t;

    t = new ListNode(3);
    t->next = head;
    head = t;

    t = new ListNode(2);
    t->next = head;
    head = t;

    t = new ListNode(1);
    t->next = head;
    head = t;

    cout << "Original:";

    t = head;
    while(t) {
        cout << t->val<<" ";
        t = t->next;
    }
    cout << endl;

    ListUtil::DeleteLastKth(head,3);

    cout << "Modified:";

    t= head;
    while(t) {
        cout << t->val<<" ";
        t = t->next;
    }
    cout << endl;

}