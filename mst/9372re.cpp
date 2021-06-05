#include <iostream>

using namespace std;

int T;
int N, M;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N >> M;
        int a, b;
        for (int j = 0; j < M; j++)
        {
            cin >> a >> b;
        }
        cout << N - 1 << '\n';
    }
}