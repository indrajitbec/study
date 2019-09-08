// [Hard]
// This problem was asked by Google.
// 
// Given an array of integers where every integer occurs three times except for one integer, 
// which only occurs once, find and return the non-duplicated integer.
// 
// For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19.
// 
// Do this in O(N) time and O(1) space.

#include<iostream>
#include<vector>

using namespace std;

class DuplicateExceptOne {
	public :
		static int findUniqueNumber(vector<int> & arr) {
			int once = 0, twice = 0;

			for(auto num : arr) {

				twice = twice | (once & num);

				// clear bits apearing twice
				once = once ^ num;

				// clear bits apearing thrise
				int mask = ~(once & twice);

				// Clear bits apearing thrice
				once &= mask;

				// Clear bits apearing thrice
				twice &= mask;

			}
			return once;
		}
};



int main() {
	vector<int> arr = {6, 1, 3, 3, 3, 6, 6};

	cout << DuplicateExceptOne::findUniqueNumber(arr) << endl;
}
