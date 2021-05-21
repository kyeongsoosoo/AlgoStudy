#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<double,double> > coord;
vector<pair<double, pair<int,int> > >graph;
int arr[120];

double find_distance(double x, double y, double x2, double y2){
    double dx = (x-x2) * (x-x2);
    double dy = (y -y2) * (y-y2);
    double dist = sqrt(dx + dy);

    return dist;
}

int find(int idx){
    if(arr[idx] == idx) return idx;

    return arr[idx] = find(arr[idx]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;
    else{
        arr[a] = b;
    }
}

bool isDiff(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin >> n;

    double c_x, c_y;
    for(int i=0; i<n; i++){
        cin >> c_x >> c_y;
        coord.push_back(make_pair(c_x,c_y));
        arr[i] = i;
    }

    for(int i=0; i<coord.size(); i++){
        for(int j=i+1; j<coord.size(); j++){
            double dist = find_distance(coord[i].first,coord[i].second, coord[j].first,coord[j].second);
            graph.push_back(make_pair(dist, make_pair(i,j)));
        }
    }
    sort(graph.begin(), graph.end());

    double ans = 0;
    int node_n = 0;

    for(int i=0; i<graph.size(); i++){
        if(node_n == n-1) break;

        if(isDiff(graph[i].second.first, graph[i].second.second)){
            ans += graph[i].first;
            merge(graph[i].second.first,graph[i].second.second);
            node_n++;
        }
    }
    cout.precision(3);
    cout << ans;


}