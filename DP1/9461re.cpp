#include <iostream>

using namespace std;

int main() {
    long long DP[101] = {1,1,1,2,2,3};
    int testN;
    cin >> testN;
    for(int i=0; i<testN; i++){
        int N;
        cin >> N;
        for(int i= 6; i<N; i++){
            DP[i] = DP[i-5] + DP[i-1];
        }
        cout << DP[N-1] << endl;
    }
}