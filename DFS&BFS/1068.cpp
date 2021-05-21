#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;

int visited[51];
int degree[51];
int graph[51][51];

void dfs(int idx){
    degree[idx] = -1;
    // cout << idx << " " << degree[idx] << '\n';

    visited[idx] = 1;


    for(int i=0; i<N; i++){
        if(graph[idx][i] && !visited[i]){
            
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int tmp;
    int root;
    for(int i=0; i<N; i++){
        cin >> tmp;
        if(tmp == -1)
            root = i;
        else{
            graph[tmp][i] = 1;
            degree[tmp]++;
        }
    }

    int remove_node;

    cin >> remove_node;

    if(remove_node == root){
        cout << 0 << '\n';
        return 0;
    }

    dfs(remove_node);

    for(int i=0; i<N; i++){
        if(graph[i][remove_node]){
            degree[i] -= 1;
        }
    }

    int leaf_count = 0;
    for(int i=0; i < N; i++){
        if(degree[i] == 0)
            leaf_count++;
    }

    cout << leaf_count << '\n';
}