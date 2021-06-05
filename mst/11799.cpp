#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define E_MAX 100001
#define C_MAX 1010

using namespace std;

int n, m;
int Di[C_MAX];
int Route[C_MAX];
int start, goal;
vector<pair<int, int> > Edge[E_MAX];
vector<int> Route_V;

void di(int start)
{
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, start));
    Di[start] = 0;

    while (!pq.empty())
    {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (int i = 0; i < Edge[cur].size(); i++)
        {
            int next = Edge[cur][i].first;
            int n_cost = Edge[cur][i].second + cost;

            // cout << tmp.from << " " << next << " " << n_cost << '\n';

            if (Di[next] > n_cost)
            {
                // cout << tmp.from << " " << next << '\n';
                Route[next] = cur;
                Di[next] = n_cost;
                pq.push(make_pair(-Di[next], next));
            }
        }
    }
    cout << Di[goal] << '\n';
    int tmp = goal;
    while (tmp)
    {
        Route_V.push_back(tmp);
        tmp = Route[tmp];
    }
    cout << Route_V.size() << '\n';
    for (int i = Route_V.size() - 1; i >= 0; i--)
        cout << Route_V[i] << " ";
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        Edge[from].push_back(make_pair(to, cost));
    }

    cin >> start >> goal;

    for (int i = 0; i < C_MAX; i++)
    {
        Di[i] = INT_MAX;
    }

    di(start);
}