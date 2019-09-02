// [Hard]
// This problem was asked by Google.
// 
// Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array 
// so that all the Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array.
// 
// Do this in linear time and in-place.
// 
// For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].



// Dutch national flag problem
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class SortRGB {
	public:
		static void Sort(vector<char> &arr) {
			int n = arr.size();

			int lo = 0, mid = 0, hi = n-1;
			while(mid <= hi) {
				switch(arr[mid]) {
					case 'R':
						swap(arr[lo],arr[mid]);
						lo++;
						mid++;
						break;
					case 'G':
						mid++;
						break;
					case 'B':
						swap(arr[hi],arr[mid]);
						hi--;
						break;

				}
			}
		}
};

int main() {
	vector<char> arr = {'G', 'B', 'R', 'R', 'B', 'R', 'G'};
	SortRGB::Sort(arr);
	for(auto i : arr) {
		cout << i;
	}
	cout << endl;
	return 0;
}
