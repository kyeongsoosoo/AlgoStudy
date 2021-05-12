#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N,M;

bool check[1001];
int graph[1001][1001];
queue<int> q;


void bfs(){
    int n = q.front();
    q.pop();
    
    for(int i=1; i<=N; i++){
        if(graph[n][i] && !check[i]){
            q.push(i);
            check[i] = true;
            bfs();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    int start, to;

    for(int i=0; i<M; i++){
        cin >> start >> to;

        graph[start][to] = 1;
        graph[to][start] = 1;

    }

    int cnt = 0;

    q.push(start);
    check[start] = 1;
    cnt++;
    bfs();

    for(int i=1; i<=N; i++){
        if(!check[i]){
            q.push(i);
            check[start] = true;
            bfs();
            cnt++;
        }
    }
    cout << cnt;
}