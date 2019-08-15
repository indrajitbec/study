// This problem was asked by Twitter.

// You run an e-commerce website and want to record the last N order ids in a log. 
// Implement a data structure to accomplish this, with the following API:

// record(order_id): adds the order_id to the log
// get_last(i): gets the ith last element from the log. 
// i is guaranteed to be smaller than or equal to N.
// You should be as efficient with time and space as possible.

// implement Queue with capacity N

#include<iostream>
#include<vector>
#include<stdexcept>
using namespace std;


class OrderLog {
private:
    vector<int> orders;
    int capacity;
    int front, tail;
public:
    OrderLog(int capacity)
    : orders(capacity), capacity(capacity) {
        front = 0;
        tail = 0;
    }

    void record(int order_id) {
        
        if((tail-front+capacity)%capacity == capacity) {
            //purge one element
            front = (front+1)%capacity;
        }
        orders[tail] = order_id;

        tail = (tail+1)%capacity; 
    }

    int get_Last(int i) {
        i = (tail-i+capacity)%capacity;
        if(i < front) {
            //empty
            throw std::out_of_range("index out of range");
        }
        
        return orders[i];
    }
};

int main() {
    OrderLog ol(5);

    ol.record(4);
    ol.record(3);
    ol.record(2);
    ol.record(1);
    ol.record(0);

    cout << ol.get_Last(3) << endl;
    cout <<ol.get_Last(1) << endl;

    ol.record(-1);

    cout <<ol.get_Last(1) << endl;

    try {   
        cout << ol.get_Last(7) << endl;

    } catch(std::out_of_range &e) {
        cout << e.what() <<endl;
    }
    return 0;
}