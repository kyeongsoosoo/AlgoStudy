#include <iostream>
#include <queue>

using namespace std;

int N,M;

int arr[101][101];
int visited[101][101];

int d[101][101];
int p[101][101];

int x_move[4] = {0,0,-1,1};
int y_move[4] = {1,-1,0,0};

queue<pair<int,int> > q;

void bfs(int x_idx, int y_idx){
    pair<int,int> t = make_pair(x_idx,y_idx);
    q.push(t);
    visited[t.second][t.first] = 1;
    d[y_idx][x_idx] = 1;
    

    while(!q.empty()){
        pair<int,int> temp = q.front();
        q.pop();

        for(int i = 0; i <=3; i++){
            int x_cord = temp.first + x_move[i];
            int y_cord = temp.second + y_move[i];

            if(x_cord < 0 || x_cord >= M || y_cord < 0 || y_cord >= N) {
                continue;}

            else if(arr[y_cord][x_cord] && !visited[y_cord][x_cord]){
                visited[y_cord][x_cord] = 1;
                d[y_cord][x_cord] = d[temp.second][temp.first] + 1;
                
                t.first = x_cord;
                t.second = y_cord;
                
                q.push(t);
                
        }
    }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    string temp;

    for(int i=0; i<N; i++){
        cin >> temp;
        for(int j=0; j<M; j++){
            arr[i][j] = temp[j] - 48;
        }
    }

    bfs(0,0);

    cout << d[N-1][M-1];
}