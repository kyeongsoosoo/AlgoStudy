#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define V_MAX 20001
#define INF 987654321

using namespace std;

int V, E;
int S;
vector<pair<int, int> > Edge[V_MAX];
int di[V_MAX];

void find(int start)
{
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        for (int i = 0; i < Edge[cur].size(); i++)
        {
            int next = Edge[cur][i].first;
            int next_w = Edge[cur][i].second + cost;

            if (di[next] > next_w)
            {
                di[next] = next_w;
                pq.push(make_pair(-next_w, next));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> V >> E;
    cin >> S;

    int u, v, w;
    for (int i = 0; i < E; i++)
    {
        cin >> u >> v >> w;
        Edge[u].push_back(make_pair(v, w));
    }

    for (int i = 1; i <= V; i++)
    {
        di[i] = INF;
    }

    di[S] = 0;
    find(S);

    for (int i = 1; i <= V; i++)
    {
        if (di[i] == INF)
            cout << "INF" << '\n';
        else
            cout << di[i] << '\n';
    }
}