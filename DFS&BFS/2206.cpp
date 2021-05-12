#include <iostream>
#include <cstring>
#include <queue>
#define MAX 1000

using namespace std;

int maze[MAX][MAX];
int len[MAX][MAX][2];

int x_move[4] = {0,0,-1,1};
int y_move[4] = {1,-1,0,0};

int N,M;

queue<pair<pair<int, int>, pair<int,int> > > q;

int bfs() {
    
    q.push(make_pair(make_pair(0,0), make_pair(0,1)));
    len[0][0][0] = 1;

    while(!q.empty()){
        int x= q.front().first.second;
        int y = q.front().first.first;
        int B= q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        if( x == M-1 && y==N-1){
            return cnt;
        }

        for(int i=0; i<4; i++){
            int x_cord = x + x_move[i];
            int y_cord = y + y_move[i];

            if(x_cord < 0 || y_cord < 0 || x_cord >=M || y_cord >= N) continue;

            if(maze[y_cord][x_cord] == 1 && B == 0){
                len[y_cord][x_cord][1] = true;
                q.push(make_pair(make_pair(y_cord, x_cord), make_pair(B + 1, cnt + 1)));
            }
            else if(maze[y_cord][x_cord] == 0 && len[y_cord][x_cord][B] == 0){
                len[y_cord][x_cord][B] = true;
                q.push(make_pair(make_pair(y_cord, x_cord), make_pair(B, cnt + 1)));
            }
        } 
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    string temp;
    for(int y=0; y<N; y++){
        cin >> temp;
        for(int x=0; x<M; x++){
            maze[y][x] = temp[x] - '0';
        }
    }
    int ans = bfs();
    
    cout << ans;

}