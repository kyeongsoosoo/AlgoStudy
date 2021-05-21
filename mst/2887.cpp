#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
// vector<pair<int,pair<int,int> > > coord;

// vector<pair<int, pair<int,int> > > E;

struct p{
    int x,y,z,num;
};
bool cmpx(p a, p b){
    return a.x < b.x;
}
bool cmpy(p a, p b){
    return a.y < b.y;
}
bool cmpz(p a, p b){
    return a.z < b.z;
}

p pl[1000000];

struct edge{
    int weight, from, to;
};

bool cmp(edge a, edge b){
    return a.weight < b.weight;
}

vector <edge> ed;

int arr[100005];

int find(int idx){
    if(arr[idx] == idx) return idx;

    return arr[idx] = find(arr[idx]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);

    if ( a == b) return;

    arr[a] = b;
}

bool isDiff(int a,int b){
    a = find(a);
    b = find(b);

    if(a!=b) return true;
    return false;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i=0; i<N; i++){
        int x,y,z;
        cin >> x >> y >> z;
        pl[i].x = x;
        pl[i].y = y;
        pl[i].z = z;
        pl[i].num = i;
    }
    sort(pl,pl+N,cmpx);
    for(int i=0;i < N-1; i++){
        edge temp = {abs(pl[i].x-pl[i+1].x),pl[i].num,pl[i+1].num};
        ed.push_back(temp);
        
    }
    sort(pl,pl+N,cmpy);
    for(int i=0;i < N-1; i++){
        edge temp = {abs(pl[i].y-pl[i+1].y),pl[i].num,pl[i+1].num};
        ed.push_back(temp);
    }
    sort(pl,pl+N,cmpz);
    for(int i=0;i < N-1; i++){
        edge temp = {abs(pl[i].z-pl[i+1].z),pl[i].num,pl[i+1].num};
        ed.push_back(temp);
    }

    sort(ed.begin(), ed.end(),cmp);

    for(int i=0; i<N; i++){
        arr[i] = i;
    }

    int ans = 0;

    for(int i=0; i<ed.size(); i++){
        // cout << ed[i].weight << '\n';
        if(isDiff(ed[i].from, ed[i].to)){
            merge(ed[i].from,ed[i].to);
            ans += ed[i].weight;
            // cout << ed[i].weight << '\n';
        }
    }

    cout << ans;

}