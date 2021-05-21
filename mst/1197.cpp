#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10001

using namespace std;

int V,E;
int arr[MAX];
vector<pair<int, pair<int, int> > > V_Vect;

int find(int idx){
    if(arr[idx] == idx) return idx;

    return arr[idx]  = find(arr[idx]);
}

void merge(int a, int b){
    a= find(a);
    b= find(b);

    if( a == b) return;
    else arr[a] = b;
}

bool isDiff(int a, int b){
    a = find(a);
    b = find(b);

    if ( a == b) return false;
    else return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ans = 0;

    cin >> V >> E;
    for(int i=0; i<E; i++){
        int from,to,cost;
        cin >> from >> to >> cost;

        V_Vect.push_back(make_pair(cost, make_pair(from,to)));
    }

    sort(V_Vect.begin(), V_Vect.end());

    for(int i= 1; i <= V; i++){
        arr[i] = i;
    }

    for (int i=0; i< E; i++){
        if(isDiff(V_Vect[i].second.first,V_Vect[i].second.second)){
            merge(V_Vect[i].second.first, V_Vect[i].second.second);
            ans = ans + V_Vect[i].first;
        }
    }

    cout << ans;


}