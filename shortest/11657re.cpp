#include <iostream>
#include <vector>

#define MAX 510
#define INF 987654321

using namespace std;

int N, M;
long long Dist[MAX];
vector<pair<pair<int, int>, int> > Edge;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        Edge.push_back(make_pair(make_pair(from, to), cost));
    }

    for (int i = 1; i <= N; i++)
    {
        Dist[i] = INF;
    }

    Dist[1] = 0;

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < Edge.size(); j++)
        {
            int from = Edge[j].first.first;
            int to = Edge[j].first.second;
            int cost = Edge[j].second;

            if (Dist[from] == INF)
                continue;
            if (Dist[to] > Dist[from] + cost)
                Dist[to] = Dist[from] + cost;
        }
    }

    for (int j = 0; j < Edge.size(); j++)
    {
        int from = Edge[j].first.first;
        int to = Edge[j].first.second;
        int cost = Edge[j].second;

        if (Dist[from] == INF)
            continue;
        if (Dist[to] > Dist[from] + cost)
        {
            cout << -1 << '\n';
            return 0;
        }
    }

    for (int i = 2; i <= N; i++)
    {
        if (Dist[i] == INF)
            cout << -1 << '\n';
        else
            cout << Dist[i] << '\n';
    }
}