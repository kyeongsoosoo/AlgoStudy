#include <iostream>
#include <queue>

using namespace std;

int N,K;
int visited[100001];
int sec[100001];
int point;

queue<int> q;

void bfs(int idx) {
    q.push(idx);
    visited[idx] = 1;
    sec[idx] = 0;

    while(!q.empty()){
        int start = q.front();
        q.pop();

        int c1 = start + 1;
        int c2 = start*2;
        int c3 = start - 1;

        if(start == K) {
            point = start;
        }

        if(c2 < 100001 && !visited[c2]){
                visited[c2] = 1;
                sec[c2] = sec[start] + 1;
                q.push(c2);
            
        }
        if(c1 < 100001 && !visited[c1]){
            visited[c1] = 1;
            sec[c1] = sec[start] + 1;
            q.push(c1);
        }
        if(c3 >=0 && !visited[c3]){
            visited[c3] = 1;
            sec[c3] = sec[start] + 1;
            // cout << sec[c3] << " " << c3 << '\n';
            q.push(c3);
        }

            
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    bfs(N);

    int ans = sec[point]== 0 ? 0 : sec[point];

    cout << ans;
}