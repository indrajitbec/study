// This problem was asked by Facebook.

// Given a stream of elements too large to store in memory,

// pick a random element from the stream with uniform probability.

//https://www.geeksforgeeks.org/select-a-random-node-from-a-singly-linked-list/

// Resorvoir sampling

#include<iostream>
#include<ctime>
#include<vector>
#include<unistd.h>

using namespace std;

class Stream {
private:
    vector<int>::iterator it;
    vector<int> arr;
public:
    Stream(vector<int> & v) {
        arr = v;
        it  = arr.begin();
    }

    int get() {
        return *it;
    }

    void next() {
        it++;
    }

    bool empty() {
        return it == arr.end();
    }
};

class RandomStream {
public:
    static int pickRandom(Stream &s) {
        int res = s.get();
        s.next();
        srand(time(NULL));

        int i = 2;
        while(!s.empty()) {
            int item = s.get();
            s.next();
            if(rand()%i == 0) {
                res = item;
            }
            i++;
        }

        return res;
    }
};

int main() {
    vector<int> v = {1,2,3,4,5,6,7,8};

    for(int i=0; i<v.size(); i++ ) {
        Stream input(v);
        cout << RandomStream::pickRandom(input) << endl;
        sleep(10);
    }

    return 0;
}