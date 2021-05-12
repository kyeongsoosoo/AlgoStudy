#include <iostream>
#include <vector>

using namespace std;

int N,M;

bool check[1001];
int graph[1001][1001];

void dfs(int idx){
    check[idx] = true;
    
    for(int i=1; i<=N; i++){
        if(graph[idx][i] && !check[i]){
            dfs(i);
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

    for(int i=1; i<=N; i++){
        if(!check[i]){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt;
}