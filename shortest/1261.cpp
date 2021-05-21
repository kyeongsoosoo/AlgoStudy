#include <iostream>
#include <queue>

#define MAX 101
#define INF 987654321

using namespace std;

int M,N;
int MAP[MAX][MAX];
int Dist[MAX][MAX];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void BFS(int a, int b){
    queue<pair<int, int> > Q;
    Q.push(make_pair(a, b));
    Dist[a][b] = 0;

    while (!Q.empty()){
        int y = Q.front().first;
        int x = Q.front().second;
        Q.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= M || ny >= N) continue;

            if(MAP[ny][nx] == 1){
                if(Dist[ny][nx] > Dist[y][x] + 1 ){
                    Dist[ny][nx] = Dist[y][x] + 1;
                    Q.push(make_pair(ny,nx));
                }
            }
            else if (MAP[ny][nx] == 0){
                if(Dist[ny][nx] > Dist[y][x]){
                    Dist[ny][nx] = Dist[y][x];
                    Q.push(make_pair(ny,nx));
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;

    string temp;
    for(int i=0; i<N; i++){
        cin >> temp;
        for(int j=0; j<M; j++){
            MAP[i][j] = temp[j] - '0';
            Dist[i][j] = INF;
        }
    }
    BFS(0,0);

    cout << Dist[N-1][M-1];


}