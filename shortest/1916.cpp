#include <iostream>
#include <vector>
#include <queue>

#define MAX 1005
#define INF 987654321

using namespace std;

int N,M;

vector<pair<int, int> > graph[MAX];
int Dist[MAX];

void stra(int start) {
    priority_queue<pair<int,int> > pq;
    pq.push(make_pair(0,start));
    Dist[start] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        int next = pq.top().second;
        pq.pop();

        for(int i=0; i < graph[next].size(); i++){
            int n_cost = graph[next][i].second;
            int n_node = graph[next][i].first;

            if(Dist[n_node] > Dist[next] + n_cost){
                Dist[n_node] = cost + n_cost;
                pq.push(make_pair(-Dist[n_node], n_node));
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    int from,to,weight;
    for(int i=0; i<M; i++){
        cin >> from >> to >> weight;
        graph[from].push_back(make_pair(to,weight));
    }
    for(int i=1; i<=N; i++){
        Dist[i] = INF;
    }

    cin >> from >> to;

    stra(from);

    cout << Dist[to];


}