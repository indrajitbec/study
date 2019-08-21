// [Easy]

// This problem was asked by Google.

// You are given an M by N matrix consisting of booleans that represents a board. 
// Each True boolean represents a wall. Each False boolean represents a tile you can walk on.

// Given this matrix, a start coordinate, and an end coordinate, 
// return the minimum number of steps required to reach the end coordinate from the start. 
// If there is no possible path, then return null. You can move up, left, down, and right. 
// You cannot move through walls. You cannot wrap around the edges of the board.

// For example, given the following board:

// [[f, f, f, f],
// [t, t, f, t],
// [f, f, f, f],
// [f, f, f, f]]
// and start = (3, 0) (bottom left) and end = (0, 0) (top left), 
// the minimum number of steps required to reach the end is 7, 
// since we would need to go through (1, 2) because there is a wall everywhere else on the second row.

//BFS

#include<iostream>
#include<vector>
#include<queue>
#include<utility>

using namespace std;

template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
} 

class TileBoard {
private:
    vector<vector<bool>> mat;
    int rows = 0, cols = 0;
    const vector<pair<int,int>> move = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    bool isValid(pair<int,int> point) {
        if(point.first >=0 && point.first <=rows && point.second >=0 && point.second <= cols) {
            return true;
        }
        return false;
    }

public:
    TileBoard(vector<vector<bool>> &mat) {
        this->mat = mat;
        if(this->mat.size() == 0) return;

        rows = this->mat.size()-1;
        cols = this->mat[0].size()-1;
    }
    int minimumSteps(pair<int,int> source , pair<int,int> dest) {
        if(source == dest) {
            return 0;
        }

        if(!isValid(source) || !isValid(dest)) {
            return -1;
        }

        queue<pair<int,int>> q;

        int count = 0;

        q.push(source);

        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                auto point = q.front();
                q.pop();
                if(point == dest) {
                    return count;
                }
                for(auto d : move) {
                    auto new_p = point + d;
                    if(isValid(new_p) && mat[new_p.first][new_p.second]==false) {
                        q.push(new_p);
                    }
                }
            }
            count++;
        }
        return count;
    }

};

int main() {
    vector<vector<bool>> mat = {
                        {false, false, false, false},
                        {true, true, false, true},
                        {false, false, false, false},
                        {false, false, false, false},
                        };
    TileBoard B(mat);

    pair<int,int> src = {3,0}, dest ={0,0};
    cout << B.minimumSteps(src,dest) << endl;
}