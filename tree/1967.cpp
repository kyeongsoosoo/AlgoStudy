#include <iostream>
#include <cstring>
#include <vector>
#define MAX 10001

using namespace std;

struct Node{
    int idx;
    int weight;
};

vector<Node> graph[MAX];
bool visit[MAX];
int maxNode, maxDist;
int N;

void dfs(int node, int dist){
    visit[node] = true;

    if(maxDist < dist){
        maxDist = dist;
        maxNode = node;
    }

    for(int i=0; i<graph[node].size(); i++){
        int n_node = graph[node][i].idx;
        int n_dist = graph[node][i].weight;
        if(!visit[n_node])
            dfs(n_node, dist + n_dist);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int par, child, w;
    for(int i=0; i<N-1; i++){
        cin >> par >> child >> w;
        Node c_node = {
            child, w
        };
        Node p_node = {
            par, w
        };
        graph[par].push_back(c_node);
        graph[child].push_back(p_node);
        
    }

    dfs(1,0);
    memset(visit, 0 , sizeof(visit));
    dfs(maxNode, 0);

    cout << maxDist;
}