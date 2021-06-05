#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001

using namespace std;
bool Visit[MAX];
char order_set[4] = {'D', 'S', 'L', 'R'};

int T;
int A, B;

void find(int a, int b)
{
    queue<pair<int, string> > q;
    Visit[a] = true;
    q.push(make_pair(a, ""));

    while (!q.empty())
    {
        int cur = q.front().first;
        string s = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int next;
            char order = order_set[i];

            switch (order)
            {
            case 'D':
                next = (cur * 2) % 10000;
                break;
            case 'S':
                next = cur == 0 ? 9999 : cur - 1;
                break;
            case 'L':
                next = (cur % 1000) * 10 + (cur / 1000);
                break;
            case 'R':
                next = (cur / 10) + (cur % 10) * 1000;
                break;
            default:
                break;
            }

            if (Visit[next])
                continue;
            Visit[next] = true;
            q.push(make_pair(next, s + order));

            if (next == B)
            {
                cout << s + order;
                cout << '\n';
                return;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            Visit[j] = false;
        }
        cin >> A >> B;
        find(A, B);
    }
}