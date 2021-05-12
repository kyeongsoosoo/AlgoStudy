#include <iostream>
#include <cstring>

using namespace std;

int T, M, N, K;

int X,Y;

int x_move[4] = {0,0,-1,1};
int y_move[4] = {1,-1,0,0};

int chu[51][51];
int visited[51][51];

void dfs(int x_idx, int y_idx){

    for(int i = 0; i <=3; i++){
        int x_cord = x_idx + x_move[i];
        int y_cord = y_idx + y_move[i];

        if(x_cord < 0 || x_cord >= M || y_cord < 0 || y_cord >= N) {
            continue;}

        if(chu[x_cord][y_cord] && !visited[x_cord][y_cord]){
            visited[x_cord][y_cord] = 1;
            dfs(x_cord,y_cord);
        }
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for(int i=0; i<T; i++){
        int warm_count = 0;
        cin >> M >> N >> K;
        for(int j=0; j<K; j++){
            cin >> X >> Y;
            chu[X][Y] = 1;
        }

        for(int a= 0; a <M; a++){
            for(int b=0; b < N; b++){
                if(chu[a][b] && !visited[a][b]){
                    warm_count++;
                    visited[a][b] = 1;
                    dfs(a,b);
                }
            }
        }
        memset(visited, 0, sizeof(visited));
        memset(chu, 0, sizeof(chu));
        cout << warm_count << '\n';
    }
}