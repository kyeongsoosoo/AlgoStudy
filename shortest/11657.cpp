#include <iostream>
#include <vector>

#define MAX 510
#define INF 987654321

using namespace std;

int N,M;
long long Dist[MAX];
vector<pair<pair<int,int>, int> > Edge;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i=1; i<=N; i++) Dist[i] = INF;
    for(int i=0; i<M; i++) {
        int From, To, Cost;
        cin >> From >> To >> Cost;
        Edge.push_back(make_pair(make_pair(From, To), Cost));
    }

    Dist[1] = 0;
    for (int i=1; i<= N-1; i++){
        for(int j=0; j<Edge.size(); j++){
            int From = Edge[j].first.first;
            int To = Edge[j].first.second;
            int Cost = Edge[j].second;

            if(Dist[From] == INF) continue;

            if(Dist[To] > Dist[From] + Cost) Dist[To] = Dist[From] + Cost;
        }
    } 

    for(int i=0; i< Edge.size(); i++){
        int From = Edge[i].first.first;
        int To = Edge[i].first.second;
        int Cost = Edge[i].second;

        if(Dist[From] == INF) continue;
        if(Dist[To] > Dist[From] + Cost){
            cout << -1;
            return 0;
        }
    }
    for (int i=2; i<=N; i++){
        if(Dist[i] == INF) cout << -1 << '\n';
        else cout << Dist[i] << '\n';
    }
}