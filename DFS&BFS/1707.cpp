#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int K,V,E;

const int MAX = 20000+1;

vector<int> graph[MAX];

int nodeColor[MAX];


void dfs(int nodeNum, int color) {
    nodeColor[nodeNum] = color;

    for(int i=0; i< graph[nodeNum].size(); i++){
        int next = graph[nodeNum][i];
        if(!nodeColor[next])
            dfs(next, 3-color);
    }
}

bool isBipartiteGraph(){
    for(int i=1; i<=V; i++){
        for(int j=0; j<graph[i].size(); j++){
            int next = graph[i][j];
            if(nodeColor[i] == nodeColor[next])
                return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K;

    for(int i=0; i<K; i++){
        for(int j=1;j<MAX;j++)
            graph[j].clear();
        memset(nodeColor,0,sizeof(nodeColor));
        cin >> V >> E;
        for(int j=0; j<E; j++){
            int node1, node2;
            cin >> node1 >> node2;

            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }
        for (int j = 1; j <= V; j++)
            if (nodeColor[j] == 0)
                dfs(j, 1); //1번 색깔부터 시작

 

        if (isBipartiteGraph())

            cout << "YES" << endl;

        else

            cout << "NO" << endl;

    }
}