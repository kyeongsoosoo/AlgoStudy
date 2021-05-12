#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int K,V,E;

const int MAX = 20000+1;

vector<int> graph[MAX];

int p_color[MAX];


void color_dfs(int start, int color){
    p_color[start] = color;

    for(int i=0; i<graph[start].size(); i++){
        if(!p_color[graph[start][i]])
            color_dfs(graph[start][i],3-color);
    }
}

bool canBipartite(){
    for(int i=1; i<=V; i++){
        for(int j=0; j<graph[i].size(); j++){
            if(p_color[i] == p_color[graph[i][j]])
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

    int from,to;

    for(int i=0; i<K; i++){
        //초기화
        for(int j=1; j<MAX; j++){
            graph[j].clear();
        }
        memset(p_color,0,sizeof(p_color));
        cin >> V >> E;
        for(int j=0; j<E; j++){
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        for(int a=1; a<=V; a++){
            if(!p_color[a])
                color_dfs(a,1);
        }
        bool ans = canBipartite();
        string ans_st =ans ? "YES" : "NO";
        cout << ans_st << '\n';
    }

}