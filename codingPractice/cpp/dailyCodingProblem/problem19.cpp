// This problem was asked by Facebook.

// A builder is looking to build a row of N houses that can be of K different colors.
// He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.

// Given an N by K matrix where the nth row and kth column represents 
// the cost to build the nth house with kth color, 
// return the minimum cost which achieves this goal.

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class PaintBuilding {
public:
    static int minimumCost(int N, int K, vector<vector<int>> & cost) {
        vector<vector<int>> dp(N, vector<int>(K));

        for(int j=0; j < K; j++) {
            dp[0][j] = INT_MAX;
            for(int l=0; l < K; l++) {
                dp[0][j] = min(dp[0][j], cost[0][j]);
            }
        }


        for(int i=1; i<N; i++) {
            for(int c=0; c < K; c++) {
                dp[i][c] = INT_MAX;

                for(int j=0; j<K; j++) {
                    if(j==c) continue;

                    dp[i][j]= min(dp[i][j], dp[i-1][j] + cost[i][j]);
                }
            }
        }

        int minCost = INT_MAX;

        for(int c=0; c<K; c++) {
            minCost = min(minCost, dp[N-1][c]);
        }
        return minCost;
    }
};


int main() {

    vector< vector<int> > cost = {
        {5,6,8},
        {1,3,2},
        {8,9,1},
        {4,5,7}
    };

    cout << PaintBuilding::minimumCost(4, 3, cost) << endl;
}