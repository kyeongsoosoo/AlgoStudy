#include <iostream>
#include <cstring>

using namespace std;

int map[501][501];
int DP[501][501];
int a[4] = { 1,0,-1,0};
int b[4] = {0,1,0,-1};
int C,R;

int dfs(int x, int y){
    if (DP[x][y] != -1) return DP[x][y];
    if(x<0 || x >= R || y<0 || y>= C) return 0;
    if (x == 0 && y == 0) return 1;

    DP[x][y] = 0;
    for (int i=0; i<4; i++){
        int nextX = x + a[i];
        int nextY = y + b[i];

        if(map[nextX][nextY] > map[x][y]){
            DP[x][y] += dfs(nextX, nextY);
        }
    }
    return DP[x][y];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> C >> R;
    for(int i=0; i<C; i++){
        for(int j=0; j<R; j++){
            cin >> map[j][i];
        }
    }
    memset(DP, -1 , sizeof(DP));

    cout << dfs(R-1,C-1);

}