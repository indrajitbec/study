#include<iostream>
#include<queue>

using namespace std;
class mycomparison
{
  bool reverse;
public:
  mycomparison(const bool& revparam=false)
    {reverse=revparam;}
  bool operator() (const int& lhs, const int&rhs) const
  {
    if (reverse) return (lhs>rhs);
    else return (lhs<rhs);
  }
};

int main()
{
    std::priority_queue<int, vector<int>, greater<int> > pq;
    //std::priority_queue<int, vector<int>, mycomparison> pq1(mycomparison(true));
    std::priority_queue<int, vector<int>, mycomparison> pq1;
    int arr[] = {12,4,-3,32,12};

    pq.push(5);
    pq.push(15);
    pq.push(-3);
    pq.push(45);
    pq.push(51);


    for(int i =0 ; i < 5; i++)
        pq1.push(arr[i]);


    cout<<pq.top()<<endl;
    cout<<pq1.top()<<endl;
}
