#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	unordered_map <string, int> m;

	m["foo"] = 21;
	cout<<m["foo"]<<endl;
	cout<<m["ooo"]<<endl;
	return 0;
}
