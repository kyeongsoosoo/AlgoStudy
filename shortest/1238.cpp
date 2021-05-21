#include <iostream>
#include <queue>
#include <vector>

#define MAX 1001
#define INF 987654321

using namespace std;

int N,M,X;

vector<pair<int,int> > graph[MAX];

int Distance[MAX][MAX];

void find_path(int start_idx){

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> X;

    int from,to,time;
    for(int i=0; i<M; i++){
        cin >> from >> to >> time;
        graph[from].push_back(make_pair(to,time));
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            Distance[i][j] = INF;
        }
    }


}