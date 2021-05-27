#include <iostream>
#include <queue>
#include <algorithm>



using namespace std;

int N,K;
queue<pair<int, int> > coord;
int order[100005];
vector<int> path;

pair<int,int> bfs(int from){
    coord.push(make_pair(from, 0));
    order[from] = from;

    while(!coord.empty()){
        int tmp_p = coord.front().first;
        int tmp_s = coord.front().second;

        if(tmp_p == K) {
            int idx = tmp_p;
            
            while(idx != N){
                path.push_back(idx);
                idx = order[idx];
            }
            path.push_back(N);
            return make_pair(tmp_p,tmp_s);}

        coord.pop();

        if(tmp_p < K && order[tmp_p*2]==-1 && tmp_p<=50000 && tmp_p > 0){
            coord.push(make_pair(tmp_p*2, tmp_s + 1));
            order[tmp_p*2] = tmp_p;
            
        } 
        if(tmp_p >0 && order[tmp_p-1] == -1){
            coord.push(make_pair(tmp_p - 1, tmp_s + 1));
            order[tmp_p - 1] = tmp_p;
            
        }
        if(tmp_p < K && order[tmp_p+1] == -1){
            coord.push(make_pair(tmp_p + 1, tmp_s + 1));
            order[tmp_p + 1] = tmp_p;
        }

   
    }
    return make_pair(-1,-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for(int i=0; i<100005; i++){
        order[i] = -1;
    }

    pair<int,int> ans = bfs(N);
    cout << ans.second << '\n';

    int tmp = ans.first;

    for(int i=path.size()-1; i>=0; i--){
        cout << path[i] << " ";
    }


}