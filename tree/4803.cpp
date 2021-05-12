#include <iostream>
#include <vector>
#include <cstring>
#define MAX 501

using namespace std;

vector<int> tree[MAX];
int N,M;

bool visited[MAX];
bool passed[MAX];

int numOfVertex(int nodeNum){
    int cnt = 1;
    visited[nodeNum] = true;

    for(int i=0; i<tree[nodeNum].size(); i++){
        int next = tree[nodeNum][i];
        if(!visited[next])
            cnt += numOfVertex(next);
    }
    return cnt;
}

int numOfEdge(int nodeNum){
    int cnt = tree[nodeNum].size();
    passed[nodeNum] = true;

    for(int i=0; i<tree[nodeNum].size(); i++){
        int next = tree[nodeNum][i];
        if(!passed[next]){
            cnt += numOfEdge(next);
        }
    }
    return cnt;
}


int main(){
    int cnt = 1;

    while(1){
        for(int i=0; i<MAX; i++){
            tree[i].clear();
       }
       cin >> N >> M;
       if(N==0 && M==0) break;

       for(int i=0; i<M; i++){
           int node1, node2;
           cin >> node1 >> node2;

           tree[node1].push_back(node2);
           tree[node2].push_back(node1);
       }

       memset(visited, false, sizeof(visited));
       memset(passed, false, sizeof(passed));

       cout << "Case " << cnt++ << ": ";

       int result = 0;
       for (int i=1; i<= N; i++){
           if(!visited[i]){
               int V = numOfVertex(i);
               int E = numOfEdge(i);
               if(V-1 == E/2){
                   result++;
               }
           }
       }

       switch(result){
            case 0:
                cout << "No trees." << "\n";
                break;
            case 1:
                cout << "There is one tree." << "\n";
                break;
            default:
                cout << "A forest of " << result << " trees." << "\n";
                break;
            
       }
    }


}