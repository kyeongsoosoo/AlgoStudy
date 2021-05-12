#include <iostream>
#define max(a,b) (a>b ? a : b)

using namespace std;

int N;

int bomb[500][500];

int DP[500][500];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int max_day = 0;

int findMax(int r, int c){
    if(DP[r][c])
        return DP[r][c];
    DP[r][c] = 1;

    for(int i=0; i<4; i++){
        int nx = r + dx[i];
        int ny = c + dy[i];

        if(nx < 0 || nx >= N || ny< 0 || ny >= N) continue;
        if(bomb[r][c] >= bomb[nx][ny]) continue;

        DP[r][c] =max(DP[r][c], findMax(nx,ny) + 1);
    }
    return DP[r][c];
    // if(r < N-1 && bomb[r+1][c] > bomb[r][c] )
    //     DP[r][c] = max(DP[r][c],findMax(r+1, c)+1);
    // else if(0< r && bomb[r-1][c] > bomb[r][c])
    //     DP[r][c] = max(DP[r][c],findMax(r-1, c)+1);
    // else if(c < N-1 && bomb[r][c+1] > bomb[r][c])
    //     DP[r][c] = max(DP[r][c],findMax(r, c+1)+1);
    // else if(0< c && bomb[r][c-1] > bomb[r][c])
    //     DP[r][c] = max(DP[r][c],findMax(r, c-1) + 1);
    // return DP[r][c];
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> bomb[i][j];
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int m =findMax(i,j);
            max_day = max(max_day, m);
        }
    }

    cout << max_day;

}