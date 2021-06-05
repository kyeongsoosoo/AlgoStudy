#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int N, M;
int map[11][11];
int visit[11][11];
int island_n = 0;
int island[7][4];
int parent[7];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool island_visit[7];
vector<pair<int, pair<int, int> > > vec;
vector<int> graph[7];
queue<int> q;

int ans = 0;

int find(int idx)
{
    if (parent[idx] == idx)
        return idx;
    else
        return parent[idx] = find(parent[idx]);
}

bool merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        parent[a] = b;

        graph[a].push_back(b);
        graph[b].push_back(a);
        return true;
    }
    return false;
}

void DFS(int x, int y)
{
    if (visit[x][y])
        return;

    visit[x][y] = true;
    map[x][y] = island_n;

    island[island_n][0] = min(island[island_n][0], x);
    island[island_n][1] = max(island[island_n][1], x);
    island[island_n][2] = min(island[island_n][2], y);
    island[island_n][3] = max(island[island_n][3], y);

    for (int i = 0; i < 4; i++)
    {
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= M)
        {
            if (map[next_x][next_y] != 0 && !visit[next_x][next_y])
                DFS(next_x, next_y);
        }
    }
}

void distance(int now, int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int now_x = x;
        int now_y = y;
        int dist = 0;

        while (true)
        {
            now_x += dx[i];
            now_y += dy[i];

            if (now_x < 1 || now_x > N || now_y < 1 || now_y > M)
                break;

            if (map[now_x][now_y] != 0)
            {
                vec.push_back(make_pair(dist, make_pair(now, map[now_x][now_y])));
                break;
            }
            dist++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= 6; i++)
        parent[i] = i;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (map[i][j] != 0)
            {
                if (!visit[i][j])
                {
                    island_n++;
                }
                DFS(i, j);
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            if (map[i][j] != 0)
            {
                distance(map[i][j], i, j);
            }
        }
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < vec.size(); i++)
    {
        int dist = vec[i].first;
        int island_1 = vec[i].second.first;
        int island_2 = vec[i].second.second;

        if (dist < 2)
            continue;
        if (merge(island_1, island_2))
            ans += dist;
    }
    int cnt = 1;
    q.push(1);

    while (!q.empty())
    {
        int now_island = q.front();
        q.pop();
        island_visit[now_island] = true;

        for (int i = 0; i < graph[now_island].size(); i++)
        {
            int next_island = graph[now_island][i];
            if (!island_visit[next_island])
            {
                q.push(next_island);
                cnt++;
            }
        }
    }
    if (cnt != island_n)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}