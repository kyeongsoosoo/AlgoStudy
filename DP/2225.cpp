#include <iostream>
#define MAX 1000000000

int N,K;
long long DP[201][201];


using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for(int i=0; i<= N; i++){
        DP[1][i] = 1;
    }

    for(int k= 2; k <= K; k++){
        for(int n=0; n<=N; n++){
            for(int idx=0; idx<=n; idx++){
                DP[k][n] += DP[k-1][idx];
            }
            DP[k][n] %= MAX;
        }
    }
    cout << DP[K][N];
}