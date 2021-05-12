#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N,M,V;

int graph[1001][1001];
int visited[1001];
queue<int> q;

void DFS(int idx){
    cout << idx << " ";

    for(int i=1; i<=N; i++){
        if(graph[idx][i] && !visited[i]){
            visited[i] = 1;
            DFS(i);
        }
    }
}

void BFS(int idx){
    q.push(idx);
    visited[idx] = 1;

    while(!q.empty()){
        idx = q.front();
        q.pop();

        cout << idx << " ";

        for(int i=1; i<=N; i++){
            if(graph[idx][i] && !visited[i]){
                visited[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> V;

    for(int i=0; i<M; i++){
        int from,to;
        cin >> from >> to;
        graph[from][to] = 1;
        graph[to][from] = 1;
    }
    visited[V] = 1;
    DFS(V);

    cout << '\n';

    memset(visited, 0, sizeof(visited));
    BFS(V);
}