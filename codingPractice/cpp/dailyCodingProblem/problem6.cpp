// [Hard]
// This problem was asked by Google.

// An XOR linked list is a more memory efficient doubly linked list. 
// Instead of each node holding next and prev fields, it holds a field named both,
// which is an XOR of the next node and the previous node.
// Implement an XOR linked list; 
// it has an add(element) which adds the element to the end, and 
// a get(index) which returns the node at index.

// If using a language that has no pointers (such as Python), 
// you can assume you have access to get_pointer and dereference_pointer functions that converts between nodes and memory addresses.


#include<iostream>
using namespace std;

class XORListNode {
    public:
        int val;
        XORListNode *both;
        XORListNode(int val, XORListNode *both = nullptr) : val(val), both(both) {}
};

class XORList {
    private:
        XORListNode *head, *tail;
        XORListNode *XOR(XORListNode *a, XORListNode *b) {
            return ( XORListNode *)(((unsigned) a) ^ ((unsigned) b));
        }
    public:
        XORList() : head(nullptr), tail(nullptr) {}

        void AddElement(int item) {
            auto node = new XORListNode(item);
            if(head == nullptr) {
                head = tail = node;
                return;
            }

            node->both = XOR(tail, nullptr);
            tail->both = XOR(tail->both, node);
            tail = node;

            return;
        }

        int GetElement(int index) {
            XORListNode *previous = nullptr;
            auto current = head;
            while(current && index--) {
                previous = current;
                current = XOR(current->both , previous);
            }

            if(index != 0) {
                throw std::out_of_range("index out of range");
            }

            return previous->val;
        }
};

int main() {

    XORList list;
    list.AddElement(1);
    list.AddElement(2);
    list.AddElement(3);
    list.AddElement(4);
    list.AddElement(5);

    

    try {
        cout << list.GetElement(3) << endl;
        //cout << list.GetElement(5) << endl;
        //cout << list.GetElement(6) << endl;
    }
    catch(std::exception &e) {
        cout << e.what() << endl;
    }
    return 0;
}
