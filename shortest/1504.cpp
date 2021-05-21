#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 20005
#define INF 987654321

using namespace std;

int V,E,Start;
int v1,v2;
int Dist[3][MAX];
vector<pair<int,int> > Vertex[MAX];

void di(int idx,int start){
    priority_queue<pair<int,int> > PQ;
    PQ.push(make_pair(0,start));
    Dist[idx][start] = 0;

    while(!PQ.empty()){
        int Cost = -PQ.top().first;
        int Cur = PQ.top().second;
        PQ.pop();

        for(int i=0; i<Vertex[Cur].size(); i++){
            int Next = Vertex[Cur][i].first;
            int nCost = Vertex[Cur][i].second;

            if(Dist[idx][Next] > Cost + nCost){
                Dist[idx][Next] = Cost + nCost;
                PQ.push(make_pair(-Dist[idx][Next], Next));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E;

    for(int i=0; i<E; i++){
        int a,b,c;
        cin >> a >> b >> c;
        Vertex[a].push_back(make_pair(b,c));
        Vertex[b].push_back(make_pair(a,c));
    }

    

    cin >> v1 >> v2;

    for(int i =1; i<= V; i++){
        for(int j=0; j<3; j++){
            Dist[j][i] = INF;
        }
    }

    di(0,1);
    di(1,v1);
    di(2,v2);

    int opt1 = Dist[0][v1] + Dist[1][v2] + Dist[2][V];
    int opt2 = Dist[0][v2] + Dist[2][v1] + Dist[1][V];
    // cout << Dist[0][v1] << " " << Dist[1][v2] << " " << Dist[2][V] <<'\n';
    // cout << Dist[0][v2] << " " << Dist[2][v1] << " " << Dist[1][V] <<'\n';
    // cout << opt1 << " " << opt2 <<'\n';
    int ans = min(opt1, opt2);

    if(ans > INF || ans < 0){
        cout << -1;
    }
    else
        cout << ans;


    
    
    // for (int i=1; i<= V; i++){
    //     if(Dist[i] == INF) cout << "INF" << '\n';
    //     else cout << Dist[i] << '\n';
    // }
}