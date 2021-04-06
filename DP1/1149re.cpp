#include <iostream>
#define min(a,b) (a<b ? a : b)

using namespace std;

int main() {
    int color[1000][3];
    int DP[1000][3];
    int N;
    cin >> N;
    for(int i=0 ; i< N; i++){
        scanf("%d %d %d", &color[i][0],&color[i][1],&color[i][2]);
        if(i == 0){
            DP[i][0] = color[i][0];
            DP[i][1] = color[i][1];
            DP[i][2] = color[i][2];
        }
    }
    for(int i=1; i<N; i++){
        for(int j=0; j<3; j++){
            DP[i][j] = min(DP[i-1][(j+1)%3], DP[i-1][(j+2)%3]) + color[i][j];
        }
    }
    cout << min(DP[N-1][0], min(DP[N-1][1],DP[N-1][2]));
}