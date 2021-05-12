#include <iostream>

using namespace std;

int N, M;
int arr[101][101];
int check[101];

int cnt = 0;

void dfs(int idx) {
    cnt++;
    check[idx] = 1;

    for(int i=1; i<=N; i++){
        if(arr[idx][i] && !check[i]){
            dfs(i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;

    int start, to;

    for(int i=0; i<M; i++){
        cin >> start >> to;
        arr[start][to] = 1;
        arr[to][start] = 1;
    }

    dfs(1);

    cout << cnt-1;


}