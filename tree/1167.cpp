#include <cstring>
#include <vector>
#include <iostream>
#define MAX 100001

using namespace std;

struct Node{
    int index;
    int dist;
};
int v, maxDist, maxNode;
bool visit[MAX];
vector<Node> graph[MAX];

void dfs(int node, int dist){
    visit[node] = true;

    if(maxDist < dist){
        maxDist = dist;
        maxNode = node;
    }

    for(int i=0; i<graph[node].size(); i++){
        int n_node = graph[node][i].index;
        int n_dist = graph[node][i].dist;
        if(visit[n_node] != true)
            dfs(n_node, dist + n_dist);
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v;
    int fr,to,dist;
    for(int i=0; i<v; i++){
        cin >>fr;
        
        while(true){
            cin >> to;
            if(to == -1)
                break;
            cin >> dist;
            Node fron_elem;
            fron_elem.index = to;
            fron_elem.dist = dist;
            Node to_elem;
            to_elem.index = fr;
            to_elem.dist = dist;
            graph[fr].push_back(fron_elem);
            graph[to].push_back(to_elem);
        }
    }
    dfs(1,0);
    memset(visit, 0, sizeof(visit));
    dfs(maxNode, 0);

    cout << maxDist;
    
}