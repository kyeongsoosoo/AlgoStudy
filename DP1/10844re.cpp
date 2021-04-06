#include <iostream>
#define limit 1000000000

using namespace std;

int main() {
    long long DP[100][10] = {{0,1,1,1,1,1,1,1,1,1},};
    int N;
    long long sum=0;
    cin >> N;
    for(int i=1; i<N; i++){
        for(int j=0; j<10; j++){
            if(j==0){
                DP[i][j] = (DP[i-1][j+1])%limit;
            }
            else if(j==9){
                DP[i][j] = (DP[i-1][j-1])%limit;
            }
            else{
                DP[i][j] = (DP[i-1][j-1] + DP[i-1][j+1])%limit;
            }
        }
    }
    for(int i=0; i<10;i++){
        sum += DP[N-1][i];
        sum %= limit;
    }
    cout << sum << endl;
}