#include <iostream>
#include <algorithm>

using namespace std;

int coord[101][101];

int n, m;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;

        if (!coord[from][to])
            coord[from][to] = cost;
        else if (coord[from][to] > cost)
            coord[from][to] = cost;
    }

    for (int via = 1; via <= n; via++)
    {
        for (int from = 1; from <= n; from++)
        {
            if (coord[from][via] == 0)
                continue;
            for (int to = 1; to <= n; to++)
            {
                if (coord[via][to] == 0 || from == to)
                    continue;
                if (coord[from][to] == 0 || coord[from][to] > coord[from][via] + coord[via][to])
                    coord[from][to] = coord[from][via] + coord[via][to];
            }
        }
    }

    for (int from = 1; from <= n; from++)
    {
        for (int to = 1; to <= n; to++)
        {
            cout << coord[from][to] << " ";
        }
        cout << '\n';
    }
}