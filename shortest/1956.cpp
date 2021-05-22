#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321

using namespace std;

int V,E;

vector<pair<int , pair<int,int> > > Edge;
int Cost[410][410];

void floyd(){
    for(int via=1; via<=V; via++){
        for(int from=1; from<=V; from++){
            if(Cost[from][via] == INF) continue;
            for(int to=1; to<=V; to++){
                if(Cost[via][to] == INF) continue;
                if(Cost[from][to] > Cost[from][via] + Cost[via][to]){
                    Cost[from][to] = Cost[from][via] + Cost[via][to];
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> V >> E;

    int from,to,cost;

    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            Cost[i][j] = INF;
        }
    }
    

    for(int i=0; i < E; i++){
        cin >> from >> to >> cost;
        Cost[from][to] = cost;
    }

    

    floyd();

    int min_c = INF;

    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            if(i == j) continue;
            min_c = min(min_c, Cost[i][j] + Cost[j][i]);
        }
    }
    if(min_c == INF) cout << -1;
    else cout << min_c;
}