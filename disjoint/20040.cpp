#include <iostream>
#include <algorithm>
#define MAX 500001

using namespace std;    

int n,m;

int arr[MAX];

int find(int idx){
    if(arr[idx] == idx) 
        return idx;

    return find(arr[idx]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);

    if(a == b) return;

    if(a > b){
        arr[b] = a;
    }
    else{
        arr[b] = a;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int from,to;
    bool isCycle = false;
    int turn;

    for(int i=0; i<n; i++){
        arr[i] = i;
    }

    for(int i=0; i<m; i++){
        cin >> from >> to;
        from = find(from);
        to = find(to);

        if(from == to){
            isCycle = true;
            turn = i+1;
            break;
        }
        else{
            merge(from, to);
        }
    }
    if(isCycle){
        cout << turn;
    }
    else {
        cout << "0";
    }

    
}