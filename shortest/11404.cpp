#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int graph[101][101];

void floyd(){
    for(int via=1; via <=n; via++){
        for(int from = 1; from <=n; from++){
            if(graph[from][via] == 0)
                continue;
            for(int to = 1; to <= n; to++){
                if(graph[via][to] == 0 || from == to)
                    continue;
                
                if(graph[from][to] == 0 || graph[from][to] > graph[from][via] + graph[via][to])
                    graph[from][to] = graph[from][via] + graph[via][to];
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<m; i++){
        int from,to,cost;
        cin >> from >> to >> cost;

        if(!graph[from][to])
            graph[from][to] = cost;
        else
            graph[from][to] = min(graph[from][to], cost);
    }

    floyd();

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++)
            cout << graph[i][j] << " ";
        cout << '\n';
    }

}