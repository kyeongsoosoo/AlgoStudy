#include <iostream>
#include <queue>

using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T_N;
    int T_len;
    long long inp;
    cin >> T_N;
    for(int i=0; i<T_N; i++){
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        cin >> T_len;
        for(int j=0; j<T_len; j++){
            cin >> inp;
            pq.push(inp);
        }
        long long fir,sec, sum;
        long long result = 0;
        while(pq.size() != 1){
            fir = pq.top();
            pq.pop();
            sec = pq.top();
            pq.pop();
            sum = fir + sec;
            result += sum;
            pq.push(sum);
        }
        cout << result << '\n';
    }

}