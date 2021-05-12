#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int M,N,H;

int toma[100][100][100];
int visited[100][100][100];

int x_move[6] = {0,0,-1,1,0,0};
int y_move[6] = {1,-1,0,0,0,0};
int z_move[6] = {0,0,0,0,1,-1};

queue<vector<int> > q;

int day_count = 0 ;
int toma_count = 0;
int empty_basket = 0;

void bfs(){
    vector<int> t_arr;
    int size = q.size();
    int nxt_size = 0;

    while(!q.empty()){
        
        nxt_size = 0;
        day_count++;

        for(int i=0; i<size; i++){
            t_arr = q.front();
            q.pop();

            
            vector<int> nxt;
            if(toma[t_arr[0]][t_arr[1]][t_arr[2]] == 1){
                for(int j=0; j<6; j++){
                    nxt.clear();
                    int x_pos = t_arr[2] + x_move[j];
                    int y_pos = t_arr[1] + y_move[j];
                    int z_pos = t_arr[0] + z_move[j];

                    if(x_pos <0 || x_pos >= M || y_pos <0 || y_pos >= N || z_pos <0 || z_pos >= H ) continue;

                    if(toma[z_pos][y_pos][x_pos] == 0 && !visited[z_pos][y_pos][x_pos]){
                        toma[z_pos][y_pos][x_pos] = 1;
                        visited[z_pos][y_pos][x_pos] = 1;
                        
                        nxt.push_back(z_pos);
                        nxt.push_back(y_pos);
                        nxt.push_back(x_pos);
                       
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

    cin >> M >> N >> H;
    int tmp;
    vector<int> tmp_array;
    for(int z=0; z<H; z++){
        for(int y=0; y<N; y++){
            for(int x=0; x<M; x++){
               
                cin >> tmp;
                toma[z][y][x] = tmp;
                
                if(tmp == 1){
                    tmp_array.push_back(z);
                    tmp_array.push_back(y);
                    tmp_array.push_back(x);
                    // cout << tmp_array[0] << " " << tmp_array[1] << " " << tmp_array[2] << '\n';
                    q.push(tmp_array);
                    tmp_array.clear();
                    visited[z][y][x] = 1;
                    toma_count++;
                    
                }
                else if(tmp == -1){
                    empty_basket++;
                }
            }
        }
    }
    bfs();
    int total = M*N*H -empty_basket;
    if(toma_count != total){
        cout << "-1";
    } else if( toma_count == total && day_count == 1){
        cout << "0";
    } else{
        cout << day_count-1;
    }


}