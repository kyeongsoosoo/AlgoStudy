#include <iostream>
#include <queue>

using namespace std;

int M,N;

int toma[1000][1000];
int visited[1000][1000];

int x_move[4] = {0,0,-1,1};
int y_move[4] = {1,-1,0,0};

queue<pair<int, int> > q;

int day_count = 0 ;
int toma_count = 0;
int empty_basket = 0;

void bfs(){
    pair<int,int> t_pair;
    int size = q.size();
    int nxt_size = 0;

    while(!q.empty()){
        
        nxt_size = 0;
        day_count++;

        for(int i=0; i<size; i++){
            t_pair = q.front();
            q.pop();

            
            if(toma[t_pair.first][t_pair.second] == 1){
                for(int j=0; j<4; j++){
                    pair<int,int> nxt;
                    int x_pos = t_pair.second + x_move[j];
                    int y_pos = t_pair.first + y_move[j];

                    if(x_pos <0 || x_pos >= M || y_pos <0 || y_pos >= N) continue;

                    if(toma[y_pos][x_pos] == 0 && !visited[y_pos][x_pos]){
                        toma[y_pos][x_pos] = 1;
                        visited[y_pos][x_pos] = 1;
                        nxt.first = y_pos;
                        nxt.second = x_pos;
                        q.push(nxt);
                        nxt_size++;
                        toma_count++;
                    }
                }
            }

        }
        size = nxt_size;
        
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M >> N;
    int tmp;
    pair<int,int> tmp_pair;
    for(int y=0; y<N; y++){
        for(int x=0; x<M; x++){
            cin >> tmp;
            toma[y][x] = tmp;
            if(tmp == 1){
                tmp_pair.first = y;
                tmp_pair.second = x;
                q.push(tmp_pair);
                visited[y][x] = 1;
                toma_count++;
            }
            else if(tmp == -1){
                empty_basket++;
            }
        }
    }
    bfs();
    int total = M*N -empty_basket;
    if(toma_count != total){
        cout << "-1";
    } else if( toma_count == total && day_count == 1){
        cout << "0";
    } else{
        cout << day_count-1;
    }


}