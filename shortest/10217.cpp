#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 110
#define COST_MAX 10005
#define INF 1000000000


using namespace std;

int T;
int V,E,Start;
vector<pair<int,pair<int,int > > > Vertext[105];
int Dist[MAX][COST_MAX];
// int cost_Time[MAX];

void di(int M){
    priority_queue<pair<int, pair<int,int> > > PQ;
    // Cost To Time
    PQ.push(make_pair(0, make_pair(1,0 )));
    Dist[1][0] = 0;

    while(!PQ.empty()){
        int Time = -PQ.top().first;
        int Cur = PQ.top().second.first;
        int Cost = PQ.top().second.second;
        PQ.pop();

        if(Dist[Cur][Cost] < Time) continue;

        for(int i=0; i<Vertext[Cur].size(); i++){
            int Next = Vertext[Cur][i].first;
            int nCost = Vertext[Cur][i].second.first + Cost;
            int nTime = Vertext[Cur][i].second.second + Time;

            if(nCost > M) continue;

            if(Dist[Next][nCost] <= nTime) continue;

            for(int j=nCost; j<=M; j++){
                if(Dist[Next][j] > nTime){
                    Dist[Next][j] = nTime;
                }
            }
            PQ.push(make_pair(-Dist[Next][nCost], make_pair(Next, nCost)));
            // if(Dist[Next][nCost] > nTime && Cost + nCost <= M ){
            //     Dist[Next] = Cost + nCost;
            //     cost_Time[Next] = nTime + Time;
            //     PQ.push(make_pair(-cost_Time[Next], make_pair(Next, Cost+nCost)));
            // }
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for(int i=0; i<T; i++){
        int N,M,K;
        cin >> N >> M >> K;


        for(int j=1; j<=100; j++){
            Vertext[j].clear();
            for(int k=0; k<= 10000; k++){
                Dist[j][k] = INF;
            }
        }

        for(int j=0; j<K; j++){
            int from,to,cost,time;
            cin >> from >> to >> cost >>time;
            Vertext[from].push_back(make_pair(to, make_pair(cost,time)));
        }

        di(M);

        int ans =INF;
        for(int z=1; z<=M; z++){
            ans = min(ans,Dist[N][z]);
        }

        if(ans == INF) cout << "Poor KCM\n";
        else cout << ans << '\n';
    }
}