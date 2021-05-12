#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <algorithm>

#define MAX 100010

using namespace std;

priority_queue<int, vector<int> > maxQ;
priority_queue<int, vector<int>, greater<int> > minQ;



int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        if(maxQ.size() == minQ.size()){
            maxQ.push(num);
        }
        else {
            minQ.push(num);
        }
        if(maxQ.size() != 0 && minQ.size() != 0 && maxQ.top() > minQ.top()) {
            int maxvalue = maxQ.top();
            int minvalue = minQ.top();
            maxQ.pop();
            minQ.pop();
            maxQ.push(minvalue);
            minQ.push(maxvalue);

        }
        cout << maxQ.top() << "\n";
    }
}



