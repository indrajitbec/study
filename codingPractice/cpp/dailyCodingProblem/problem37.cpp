// [Easy]
// This problem was asked by Google.
// 
// The power set of a set is the set of all its subsets. 
// Write a function that, given a set, generates its power set.
// 
// For example, given the set {1, 2, 3}, 
// it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.
// 
// You may also use a list or array to represent a set.
// O(!N)
#include<iostream>
#include<vector>

using namespace std;

class PowerSet {
	public:
		static vector<vector<int>> Generate(vector<int> &nums) {
			vector<vector<int>> res;

			res.push_back(vector<int>());
			
			for(auto num : nums) {
				int last = res.size();
				for(int i = 0; i < last; i++) {
					auto temp = new vector<int>(res[i].begin(), res[i].end());
					temp->push_back(num);
					res.push_back(*temp);
				}
			}
			return res;
		}
};

int main(int argc, char*argv[]) {
	vector<int> arr = {1,2,3};
	if(argc > 1) {
		arr.resize(0);
		for(int i =1; i < argc; i++) {
			arr.push_back(stoi(argv[i]));
		}
	}

	auto res = PowerSet::Generate(arr); 

	cout << "{";
	for(auto v : res) {
		cout <<"{";
		for(auto n : v) {
			cout<<n<<",";
		}
		cout <<"},";
	}
	cout << endl;
}
