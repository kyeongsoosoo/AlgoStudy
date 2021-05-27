#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 20005
#define INF 987654321

using namespace std;

int V,E;
vector<pair<int,int> > Vertex[20001];
int Start =0;
int Dist[MAX];

void di(int idx){
    priority_queue<pair<int,int> > PQ;
    PQ.push(make_pair(0,idx));
    Dist[idx] = 0;

    while(!PQ.empty()){
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();

        for(int i=0; i<Vertex[Cur].size(); i++){
            int Next = Vertex[Cur][i].first;
            int nCost = Vertex[Cur][i].second;

            if(Dist[Next] > Cost + nCost){
                Dist[Next] = Cost + nCost;
                PQ.push(make_pair(-Dist[Next],Next));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E;
    cin >> Start;

    int u,v,w;
    for(int i=0; i<E; i++){
        cin >> u >> v >> w;
        Vertex[u].push_back(make_pair(v,w));
    }
    for(int i= 1; i<=V; i++){
        Dist[i] = INF;
    }
    di(Start);

    for(int i=1; i<=V; i++){
        if(Dist[i] == INF) cout << "INF" << '\n';
        else cout << Dist[i] << '\n';
    }

}