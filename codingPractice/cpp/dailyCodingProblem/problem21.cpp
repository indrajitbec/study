// [Easy]

// This problem was asked by Snapchat.

// Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), 
// find the minimum number of rooms required.

// For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>


using namespace std;

class LectureCoordinator {
private:
    struct cmpEnd {
        bool operator () (const pair<int,int> &x, const pair<int,int> &y) {
            return x.second > y.second;
        }
    };
public:
    static int FindMinimumRooms(vector<pair<int,int>> &lectures) {
        int n = lectures.size();

        int min_rooms = 0;

        sort(lectures.begin(), lectures.end());

        priority_queue<pair<int,int>, vector<pair<int,int>> , cmpEnd> minScheduled;

        for(auto lec : lectures) {
            if(!minScheduled.empty() && lec.first > minScheduled.top().second) {
                minScheduled.pop();
            }
            minScheduled.push(lec);
            int current_rooms = minScheduled.size();
            min_rooms = max(min_rooms, current_rooms);
        }

        return min_rooms;
    }
};

int main() {

    vector<pair<int,int>> lectures = {{30, 75}, {0, 50},{60, 150}};

    cout << LectureCoordinator::FindMinimumRooms(lectures) << endl;

    vector<pair<int,int>> lectures1;

    cout << LectureCoordinator::FindMinimumRooms(lectures1) << endl;
    
    return 0;
}

