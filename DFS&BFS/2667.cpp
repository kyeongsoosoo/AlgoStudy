#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[26][26];
int visited[26][26];
vector<int> danji;

int x_move[4] = {0, 0, 1, -1};
int y_move[4] = {1, -1, 0, 0};

int N;

int hos_count = 1;

string temp;

void search(int x, int y){
    hos_count++;
    for(int i=0; i<5; i++){
        int x_cord = x+x_move[i];
        int y_cord = y+y_move[i];
        if(x_cord < 0 ||  y_cord < 0 || x_cord >=N || y_cord >= N) continue;
        else if(arr[x_cord][y_cord] && !visited[x_cord][y_cord]){
            visited[x_cord][y_cord] = 1;
            search(x_cord,y_cord);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i=0; i<N; i++){
        cin >> temp;
        for(int j=0; j<N; j++){
            arr[i][j] = temp[j] -48;
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] && !visited[i][j]){
                hos_count = 0;
                visited[i][j] = 1;
                search(i,j);
                danji.push_back(hos_count);
            }
        }
    }
    sort(danji.begin(), danji.end());

    cout << danji.size() << '\n';

    for(int i=0; i<danji.size(); i++){
        cout << danji[i] << '\n';
    }
}