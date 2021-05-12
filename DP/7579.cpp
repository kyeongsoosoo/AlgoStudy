#include <iostream>

using namespace std;

int N,M;
int m[101] = {0, };
int c[101] = {0, };
int DP[101][10001] = {0, };
int result = 1000000000;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);

    cin >> N >> M;

    for(int i=1; i<= N; i++){
        cin >> m[i];
    }

    for(int i=1; i<=N; i++){
        cin >> c[i];
    }

    for(int i=1; i<= N; i++){
        for(int j=0; j <= 10000; j++){
            if(c[i] <= j)
                DP[i][j] = max(DP[i-1][j], DP[i-1][j - c[i]] + m[i]);
            else
                DP[i][j] = DP[i-1][j];
            if(DP[i][j] >= M) result = min(result,j);
        }
    }

    cout << result << endl;

    return 0;
}