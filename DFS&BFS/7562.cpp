#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int T, I;
int this_x, this_y;
int to_x, to_y;

int x_move[8] = {-2,-1,1,2,-2,-1,1,2};
int y_move[8] = {1,2,2,1,-1,-2,-2,-1};

int board[300][300];
int visited[300][300];

int find = 0;
int move_n =0 ;

void bfs() {
    move_n =0;
    visited[this_y][this_x] = 1;
    queue<pair<pair<int,int>,int> > q;
    q.push(make_pair(make_pair(this_y,this_x),move_n));

    while(!q.empty()){
        pair<pair<int,int>,int> temp;
        pair<int,int> current = q.front().first;
        int c_move = q.front().second;
        q.pop();

        if( current.second == to_x && current.first == to_y){
            move_n = c_move;
            return;
        }

        for(int i=0; i<8; i++){
            int x_pos = current.second + x_move[i];
            int y_pos = current.first + y_move[i];

            if(x_pos <0 || y_pos<0 || x_pos >= I || y_pos >= I) continue;
            
            if(!visited[y_pos][x_pos]){
                temp.first = make_pair(y_pos,x_pos);
                temp.second = c_move + 1;
                visited[y_pos][x_pos] = 1;
                q.push(temp);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;

    for(int i=0; i<T; i++){
        cin >> I;
        cin >> this_y >> this_x;
        cin >> to_y >> to_x;
        bfs();
        cout << move_n << '\n';
        memset(visited, 0, sizeof(visited));
    }

}